LOCAL_PATH := $(call my-dir)

####### misc #######
# mtkc
include $(CLEAR_VARS)
LOCAL_SRC_FILES := misc/libc.cpp
LOCAL_MODULE := mtkc
LOCAL_SHARED_LIBRARIES := libc libutilscallstack
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

####### bionic #######
## libshim_mutexdestroy
include $(CLEAR_VARS)
LOCAL_SRC_FILES := bionic/pthread_mutex_destroy.cpp
LOCAL_MODULE := libshim_mutexdestroy
LOCAL_SHARED_LIBRARIES := libc
LOCAL_CXX_STL := none
LOCAL_SANITIZE := never
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
LOCAL_PROPRIETARY_MODULE := true
#LOCAL_32_BIT_ONLY := true
include $(BUILD_SHARED_LIBRARY)
