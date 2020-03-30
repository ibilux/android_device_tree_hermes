# Inherit some common CarbonROM stuff.
$(call inherit-product, vendor/carbon/config/common.mk)

# Inherit from common
$(call inherit-product, device/xiaomi/hermes/common.mk)

PRODUCT_NAME := carbon_hermes
