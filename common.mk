#
# Copyright (C) 2018 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_l.mk)

# Inherit from hermes device
$(call inherit-product, device/xiaomi/hermes/device.mk)

PRODUCT_DEVICE := hermes
PRODUCT_BRAND := Xiaomi
PRODUCT_MODEL := Redmi Note 2
PRODUCT_MANUFACTURER := Xiaomi

#ifeq ($(TARGET_BUILD_VARIANT),user)
PRODUCT_GMS_CLIENTID_BASE := android-xiaomi
BUILD_FINGERPRINT := "Xiaomi/hermes/hermes:5.0.2/LRX22G/V9.6.3.0.LHMMIFD:user/release-keys"
PRODUCT_BUILD_PROP_OVERRIDES += \
    TARGET_DEVICE=hermes \
    PRODUCT_NAME=lineage_hermes \
    PRIVATE_BUILD_DESC="hermes-user 5.0.2 LRX22G V9.6.3.0.LHMMIFD release-keys"
#endif
