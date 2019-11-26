#ifndef __GE_H__
#define __GE_H__

#include "gralloc_extra.h"

__BEGIN_DECLS

typedef uint32_t GEHND;

GEHND ge_alloc(buffer_handle_t hnd);
int ge_retain(buffer_handle_t hnd, GEHND ge_hnd);
int ge_release(buffer_handle_t hnd, GEHND ge_hnd);

int ge_query(buffer_handle_t hnd, GEHND ge_hnd, GRALLOC_EXTRA_ATTRIBUTE_QUERY attr, void *out);
int ge_perform(buffer_handle_t hnd, GEHND ge_hnd, GRALLOC_EXTRA_ATTRIBUTE_PERFORM attr, void *in);

__END_DECLS

#endif
