DEVICE_PATH := device/xiaomi/hermes

TARGET_PREBUILT_KERNEL := $(DEVICE_PATH)/kernel
BOARD_CUSTOM_BOOTIMG_MK := $(DEVICE_PATH)/bootimg/bootimg.mk
TARGET_PREBUILT_RECOVERY_KERNEL := $(DEVICE_PATH)/kernel

ifeq ($(TARGET_PREBUILT_KERNEL),)
    LOCAL_KERNEL := $(DEVICE_PATH)/kernel
else
    LOCAL_KERNEL := $(TARGET_PREBUILT_KERNEL)
endif

# Hack for building without kernel sources
$(shell mkdir -p $(OUT)/obj/KERNEL_OBJ/usr)
$(shell touch $(OUT)/obj/KERNEL_OBJ/usr/export_includes)

PRODUCT_COPY_FILES += \
    $(LOCAL_KERNEL):kernel
