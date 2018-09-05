/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#include <sys/types.h>
#include <string.h>
#include <cutils/properties.h>
#include <utils/Log.h>

#include "fm.h"
#include "fmlib_cust.h"

#undef LOGV
#define LOGV(...) ALOGV(__VA_ARGS__) 
#undef LOGD
#define LOGD(...) ALOGD(__VA_ARGS__) 
#undef LOGI
#define LOGI(...) ALOGI(__VA_ARGS__) 
#undef LOGW
#define LOGW(...) ALOGW(__VA_ARGS__) 
#undef LOGE
#define LOGE(...) ALOGE(__VA_ARGS__) 
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "FMLIB_CUST"


#ifdef __cplusplus
extern "C" {
#endif

#ifdef MTK_FM_50KHZ_SUPPORT
#define MT6630_FM_FAKE_CHANNEL \
{ \
    {9600,-107,-1},\
    {10400,-107,-1}\
}
#else
#define MT6630_FM_FAKE_CHANNEL \
{ \
    {960,-107,-1},\
    {1040,-107,-1}\
}
#endif //MTK_FM_50KHZ_SUPPORT

static struct fm_fake_channel fake_ch[] = MT6630_FM_FAKE_CHANNEL;

static struct fm_fake_channel_t fake_ch_info = {0, 0};

int CUST_get_cfg(struct CUST_cfg_ds *cfg)
{
	char val[PROPERTY_VALUE_MAX] = {0};//[10];
	cfg->chip = FM_CHIP_MT6630;
	cfg->band = FM_RAIDO_BAND; // 1, UE; 2, JAPAN; 3, JAPANW
#ifdef MTK_FM_50KHZ_SUPPORT
	cfg->low_band = FM_FREQ_MIN * 10;
	cfg->high_band = FM_FREQ_MAX * 10;
#else
	cfg->low_band = FM_FREQ_MIN;
	cfg->high_band = FM_FREQ_MAX;
#endif
#ifdef MTK_FM_50KHZ_SUPPORT
	cfg->seek_space = 5;	//FM radio seek space,5:50KHZ; 1:100KHZ; 2:200KHZ
#else
	cfg->seek_space = 1;
#endif
	
	cfg->max_scan_num = FM_MAX_CHL_SIZE;
	cfg->seek_lev = FM_SEEKTH_LEVEL_DEFAULT;
	
	cfg->scan_sort = FM_SCAN_SORT_SELECT;

#ifndef MTK_FM_SHORT_ANTENNA_SUPPORT
	cfg->short_ana_sup = false;
#else
	cfg->short_ana_sup = true;
#endif

	cfg->rssi_th_l2 = FM_CHIP_DESE_RSSI_TH;
	cfg->rssi_th_l2 = (cfg->rssi_th_l2 > -72) ? -72 : cfg->rssi_th_l2;
	cfg->rssi_th_l2 = (cfg->rssi_th_l2 < -102) ? -102 : cfg->rssi_th_l2;
    
	fake_ch_info.chan = fake_ch;
	fake_ch_info.size = sizeof(fake_ch)/sizeof(fake_ch[0]);
	cfg->fake_chan = &fake_ch_info;
	return 0;
}

#ifdef __cplusplus
}
#endif
