# Display
PRODUCT_PROPERTY_OVERRIDES += debug.hwui.use_buffer_age=false

# AudioFlinger
PRODUCT_PROPERTY_OVERRIDES += ro.af.client_heap_size_kbyte=7168

# Enable call recording
PRODUCT_PROPERTY_OVERRIDES += \
    persist.call_recording.enabled=true \
    persist.call_recording.src=4
# ADB
ifneq ($(TARGET_BUILD_VARIANT),user)
PRODUCT_PROPERTY_OVERRIDES += persist.sys.usb.config=adb \
    ro.adb.secure=0 \
    ro.secure=0 \
    ro.debuggable=1
endif

# Bluetooth
PRODUCT_PROPERTY_OVERRIDES += ro.boot.btmacaddr=00:00:00:00:00:00

# Graphics and codecs
PRODUCT_PROPERTY_OVERRIDES += \
    debug.hwui.renderer=opengl \
    debug.hwui.use_partial_updates=false \
    debug.sf.disable_backpressure=1 \
    debug.sf.latch_unsignaled=1 \
    persist.sys.display.clearMotion=1 \
    ro.mtk_deinterlace_support=1 \
    ro.mtk_pq_support=2 \
    ro.opengles.version=196609 \
    ro.sf.lcd_density=480

# RIL
PRODUCT_PROPERTY_OVERRIDES += \
    persist.radio.fd.counter=15 \
    persist.radio.fd.off.counter=5 \
    persist.radio.fd.off.r8.counter=5 \
    persist.radio.fd.r8.counter=15 \
    persist.radio.multisim.config=dsds \
    rild.libpath=/vendor/lib64/mtk-ril.so \
    rild.libargs=-d /dev/ttyC0 \
    ril.current.share_modem=2 \
    ril.external.md=0 \
    ril.telephony.mode=0 \
    ro.mtk_enable_md1=1 \
    ro.mtk_flight_mode_power_off_md=1 \
    ro.mtk_md_sbp_custom_value=1 \
    ro.mtk_rild_read_imsi=1 \
    ro.mtk_world_phone=1 \
    ro.telephony.default_network=9 \
    ro.telephony.sim.count=2

# custom patches
PRODUCT_PROPERTY_OVERRIDES += \
    ro.battery.savermode_color=0xff008080

# Disable dirty region for Mali
PRODUCT_PROPERTY_OVERRIDES += \
    debug.hwui.render_dirty_regions=false

# Camera
PRODUCT_PROPERTY_OVERRIDES += \
    media.stagefright.legacyencoder=true \
    media.stagefright.less-secure=true \
    camera.disable_zsl_mode=1

# Media Settings
PRODUCT_PROPERTY_OVERRIDES += \
    persist.media.treble_omx=false
