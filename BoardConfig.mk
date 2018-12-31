LOCAL_PATH := device/xiaomi/hermes

# Platform
TARGET_BOOTLOADER_BOARD_NAME := mt6795
TARGET_BOARD_PLATFORM := mt6795
TARGET_NO_BOOTLOADER := true
TARGET_IS_64_BIT := true

# CPU
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := cortex-a53

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv7-a-neon
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := cortex-a53

# Build old-style zip files (required for ota updater)
BLOCK_BASED_OTA := false

# Kernel
TARGET_PREBUILT_KERNEL := $(LOCAL_PATH)/kernel
BOARD_KERNEL_CMDLINE := bootopt=64S3,32N2,64N2 log_buf_len=8M androidboot.selinux=permissive
BOARD_MKBOOTIMG_ARGS := \
    --base 0x40078000 \
    --board mt6795 \
    --kernel_offset 0x00008000 \
    --pagesize 2048 \
    --ramdisk_offset 0x03f88000 \
    --second_offset 0x00e88000 \
    --tags_offset 0x0df88000

# Partitons make_ext4fs requires numbers
BOARD_USERDATAIMAGE_PARTITION_SIZE := 12737576960
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 134217728
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2147483648
BOARD_CACHEIMAGE_PARTITION_SIZE := 629145600
BOARD_BOOTIMAGE_PARTITION_SIZE := 16777216
BOARD_FLASH_BLOCK_SIZE := 131072
BOARD_HAS_LARGE_FILESYSTEM := true
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4

# EXT4
TARGET_USERIMAGES_USE_EXT4 := true
#TARGET_USERIMAGES_USE_F2FS := true

# Hardware
BOARD_USES_MTK_HARDWARE := true

# Display
BOARD_EGL_CFG := $(LOCAL_PATH)/configs/egl.cfg
TARGET_FORCE_HWC_FOR_VIRTUAL_DISPLAYS := true
MAX_VIRTUAL_DISPLAY_DIMENSION := 1

# Audio
USE_XML_AUDIO_POLICY_CONF := 1

# Charger
BOARD_CHARGER_ENABLE_SUSPEND := true
YELLOW_LED_PATH := /sys/class/leds/yellow/brightness

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(LOCAL_PATH)/bluetooth

# RIL
BOARD_PROVIDES_RILD := true
BOARD_RIL_CLASS := ../../../$(LOCAL_PATH)/mtk/ril

# LightHAL
TARGET_PROVIDES_LIBLIGHT := true

# LineageHW
BOARD_USES_LINEAGE_HARDWARE := true
BOARD_HARDWARE_CLASS := $(DEVICE_PATH)/lineagehw

# Camera
TARGET_SPECIFIC_CAMERA_PARAMETER_LIBRARY := libcamera_parameters_mtk
TARGET_CAMERASERVICE_CLOSES_NATIVE_HANDLES := true
TARGET_NEEDS_PLATFORM_TEXT_RELOCATIONS := true
TARGET_HAS_LEGACY_CAMERA_HAL1 := true

# Low-ram
MALLOC_SVELTE := true

# Include
TARGET_SPECIFIC_HEADER_PATH := $(LOCAL_PATH)/include

# Device specific props
TARGET_SYSTEM_PROP := $(LOCAL_PATH)/system.prop

# Wi-Fi
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_mt66xx
BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_mt66xx
WIFI_DRIVER_FW_PATH_PARAM := "/dev/wmtWifi"
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
WPA_SUPPLICANT_VERSION := VER_0_8_X
BOARD_HOSTAPD_DRIVER := NL80211
WIFI_DRIVER_FW_PATH_STA := STA
WIFI_DRIVER_FW_PATH_P2P := P2P
WIFI_DRIVER_FW_PATH_AP := AP

# Recovery
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/rootdir/recovery.fstab
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_15x24.h\"
TARGET_RECOVERY_PIXEL_FORMAT := "RGBA_8888"
BOARD_HAS_NO_SELECT_BUTTON := true
BOARD_SUPPRESS_EMMC_WIPE := true
BOARD_RECOVERY_SWIPE := true

# Seccomp
TARGET_DOES_NOT_SUPPORT_SECCOMP := true

# Sepolicy
BOARD_SEPOLICY_DIRS += device/xiaomi/hermes/sepolicy
BOARD_SEPOLICY_VERS := 28.0

# Build kernel without kernel sources
$(shell mkdir -p $(OUT)/obj/KERNEL_OBJ/usr)

#
# Oreo board
#

# Disable dex pre-opt
WITH_DEXPREOPT := false

# GC tweak
PRODUCT_TAGS += dalvik.gc.type-precise

# SW Gatekeeper
BOARD_USE_SOFT_GATEKEEPER := true

# Camera flags
TARGET_USES_NON_TREBLE_CAMERA := true

# suppress MTK audio blob error message flag
SUPPRESS_MTK_AUDIO_BLOB_ERR_MSG := true

# MTK av blob flag
LEGACY_MTK_AV_BLOB := true

# Google codecs
PRODUCT_COPY_FILES += \
    frameworks/av/media/libstagefright/data/media_codecs_google_audio.xml:vendor/etc/media_codecs_google_audio.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_telephony.xml:vendor/etc/media_codecs_google_telephony.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video_le.xml:vendor/etc/media_codecs_google_video_le.xml

# Audio
PRODUCT_COPY_FILES += $(LOCAL_PATH)/configs/audio/audio_effects.xml:system/etc/audio_effects.xml

# GPS
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/gps/slp_conf:vendor/etc/slp_conf \
    $(LOCAL_PATH)/configs/gps/gps.conf:vendor/etc/gps.conf \
    $(LOCAL_PATH)/configs/gps/agps_profiles_conf2.xml:vendor/etc/agps_profiles_conf2.xml

# Bluetooth
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/bluetooth/auto_pair_devlist.conf:vendor/etc/bluetooth/auto_pair_devlist.conf \
    $(LOCAL_PATH)/configs/bluetooth/bt_stack.conf.debug:vendor/etc/bluetooth/bt_stack.conf.debug \
    $(LOCAL_PATH)/configs/bluetooth/bt_did.conf:vendor/etc/bluetooth/bt_did.conf \
    $(LOCAL_PATH)/configs/bluetooth/bt_stack.conf:vendor/etc/bluetooth/bt_stack.conf \
    $(LOCAL_PATH)/configs/bluetooth/bt_stack.conf.sqc:vendor/etc/bluetooth/bt_stack.conf.sqc

# Telephony
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/telephony/ecc_list.xml:system/etc/ecc_list.xml \
    $(LOCAL_PATH)/configs/telephony/spn-conf.xml:system/etc/spn-conf.xml

# Wifi
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/wifi/p2p_supplicant_overlay.conf:vendor/etc/wifi/p2p_supplicant_overlay.conf \
    $(LOCAL_PATH)/configs/wifi/wpa_supplicant.conf:vendor/etc/wifi/wpa_supplicant.conf \
    $(LOCAL_PATH)/configs/wifi/wpa_supplicant_overlay.conf:vendor/etc/wifi/wpa_supplicant_overlay.conf

# Seccomp policy
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/seccomp_policy/mediacodec.policy:system/vendor/etc/seccomp_policy/mediacodec.policy \
    $(LOCAL_PATH)/seccomp_policy/mediaextractor.policy:system/vendor/etc/seccomp_policy/mediaextractor.policy

# HIDL Manifest
DEVICE_MANIFEST_FILE := $(LOCAL_PATH)/configs/manifest.xml

# Libshim flags (we will just export shims to init.mt6795.rc for now)
    #LIBSHIM_XLOG_SYMBOLS :=true
    #LIBSHIM_SND_SYMBOLS := true
    #LIBSHIM_UI_SYMBOLS := true
    #LIBSHIM_GUI_SYMBOLS := true
    #LIBSHIM_OMX_SYMBOLS := true
    #LIBSHIM_BIONIC_SYMBOLS := true
    #LIBSHIM_AGPS_SYMBOLS := true
    #LIBSHIM_ATOMIC_SYMBOLS := true
    #LIBSHIM_NETUTILS_SYMBOLS := true

# Treble
#PRODUCT_SHIPPING_API_LEVEL := 21
