### product default property overrides ###
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    persist.sys.timezone=Europe/Moscow \
    ro.allow.mock.location=0 \
    ro.zygote=zygote64_32 \
    ro.dalvik.vm.native.bridge=0 \
    persist.sys.usb.config=mtp \
    persist.debug.xlog.enable=0

# Display
PRODUCT_PROPERTY_OVERRIDES += debug.hwui.use_buffer_age=false

# AudioFlinger
PRODUCT_PROPERTY_OVERRIDES += ro.af.client_heap_size_kbyte=7168

# This should turn off specific memory-intensive features that work poorly on low-memory devices
PRODUCT_PROPERTY_OVERRIDES += ro.config.low_ram=true

### product property overrides ###

# Enable call recording
PRODUCT_PROPERTY_OVERRIDES += \
    persist.call_recording.enabled=true \
    persist.call_recording.src=4

# Storage
PRODUCT_PROPERTY_OVERRIDES += ro.sys.sdcardfs=false

# ADB
ifneq ($(TARGET_BUILD_VARIANT),user)
PRODUCT_PROPERTY_OVERRIDES += persist.sys.usb.config=adb
endif
