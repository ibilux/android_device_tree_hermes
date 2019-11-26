#ifndef GE_INCLUDE_CONFIG
#error "gralloc_extra_config only can be included by implementation!"
#endif

#ifndef __GE_CONFIG_H__
#define __GE_CONFIG_H__

#define GE_LIST \
	GE_STRUCT(ge_misc_info_t) \
	GE_STRUCT(ge_sf_info_t) \
	GE_STRUCT(ge_sec_hwc_t) \
	GE_STRUCT(ge_hdr_info_t) \

#undef GE_STRUCT
#define GE_STRUCT(x) sizeof(x),

static uint32_t region_sizes[] = { GE_LIST };
static int region_num = ARRAY_SIZE(region_sizes);

#define _GE_ID_PREFIX(x) GE_ID_##x

#undef GE_STRUCT
#define GE_STRUCT(x) _GE_ID_PREFIX(x),
enum { GE_LIST };

/* Used by santiy, it will check the size of struct in 32/64 arch.
 * Report fail, if you use a arch-dep type (ex: void *).
 * Report pass, otherwise.
 */
#undef GE_STRUCT
#define GE_STRUCT(x) sizeof(x) +
const int _ge_check_size = GE_LIST + 0;

#define OFFSETOF32(TYPE, MEMBER) (OFFSETOF(TYPE, MEMBER)/sizeof(uint32_t))
#define SIZEOF32(TYPE) (sizeof(TYPE)/sizeof(uint32_t))

typedef struct {
	int id;
	int offset;
	int size;
} ge_info;

#define GEI_BY_STRUCT(x) (ge_info){(int)_GE_ID_PREFIX(x), 0, SIZEOF32(x)}
#define GEI_BY_MEMBER(x, m) (ge_info){(int)_GE_ID_PREFIX(x), OFFSETOF32(x, m), SIZEOF32(((x*)0)->m)}

#endif
