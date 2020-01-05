# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.

# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.     
#
# The following software/firmware and/or related documentation ("MediaTek Software")
# have been modified by MediaTek Inc. All revisions are subject to any receiver's
# applicable license agreements with MediaTek Inc.


# Copyright 2005 The Android Open Source Project

###############################################################################
# Configuration
###############################################################################
#MTK_GPS_CHIP = MTK_GPS_MT6582
###############################################################################
# build start
###############################################################################
ifeq ($(MTK_GPS_SUPPORT), yes)
LOCAL_PATH := $(call my-dir)
MY_LOCAL_PATH := $(LOCAL_PATH)
include $(MY_LOCAL_PATH)/libs/Android.mk
#define my_libmnlp
$(warning feature_option=$(MTK_GPS_CHIP))
MNL_SRC_FILES := \
          src/mtk_gps.c \
          src/mnl_common.c \
          src/mnld_uti.c \
          src/mnld.c \
          src/mnl2agps_interface.c \
          src/mnl_agps_interface.c \
          src/data_coder.c
          
include $(CLEAR_VARS)
LOCAL_PATH := $(MY_LOCAL_PATH)
LOCAL_SRC_FILES := \
         $(MNL_SRC_FILES)
         
LOCAL_C_INCLUDES:= $(LOCAL_PATH)/inc \
				   $(LOCAL_PATH)/../inc \
				   $(MTK_PATH_SOURCE)/external/nvram/libnvram \

LOCAL_MODULE := mnld
LOCAL_MULTILIB := 32
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR_OPTIONAL_EXECUTABLES)
LOCAL_UNSTRIPPED_PATH := $(TARGET_ROOT_OUT_SBIN_UNSTRIPPED)

ifeq ($(MTK_TC1_FEATURE), yes)
ifeq ($(GPS_CO_CLOCK_DATA_IN_MD), yes)
LOCAL_CFLAGS += -DMTK_GPS_CO_CLOCK_DATA_IN_MD
endif
endif

LOCAL_CFLAGS += -DMT6795
LOCAL_CFLAGS += -Wno-int-conversion
#LOCAL_LDLIBS := -llog

LOCAL_STATIC_LIBRARIES +=  libsupl
LOCAL_SHARED_LIBRARIES +=  libmnl libcutils libc libm libnvram libhardware_legacy liblog
LOCAL_MODULE_TAGS := optional
LOCAL_REQUIRED_MODULES := libmnl.so
include $(BUILD_EXECUTABLE)
#endif
endif
###############################################################################
