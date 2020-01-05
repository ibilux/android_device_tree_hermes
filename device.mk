# Path
DEVICE_PATH := device/xiaomi/hermes

# Vendor
$(call inherit-product, vendor/xiaomi/hermes/hermes-vendor.mk)

# Dalvik/HWUI
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-2048-dalvik-heap.mk)
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-2048-hwui-memory.mk)

# Properties
include $(DEVICE_PATH)/props.mk

# HIDL (HAL Interface Definition Language)
-include $(DEVICE_PATH)/hidl.mk

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
         $(DEVICE_PATH)/overlay \
         $(DEVICE_PATH)/overlay-lineage

# Display
TARGET_SCREEN_HEIGHT := 1920
TARGET_SCREEN_WIDTH := 1080

# Screen density
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxhdpi

# Recovery allowed devices
TARGET_OTA_ASSERT_DEVICE := hermes

# Compile apps
PRODUCT_PACKAGES += Snap

# Shim symbols
PRODUCT_PACKAGES += \
    libshim_bionic \
    libshim_snd \
    libshim_omx \
    libshim_ui \
    libshim_xlog \
    libshim_gui \
    libshim_agps \
    libshim_netutils

# Power HAL
PRODUCT_PACKAGES += power.mt6795

# RIL
PRODUCT_PACKAGES += \
    libccci_util

# Modem controller
PRODUCT_PACKAGES += \
    md_ctrl

# Wifi mtk wpa_supp lib
PRODUCT_PACKAGES += lib_driver_cmd_mt66xx

# Wifi tools
PRODUCT_PACKAGES += \
    libwpa_client \
    hostapd \
    wpa_supplicant \
    wifilogd \
    wificond

# Graphic
PRODUCT_PACKAGES += \
    libGLES_android \
    libgralloc_extra \
    libgui_ext \
    libui_ext

# Camera
PRODUCT_PACKAGES += libcamera_parameters_mtk

# Ion
PRODUCT_PACKAGES += libion

# Doze
#PRODUCT_PACKAGES += XiaomiDoze

# GPS
PRODUCT_PACKAGES += \
    gps.mt6795 \
    libcurl \
    libnl_2 \
    mtk_agpsd \
    mnld \
    libmnl

# Bluetooth
PRODUCT_PACKAGES += \
    libbt-vendor \
    libbluetooth_mtk

# DRM
PRODUCT_PACKAGES += libmockdrmcryptoplugin

# FM Radio
PRODUCT_PACKAGES += \
	FMRadio \
	libfmcust

# Audio
PRODUCT_PACKAGES += \
    audio.a2dp.default \
    audio.r_submix.default \
    audio.usb.default \
    libaudio-resampler \
    libtinyalsa \
    libtinycompress \
    libtinyxml \
    tinymix

# XML Parser
PRODUCT_PACKAGES += libxml2

# hw composer
PRODUCT_PACKAGES += hwcomposer.mt6795

# Stlport
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/prebuilts/libstlport/lib/libstlport.so:system/lib/libstlport.so \
    $(DEVICE_PATH)/prebuilts/libstlport/lib64/libstlport.so:system/lib64/libstlport.so

# USB
PRODUCT_PACKAGES += com.android.future.usb.accessory

# Rootdir
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/rootdir/fstab.mt6795:$(TARGET_COPY_OUT_ROOT)/fstab.mt6795 \
    $(DEVICE_PATH)/rootdir/init.mt6795.rc:$(TARGET_COPY_OUT_ROOT)/init.mt6795.rc \
    $(DEVICE_PATH)/rootdir/init.mt6795.usb.rc:$(TARGET_COPY_OUT_ROOT)/init.mt6795.usb.rc \
    $(DEVICE_PATH)/rootdir/ueventd.mt6795.rc:$(TARGET_COPY_OUT_ROOT)/ueventd.mt6795.rc

# Permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.audio.low_latency.xml:system/vendor/etc/permissions/android.hardware.audio.low_latency.xml \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:system/vendor/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.bluetooth.xml:system/vendor/etc/permissions/android.hardware.bluetooth.xml \
    frameworks/native/data/etc/android.hardware.camera.autofocus.xml:system/vendor/etc/permissions/android.hardware.camera.autofocus.xml \
    frameworks/native/data/etc/android.hardware.camera.flash-autofocus.xml:system/vendor/etc/permissions/android.hardware.camera.flash-autofocus.xml \
    frameworks/native/data/etc/android.hardware.camera.front.xml:system/vendor/etc/permissions/android.hardware.camera.front.xml \
    frameworks/native/data/etc/android.hardware.consumerir.xml:system/vendor/etc/permissions/android.hardware.consumerir.xml \
    frameworks/native/data/etc/android.hardware.ethernet.xml:system/vendor/etc/permissions/android.hardware.ethernet.xml \
    frameworks/native/data/etc/android.hardware.location.gps.xml:system/vendor/etc/permissions/android.hardware.location.gps.xml \
    frameworks/native/data/etc/android.hardware.sensor.accelerometer.xml:system/vendor/etc/permissions/android.hardware.sensor.accelerometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.compass.xml:system/vendor/etc/permissions/android.hardware.compass.xml \
    frameworks/native/data/etc/android.hardware.sensor.gyroscope.xml:system/vendor/etc/permissions/android.hardware.sensor.gyroscope.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:system/vendor/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.sensor.proximity.xml:system/vendor/etc/permissions/android.hardware.sensor.proximity.xml \
    frameworks/native/data/etc/android.hardware.sensor.stepcounter.xml:system/vendor/etc/permissions/android.hardware.sensor.stepcounter.xml \
    frameworks/native/data/etc/android.hardware.telephony.cdma.xml:system/vendor/etc/permissions/android.hardware.telephony.cdma.xml \
    frameworks/native/data/etc/android.hardware.telephony.gsm.xml:system/vendor/etc/permissions/android.hardware.telephony.gsm.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.distinct.xml:system/vendor/etc/permissions/android.hardware.touchscreen.multitouch.distinct.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:system/vendor/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.xml:system/vendor/etc/permissions/android.hardware.touchscreen.multitouch.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.xml:system/vendor/etc/permissions/android.hardware.touchscreen.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:system/vendor/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:system/vendor/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:system/vendor/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:system/vendor/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/android.software.sip.voip.xml:system/vendor/etc/permissions/android.software.sip.voip.xml \
    frameworks/native/data/etc/handheld_core_hardware.xml:system/vendor/etc/permissions/handheld_core_hardware.xml

# Telephony (RIL)
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/telephony/ecc_list.xml:system/vendor/etc/ecc_list.xml \
    $(DEVICE_PATH)/configs/telephony/spn-conf.xml:system/vendor/etc/spn-conf.xml


# Camera
PRODUCT_COPY_FILES += $(DEVICE_PATH)/configs/init/mediaserver.rc:system/etc/init/mediaserver.rc

# Audio Wakelock (So Music will not stop while turn off screen)
PRODUCT_COPY_FILES += $(DEVICE_PATH)/configs/init/audioserver.rc:system/etc/init/audioserver.rc

# Wi-Fi
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/wifi/p2p_supplicant_overlay.conf:system/vendor/etc/wifi/p2p_supplicant_overlay.conf \
    $(DEVICE_PATH)/configs/wifi/wpa_supplicant.conf:system/vendor/etc/wifi/wpa_supplicant.conf \
    $(DEVICE_PATH)/configs/wifi/wpa_supplicant_overlay.conf:system/vendor/etc/wifi/wpa_supplicant_overlay.conf

# Audio
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/audio/audio_policy_configuration.xml:system/vendor/etc/audio/audio_policy_configuration.xml \
    $(DEVICE_PATH)/configs/audio/a2dp_audio_policy_configuration.xml:system/vendor/etc/audio/a2dp_audio_policy_configuration.xml \
    frameworks/av/services/audiopolicy/config/audio_policy_volumes.xml:system/vendor/etc/audio/audio_policy_volumes.xml \
    frameworks/av/services/audiopolicy/config/default_volume_tables.xml:system/vendor/etc/audio/default_volume_tables.xml \
    frameworks/av/services/audiopolicy/config/r_submix_audio_policy_configuration.xml:system/vendor/etc/audio/r_submix_audio_policy_configuration.xml \
    frameworks/av/services/audiopolicy/config/usb_audio_policy_configuration.xml:system/vendor/etc/audio/usb_audio_policy_configuration.xml

# Audio effects
PRODUCT_COPY_FILES += $(DEVICE_PATH)/configs/audio/audio_effects.xml:system/vendor/etc/audio_effects.xml

# Codecs
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/codecs/media_codecs_ffmpeg.xml:system/vendor/etc/media_codecs_ffmpeg.xml \
    $(DEVICE_PATH)/configs/codecs/media_codecs_mediatek_audio.xml:system/vendor/etc/media_codecs_mediatek_audio.xml \
    $(DEVICE_PATH)/configs/codecs/media_codecs_mediatek_video.xml:system/vendor/etc/media_codecs_mediatek_video.xml \
    $(DEVICE_PATH)/configs/codecs/media_codecs_performance.xml:system/vendor/etc/media_codecs_performance.xml \
    $(DEVICE_PATH)/configs/codecs/media_codecs.xml:system/vendor/etc/media_codecs.xml \
    $(DEVICE_PATH)/configs/codecs/media_profiles.xml:system/vendor/etc/media_profiles.xml

# Google codecs
PRODUCT_COPY_FILES += \
    frameworks/av/media/libstagefright/data/media_codecs_google_audio.xml:system/vendor/etc/media_codecs_google_audio.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_telephony.xml:system/vendor/etc/media_codecs_google_telephony.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video_le.xml:system/vendor/etc/media_codecs_google_video_le.xml

# GPS
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/gps/slp_conf:system/vendor/etc/slp_conf \
    $(DEVICE_PATH)/configs/gps/gps.conf:system/vendor/etc/gps.conf \
    $(DEVICE_PATH)/configs/gps/agps_profiles_conf2.xml:system/vendor/etc/agps_profiles_conf2.xml

# Bluetooth
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/bluetooth/auto_pair_devlist.conf:system/vendor/etc/bluetooth/auto_pair_devlist.conf \
    $(DEVICE_PATH)/configs/bluetooth/bt_stack.conf.debug:system/vendor/etc/bluetooth/bt_stack.conf.debug \
    $(DEVICE_PATH)/configs/bluetooth/bt_did.conf:system/vendor/etc/bluetooth/bt_did.conf \
    $(DEVICE_PATH)/configs/bluetooth/bt_stack.conf:system/vendor/etc/bluetooth/bt_stack.conf \
    $(DEVICE_PATH)/configs/bluetooth/bt_stack.conf.sqc:system/vendor/etc/bluetooth/bt_stack.conf.sqc

# Vulkan
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.vulkan.level-0.xml:system/vendor/etc/permissions/android.hardware.vulkan.level.xml \
    frameworks/native/data/etc/android.hardware.vulkan.version-1_0_3.xml:system/vendor/etc/permissions/android.hardware.vulkan.version.xml

# Seccomp policy
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/seccomp/mediacodec.policy:system/vendor/etc/seccomp_policy/mediacodec.policy \
    $(DEVICE_PATH)/seccomp/mediaextractor.policy:system/vendor/etc/seccomp_policy/mediaextractor.policy

# HIDL Manifest
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/manifest.xml:system/vendor/manifest.xml

# Filesystem management tools
PRODUCT_PACKAGES += \
	e2fsck \
	fibmap.f2fs \
	fsck.f2fs \
	mkfs.f2fs \
	make_ext4fs \
	resize2fs \
	setup_fs \
	ext4_resize \
	libext2_blkid \
	libext2_uuid_static \
	superumount

# exFAT
PRODUCT_PACKAGES += \
	mount.exfat \
	fsck.exfat \
	mkfs.exfat

# NTFS
PRODUCT_PACKAGES += \
	fsck.ntfs \
	mkfs.ntfs \
	mount.ntfs

# dalvik GC tag
PRODUCT_TAGS += dalvik.gc.type-precise
