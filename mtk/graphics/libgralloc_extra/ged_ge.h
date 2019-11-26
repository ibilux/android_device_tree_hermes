#ifndef __GED_GE_H__
#define __GED_GE_H__

#if defined (__cplusplus)
extern "C" {
#endif

/*typedef uint32_t GEHND;*/
/* declared at ui/ge.h */

GEHND ged_ge_alloc(int region_num, uint32_t *region_sizes);

/* return old_ref_count,
 * something wrong if ret_val <= 0
 */
int ged_ge_retain(GEHND ge_hnd);

/* return old_ref_count,
 * something wrong if ret_val <= 0
 * hnd will be invalid if ret_val == 1
 */
int ged_ge_release(GEHND ge_hnd);

/* ok if ret_val == 0 */
int ged_ge_get(GEHND ge_hnd, int region_id, int u32_offset, int u32_size, uint32_t *output_data);

/* ok if ret_val == 0 */
int ged_ge_set(GEHND ge_hnd, int region_id, int u32_offset, int u32_size, uint32_t *input_data);

#if defined (__cplusplus)
}
#endif

#endif
