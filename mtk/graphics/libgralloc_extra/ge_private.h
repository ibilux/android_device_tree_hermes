#ifndef __GE_PRIVATE_H__
#define __GE_PRIVATE_H__

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

#include <linux/ion_drv.h>
#include <linux/mtk_ion.h>
#include <ion.h>
#include <ion/ion.h>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif

#ifndef OFFSETOF
#define OFFSETOF(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)
#endif

#define UNUSED(x) UNUSED_ ## x __attribute__((unused))

typedef uint32_t ge_sec_hnd_t;

typedef struct {
	uint64_t _64hnd;
	GEHND ge_hnd;
	ion_user_handle_t ion_hnd;
	ge_sec_hnd_t sec_hnd;
} ge_sec_hwc_t;

__END_DECLS

#endif
