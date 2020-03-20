ifneq ($(wildcard vendor/lineage/.),)
PRODUCT_MAKEFILES := $(LOCAL_DIR)/lineage_hermes.mk
endif
