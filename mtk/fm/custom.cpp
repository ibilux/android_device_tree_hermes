#include <sys/types.h>
#include <string.h>
#include <cutils/properties.h>
#include <utils/Log.h>

#include "fmr.h"

#ifdef __cplusplus
extern "C" {
#endif

static struct fm_fake_channel fake_ch[] = {{960, -107, -1}, {1040, -107, -1}};
static struct fm_fake_channel_t fake_ch_info = {0, 0};

int CUST_get_cfg(struct CUST_cfg_ds *cfg) {
    char val[PROPERTY_VALUE_MAX] = {0};
    cfg->chip = 0x6630;
    cfg->band = FM_RAIDO_BAND;
    cfg->low_band = FM_FREQ_MIN;
    cfg->high_band = FM_FREQ_MAX;
    cfg->seek_space = 1;
    cfg->max_scan_num = 80;
    cfg->seek_lev = FM_SEEKTH_LEVEL_DEFAULT;
    cfg->scan_sort = FM_SCAN_SORT_SELECT;
    cfg->short_ana_sup = false;
    cfg->rssi_th_l2 = FM_CHIP_DESE_RSSI_TH;
    cfg->rssi_th_l2 = (cfg->rssi_th_l2 > -72) ? -72 : cfg->rssi_th_l2;
    cfg->rssi_th_l2 = (cfg->rssi_th_l2 < -102) ? -102 : cfg->rssi_th_l2;
    fake_ch_info.chan = fake_ch;
    fake_ch_info.size = sizeof(fake_ch) / sizeof(fake_ch[0]);
    cfg->fake_chan = &fake_ch_info;
    return 0;
}

#ifdef __cplusplus
}
#endif
