LOCAL_PATH := $(call my-dir)
ifneq ($(filter hermes,$(TARGET_DEVICE)),)
include $(call all-makefiles-under,$(LOCAL_PATH))
include $(CLEAR_VARS)
endif
