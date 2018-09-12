LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := custom.cpp
LOCAL_C_INCLUDES := packages/apps/FMRadio/jni/fmr
LOCAL_SHARED_LIBRARIES := libcutils
LOCAL_MODULE := libfmcust
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
include $(BUILD_SHARED_LIBRARY)
