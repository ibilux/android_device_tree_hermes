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
