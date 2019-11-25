# Storage
PRODUCT_PROPERTY_OVERRIDES += ro.sys.sdcardfs=false

# ADB
ifneq ($(TARGET_BUILD_VARIANT),user)
PRODUCT_PROPERTY_OVERRIDES += persist.sys.usb.config=adb
endif

# Timezone
PRODUCT_DEFAULT_PROPERTY_OVERRIDES := \
     persist.sys.timezone=Europe/Moscow

# Enable call recording
PRODUCT_PROPERTY_OVERRIDES += \
    persist.call_recording.enabled=true \
    persist.call_recording.src=4
