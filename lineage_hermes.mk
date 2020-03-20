# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Inherit from common
$(call inherit-product, device/xiaomi/hermes/common.mk)

PRODUCT_NAME := lineage_hermes
