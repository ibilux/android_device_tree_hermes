#include <stdlib.h>

#define LOG_TAG "GE"
#include <cutils/log.h>

#include <ui/ge.h>

#include "ge_private.h"
#include "ged_ge.h"

#define GE_INCLUDE_CONFIG
#include "ge_config.h"

static int _ge_get(GEHND ge_hnd, ge_info *gei, void *out)
{
	return ged_ge_get(ge_hnd, gei->id, gei->offset, gei->size, out);
}
static int _ge_set(GEHND ge_hnd, ge_info *gei, void *in)
{
	return ged_ge_set(ge_hnd, gei->id, gei->offset, gei->size, in);
}

static int _ge_ion_get_phys(int ion_client, ion_user_handle_t ion_hnd, ge_sec_hnd_t *pphys)
{
	int ret;
	ion_sys_data_t sys_data;

	sys_data.sys_cmd = ION_SYS_GET_PHYS;
	sys_data.get_phys_param.handle = ion_hnd;

	ret = ion_custom_ioctl(ion_client, ION_CMD_SYSTEM, &sys_data);
	if (ret)
	{
		ALOGE("IOCTL[ION_IOC_CUSTOM] Get Phys failed!\n");
		return 1;
	}

#ifdef DEBUG
	ALOGI("[ge_ion_get_phys] phy_addr = 0x%x, len = %d, pphys(0x%x)\n", sys_data.get_phys_param.phy_addr, sys_data.get_phys_param.len,pphys);
#endif

	if (!ret && pphys) {
		*pphys = sys_data.get_phys_param.phy_addr;
	}

	return ret;
}

static int _ge_alloc_sec_hwc(int ion_client, size_t size, int usage, ion_user_handle_t* pion_hnd)
{
	int ret;
	ion_user_handle_t ion_hnd;
	unsigned int heap_mask = ION_HEAP_MULTIMEDIA_SEC_MASK;
	int ion_flags = 0;

	if ( (usage & GRALLOC_USAGE_SW_READ_MASK) == GRALLOC_USAGE_SW_READ_OFTEN )
	{
		ion_flags = ION_FLAG_CACHED | ION_FLAG_CACHED_NEEDS_SYNC;
	}

	ret = ion_alloc(ion_client, size, 0, heap_mask, ion_flags, &ion_hnd);

	if ( !ret && pion_hnd) *pion_hnd = ion_hnd;
	return ret;
}

static int _ge_free_sec_hwc(int ion_client, ion_user_handle_t ion_hnd)
{
	return ion_free(ion_client, ion_hnd);
}

#define MM_DBG_NAME_LEN (sizeof(((gralloc_extra_ion_debug_t *)0)->name)/sizeof(char))

static int _ge_get_ion_debug(int ion_client, ion_user_handle_t ion_hnd, ge_ion_debug_t *pdebug_info)
{
	struct ion_mm_data mm_data;

	mm_data.mm_cmd = ION_MM_GET_DEBUG_INFO;
	mm_data.buf_debug_info_param.handle = ion_hnd;

	if (ion_custom_ioctl(ion_client, ION_CMD_MULTIMEDIA, &mm_data))
	{
		ALOGE("ion_custom_ioctl fail, hnd = 0x%x", ion_hnd);
		return 1;
	}

	pdebug_info->data[0] = mm_data.buf_debug_info_param.value1;
	pdebug_info->data[1] = mm_data.buf_debug_info_param.value2;
	pdebug_info->data[2] = mm_data.buf_debug_info_param.value3;
	pdebug_info->data[3] = mm_data.buf_debug_info_param.value4;

	strncpy(pdebug_info->name, mm_data.buf_debug_info_param.dbg_name, MM_DBG_NAME_LEN);

	return 0;
}

static int _ge_set_ion_debug(int ion_client, ion_user_handle_t ion_hnd, gralloc_extra_ion_debug_t *pdebug_info)
{
	struct ion_mm_data mm_data;

	mm_data.mm_cmd = ION_MM_SET_DEBUG_INFO;
	mm_data.buf_debug_info_param.handle = ion_hnd;

	mm_data.buf_debug_info_param.value1 = pdebug_info->data[0];
	mm_data.buf_debug_info_param.value2 = pdebug_info->data[1];
	mm_data.buf_debug_info_param.value3 = pdebug_info->data[2];
	mm_data.buf_debug_info_param.value4 = pdebug_info->data[3];

	strncpy(mm_data.buf_debug_info_param.dbg_name, pdebug_info->name, MM_DBG_NAME_LEN);

	if (ion_custom_ioctl(ion_client, ION_CMD_MULTIMEDIA, &mm_data))
	{
		ALOGE("ion_custom_ioctl fail, hnd = 0x%x", ion_hnd);
		return 1;
	}

	return 0;
}

#define err_return(err, msg, ...) do { if (err) { ALOGE(msg, ##__VA_ARGS__); return err; } } while (0)
static int _ge_query_ion_debug(buffer_handle_t hnd, GEHND UNUSED(ge_hnd), void *out)
{
	int err;
	int ion_client;
	ion_user_handle_t ion_hnd;

	err = gralloc_extra_query(hnd, GRALLOC_EXTRA_GET_ION_CLIENT, &ion_client);
	err_return(err, "get ion_client fail");
	err = gralloc_extra_query(hnd, GRALLOC_EXTRA_GET_ION_HANDLE, &ion_hnd);
	err_return(err, "get ion_hnd fail");

	if (!err) err = _ge_get_ion_debug(ion_client, ion_hnd, out);

	return err;
}
static int _ge_perform_ion_debug(buffer_handle_t hnd, GEHND UNUSED(ge_hnd), void *in)
{
	int err;
	int ion_client;
	ion_user_handle_t ion_hnd;

	err = gralloc_extra_query(hnd, GRALLOC_EXTRA_GET_ION_CLIENT, &ion_client);
	err_return(err, "get ion_client fail");
	err = gralloc_extra_query(hnd, GRALLOC_EXTRA_GET_ION_HANDLE, &ion_hnd);
	err_return(err, "get ion_hnd fail");

	if (!err) err = _ge_set_ion_debug(ion_client, ion_hnd, in);

	return err;
}

static int _ge_perform_alloc_sec_hwc(buffer_handle_t hnd, GEHND ge_hnd, void *UNUSED(in))
{
	int err;
	ge_sec_hwc_t sechwc;
	ge_info gei = GEI_BY_STRUCT(ge_sec_hwc_t);

	_ge_get(ge_hnd, &gei, &sechwc);

	if (sechwc.sec_hnd == 0)
	{
		int ion_client, size, usage;

		err = gralloc_extra_query(hnd, GRALLOC_EXTRA_GET_ION_CLIENT, &ion_client);
		err_return(err, "get ion_client fail");
		err = gralloc_extra_query(hnd, GRALLOC_EXTRA_GET_ALLOC_SIZE, &size);
		err = gralloc_extra_query(hnd, GRALLOC_EXTRA_GET_USAGE, &usage);

		err = _ge_alloc_sec_hwc(ion_client, size, usage, &sechwc.ion_hnd);

		if (!err)
		{
			_ge_ion_get_phys(ion_client, sechwc.ion_hnd, &sechwc.sec_hnd);
			sechwc.ge_hnd = ge_hnd;
			sechwc._64hnd = (uint64_t)hnd;

			_ge_set(ge_hnd, &gei, &sechwc);
		}

		return err;
	}
	else
	{
		return 1;
	}
}
static int _ge_perform_free_sec_hwc(buffer_handle_t hnd, GEHND ge_hnd, void *UNUSED(in))
{
	int ion_client, size, usage;
	ge_sec_hwc_t sechwc;
	ge_info gei = GEI_BY_STRUCT(ge_sec_hwc_t);

	_ge_get(ge_hnd, &gei, &sechwc);

	if (sechwc.sec_hnd != 0 && sechwc._64hnd == (uint64_t)hnd)
	{
		int err = 0;
		int ion_client;

		err = gralloc_extra_query(hnd, GRALLOC_EXTRA_GET_ION_CLIENT, &ion_client);
		err_return(err, "get ion_client fail");

		_ge_free_sec_hwc(ion_client, sechwc.ion_hnd);

		memset(&sechwc, 0, sizeof(ge_sec_hwc_t));
		_ge_set(ge_hnd, &gei, &sechwc);
	}

	return 0;
}

GEHND ge_alloc(buffer_handle_t UNUSED(hnd))
{
	return ged_ge_alloc(region_num, region_sizes);
}

int ge_retain(buffer_handle_t UNUSED(hnd), GEHND ge_hnd)
{
	return ged_ge_retain(ge_hnd);
}

int ge_release(buffer_handle_t hnd, GEHND ge_hnd)
{
	_ge_perform_free_sec_hwc(hnd, ge_hnd, NULL);

	return ged_ge_release(ge_hnd);
}

#define MAKE_GENERAL_CASE(attr, ge_struct) \
	case GE_PREFIX(attr): { \
		ge_info gei = GEI_BY_STRUCT(ge_struct); \
		return GE_GETSET_FUNC(ge_hnd, &gei, GE_INOUT); \
	}
#define MAKE_GENERAL_CASE2(attr, ge_struct, member) \
	case GE_PREFIX(attr): { \
		ge_info gei = GEI_BY_MEMBER(ge_struct, member); \
		return GE_GETSET_FUNC(ge_hnd, &gei, GE_INOUT); \
	}

#undef GE_PREFIX
#define GE_PREFIX(x) GRALLOC_EXTRA_GET_##x
#undef GE_GETSET_FUNC
#define GE_GETSET_FUNC _ge_get
#undef GE_INOUT
#define GE_INOUT out
int ge_query(buffer_handle_t hnd, GEHND ge_hnd, GRALLOC_EXTRA_ATTRIBUTE_QUERY attr, void *out)
{
	switch (attr)
	{
	MAKE_GENERAL_CASE(SF_INFO, ge_sf_info_t);

	MAKE_GENERAL_CASE2(SECURE_HANDLE_HWC, ge_sec_hwc_t, sec_hnd);

	MAKE_GENERAL_CASE(HDR_INFO, ge_hdr_info_t);

	case GRALLOC_EXTRA_GET_IOCTL_ION_DEBUG: return _ge_query_ion_debug(hnd, ge_hnd, out);

	MAKE_GENERAL_CASE2(ORIENTATION, ge_misc_info_t, orientation)

	default:
		ALOGE("unkown attr %x", attr);
		/* abort to expose problem earlier */
		abort();
		return 1;
	}

	return 0;
}

#undef GE_PREFIX
#define GE_PREFIX(x) GRALLOC_EXTRA_SET_##x
#undef GE_GETSET_FUNC
#define GE_GETSET_FUNC _ge_set
#undef GE_INOUT
#define GE_INOUT in
int ge_perform(buffer_handle_t hnd, GEHND ge_hnd, GRALLOC_EXTRA_ATTRIBUTE_PERFORM attr, void *in)
{
	switch (attr)
	{
	MAKE_GENERAL_CASE(SF_INFO, ge_sf_info_t);

	MAKE_GENERAL_CASE(HDR_INFO, ge_hdr_info_t);

	case GRALLOC_EXTRA_SET_IOCTL_ION_DEBUG: return _ge_perform_ion_debug(hnd, ge_hnd, in);

	case GRALLOC_EXTRA_ALLOC_SECURE_BUFFER_HWC: return _ge_perform_alloc_sec_hwc(hnd, ge_hnd, in);

	case GRALLOC_EXTRA_FREE_SECURE_BUFFER_HWC: return _ge_perform_free_sec_hwc(hnd, ge_hnd, in);

	MAKE_GENERAL_CASE2(ORIENTATION, ge_misc_info_t, orientation);

	default:
		ALOGE("unkown attr %x", attr);
		/* abort to expose problem earlier */
		abort();
		return 1;
	}

	return 0;
}
