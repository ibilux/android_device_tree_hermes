LOCAL_PATH := $(call my-dir)
ifneq ($(filter $(TARGET_DEVICE),hermes),)
include $(call all-makefiles-under,$(LOCAL_PATH))
include $(CLEAR_VARS)
endif
