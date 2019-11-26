LOCAL_PATH:= $(call my-dir)

######################################################################
#
# libui_ext.so
#

include $(CLEAR_VARS)
LOCAL_MODULE := libui_ext
LOCAL_MODULE_TAGS := optional

#ifeq ($(MTK_MIRAVISION_SUPPORT),yes)
LOCAL_CFLAGS += -DCONFIG_FOR_SOURCE_PQ
#endif

ifeq ($(FPGA_EARLY_PORTING), yes)
LOCAL_CFLAGS += -DFPGA_EARLY_PORTING
endif

LOCAL_SRC_FILES := \
	lib/FpsCounter.cpp \
	lib/GraphicBufferUtil.cpp \
	lib/SWWatchDog.cpp

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/inc \
	$(TOP)/frameworks/native/libs/nativewindow/include \
	$(TOP)/frameworks/native/libs/nativebase/include \
	$(TOP)/frameworks/native/libs/arect/include \
	$(TOP)/external/libpng \
	$(TOP)/external/zlib \
	$(TOP)/external/skia/src/images \
	$(TOP)/external/skia/include/core \
        $(TOP)/external/skia/include/config \
        $(TOP)/external/skqp/include/config \
        $(TOP)/external/pdfium/skia/config

LOCAL_SHARED_LIBRARIES := \
	libutils \
	libcutils \
	liblog \
	libbinder \
	libhardware \
	libdl \
	libgralloc_extra \
	libpng \
	libui

#ifeq (, $(findstring MTK_AOSP_ENHANCEMENT, $(MTK_GLOBAL_CFLAGS)))
	LOCAL_SRC_FILES += \
		lib/IDumpTunnel.cpp \
		lib/RefBaseDump.cpp
#endif

LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

######################################################################
#
# libgui_ext.so
#

include $(CLEAR_VARS)
LOCAL_MODULE := libgui_ext
LOCAL_MODULE_TAGS := optional

#ifeq ($(MTK_MIRAVISION_SUPPORT),yes)
LOCAL_CFLAGS += -DCONFIG_FOR_SOURCE_PQ
#endif

LOCAL_SRC_FILES := \
	lib/IGuiExtService.cpp \
	lib/GuiExtService.cpp \
	lib/GuiExtClient.cpp \
	lib/GuiExtClientProducer.cpp \
	lib/GuiExtClientConsumer.cpp \
	lib/GuiExtImpl.cpp

LOCAL_C_INCLUDES := \
		$(LOCAL_PATH)/inc \

LOCAL_SHARED_LIBRARIES := \
	libutils \
	libcutils \
	libbinder \
	libhardware \
	libhardware_legacy \
	libgui \
	liblog \
	libui \
	libdl \
	libion \
	libion_mtk \
	libgralloc_extra \
	libui_ext

LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))

######################################################################
