LOCAL_PATH := $(call my-dir)

####### misc #######
# mtkc
include $(CLEAR_VARS)
LOCAL_SRC_FILES := misc/libc.cpp
LOCAL_MODULE := mtkc
LOCAL_SHARED_LIBRARIES := libc
LOCAL_CFLAGS := -O3 -Wno-unused-variable -Wno-unused-parameter
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# mtklog
include $(CLEAR_VARS)
LOCAL_SRC_FILES := misc/liblog.c
LOCAL_MODULE := mtklog
LOCAL_SHARED_LIBRARIES := liblog
LOCAL_CFLAGS := -O3 -Wno-unused-variable -Wno-unused-parameter
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

####### ui #######
# mtkui
include $(CLEAR_VARS)
LOCAL_SRC_FILES := ui/libui.cpp
LOCAL_MODULE := mtkui
LOCAL_SHARED_LIBRARIES := libui
LOCAL_CFLAGS := -O3 -Wno-unused-variable -Wno-unused-parameter
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

####### mmsdk #######
## libshim_mmsdk
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	mmsdk/MediaBuffer.cpp \

LOCAL_SHARED_LIBRARIES := \
	libgui \
	libui \
	libstagefright_foundation

LOCAL_MODULE := libshim_mmsdk

LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS := -O3 -Wno-unused-variable -Wno-unused-parameter
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)
