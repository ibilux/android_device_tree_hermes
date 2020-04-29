# Copyright 2017 The Android Open Source Project
#
# Oreo RIL daemon for MTK devices - Version (0.9).
# by: daniel_hk(https://github.com/danielhk)
#
# start with the AOSP rild
#
# 2017/7/29: Initial Oero port for MT6752	- by:daniel_hk
#

ifdef ENABLE_VENDOR_RIL_SERVICE

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE = rild-prop-md1
LOCAL_MODULE_CLASS = STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX = .a
LOCAL_PROPRIETARY_MODULE = true
LOCAL_UNINSTALLABLE_MODULE = true
LOCAL_MULTILIB = 64
LOCAL_SRC_FILES_64 = arm64/rild-prop-md1.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE = rild-prop-md1
LOCAL_MODULE_CLASS = STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX = .a
LOCAL_PROPRIETARY_MODULE = true
LOCAL_UNINSTALLABLE_MODULE = true
LOCAL_MULTILIB = 32
LOCAL_SRC_FILES_32 = arm/rild-prop-md1.a
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    rild.c

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libdl \
    liblog \
    libril

LOCAL_STATIC_LIBRARIES := \
    rild-prop-md1

LOCAL_CFLAGS += -Wno-unused-parameter

ifeq ($(SIM_COUNT), 2)
    LOCAL_CFLAGS += -DANDROID_MULTI_SIM
    LOCAL_CFLAGS += -DANDROID_SIM_COUNT_2
endif

LOCAL_C_INCLUDES += $(DEVICE_PATH)/include/telephony

# Temporary hack for broken vendor RILs
LOCAL_WHOLE_STATIC_LIBRARIES := \
    librilutils_static

LOCAL_CFLAGS := -DRIL_SHLIB

LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE := rild
LOCAL_INIT_RC := rild.rc

include $(BUILD_EXECUTABLE)

endif # ENABLE_VENDOR_RIL_SERVICE
