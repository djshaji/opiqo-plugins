LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := gx_maestro_fz1b
LOCAL_SRC_FILES := ../plugin/gx_maestro_fz1b.cpp

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/../dsp \
    $(LOCAL_PATH)/../dsp/zita-resampler-1.1.0 \
    $(LOCAL_PATH)/../dsp/zita-resampler-1.1.0/zita-resampler \
    $(LOCAL_PATH)/../plugin \
    $(LOCAL_PATH)/../../lv2-headers

LOCAL_CPPFLAGS := \
    -D_FORTIFY_SOURCE=2 \
    -O3 \
    -Wall \
    -fstack-protector \
    -funroll-loops \
    -ffast-math \
    -fomit-frame-pointer \
    -fstrength-reduce \
    -fdata-sections \
    -ffunction-sections \
    -fvisibility=hidden \
    -std=c++11

LOCAL_LDFLAGS := \
    -Wl,--gc-sections \
    -Wl,--strip-all

LOCAL_LDLIBS := -lm -llog

include $(BUILD_SHARED_LIBRARY)
