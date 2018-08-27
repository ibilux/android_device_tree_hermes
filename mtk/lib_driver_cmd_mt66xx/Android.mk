LOCAL_PATH := $(call my-dir)

ifeq ($(WPA_SUPPLICANT_VERSION),VER_0_8_X)

ifneq ($(BOARD_WPA_SUPPLICANT_DRIVER),)
CONFIG_DRIVER_$(BOARD_WPA_SUPPLICANT_DRIVER) := y
endif

ifneq ($(BOARD_HOSTAPD_DRIVER),)
CONFIG_DRIVER_$(BOARD_HOSTAPD_DRIVER) := y
endif

WPA_SUPPL_DIR = external/wpa_supplicant_8
include $(WPA_SUPPL_DIR)/wpa_supplicant/android.config

WPA_SUPPL_DIR_INCLUDE = \
	$(WPA_SUPPL_DIR)/src \
	$(WPA_SUPPL_DIR)/src/common \
	$(WPA_SUPPL_DIR)/src/drivers \
	$(WPA_SUPPL_DIR)/src/l2_packet \
	$(WPA_SUPPL_DIR)/src/utils \
	$(WPA_SUPPL_DIR)/src/wps \
	$(WPA_SUPPL_DIR)/wpa_supplicant \
	external/libnl/include

ifeq ($(TARGET_ARCH),arm)
L_CFLAGS += -mabi=aapcs-linux
endif

ifdef CONFIG_ANDROID_LOG
L_CFLAGS += -DCONFIG_ANDROID_LOG
endif

include $(CLEAR_VARS)
LOCAL_MODULE := lib_driver_cmd_mt66xx
LOCAL_SHARED_LIBRARIES := libc libcutils
LOCAL_CFLAGS := $(L_CFLAGS)

LOCAL_SRC_FILES := lib_driver_cmd_mt66xx.c
LOCAL_C_INCLUDES := \
	$(WPA_SUPPL_DIR)/src \
	$(WPA_SUPPL_DIR)/src/common \
	$(WPA_SUPPL_DIR)/src/drivers \
	$(WPA_SUPPL_DIR)/src/l2_packet \
	$(WPA_SUPPL_DIR)/src/utils \
	$(WPA_SUPPL_DIR)/src/wps \
	$(WPA_SUPPL_DIR)/wpa_supplicant \
	external/libnl/include

include $(BUILD_STATIC_LIBRARY)
endif
