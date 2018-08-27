LOCAL_PATH := $(call my-dir)

# libshim_c
include $(CLEAR_VARS)
LOCAL_SRC_FILES := libc.cpp
LOCAL_SHARED_LIBRARIES := libbinder libc
LOCAL_MODULE := libshim_c
LOCAL_CFLAGS := -Wno-unused-variable -Wno-unused-parameter
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# libshim_media
include $(CLEAR_VARS)
LOCAL_SRC_FILES := libmedia.cpp
LOCAL_SHARED_LIBRARIES := libbinder libmedia
LOCAL_MODULE := libshim_media
LOCAL_CFLAGS := -Wno-unused-variable -Wno-unused-parameter
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# libshim_stagefright
include $(CLEAR_VARS)
LOCAL_SRC_FILES := libstagefright.cpp
LOCAL_SHARED_LIBRARIES := libbinder libstagefright
LOCAL_MODULE := libshim_stagefright
LOCAL_CFLAGS := -Wno-unused-variable -Wno-unused-parameter
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# libshim_xlog
include $(CLEAR_VARS)
LOCAL_SRC_FILES := liblog.c
LOCAL_SHARED_LIBRARIES := libbinder liblog
LOCAL_MODULE := libshim_xlog
LOCAL_CFLAGS := -Wno-unused-variable -Wno-unused-parameter
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)
