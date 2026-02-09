#!/usr/bin/env python3
"""Generate Android.mk and Application.mk for all GxPlugins"""

import os
import sys

# List of plugins with their NAME from Makefile
plugins = [
    ("GxAxisFace.lv2", "gx_AxisFace"),
    ("GxBaJaTubeDriver.lv2", "gx_bajatubedriver"),
    ("GxBlueAmp.lv2", "gx_blueamp"),
    ("GxBoobTube.lv2", "gx_boobtube"),
    ("GxBottleRocket.lv2", "gx_bottlerocket"),
    ("GxClubDrive.lv2", "gx_clubdrive"),
    ("GxCreamMachine.lv2", "gx_CreamMachine"),
    ("GxDOP250.lv2", "gx_DOP250"),
    ("GxEpic.lv2", "gx_epic"),
    ("GxEternity.lv2", "gx_eternity"),
    ("GxFz1b.lv2", "gx_maestro_fz1b"),
    ("GxFz1s.lv2", "gx_maestro_fz1s"),
    ("GxGuvnor.lv2", "gx_guvnor"),
    ("GxHeathkit.lv2", "gx_Heathkit"),
    ("GxHotBox.lv2", "gx_hotbox"),
    ("GxHyperion.lv2", "gx_hyperion"),
    ("GxKnightFuzz.lv2", "gx_KnightFuzz"),
    ("GxLiquidDrive.lv2", "gx_liquiddrive"),
    ("GxLuna.lv2", "gx_luna"),
    ("GxMicroAmp.lv2", "gx_MicroAmp"),
    ("GxPlexi.lv2", "gx_plexi"),
    ("GxQuack.lv2", "gx_quack"),
    ("GxSaturator.lv2", "gx_saturate"),
    ("GxSD1.lv2", "gx_sd1sim"),
    ("GxSD2Lead.lv2", "gx_sd2lead"),
    ("GxShakaTube.lv2", "gx_shakatube"),
    ("GxSloopyBlue.lv2", "gx_sloopyblue"),
    ("GxSlowGear.lv2", "gx_slowgear"),
    ("GxSunFace.lv2", "gx_SunFace"),
    ("GxSuperFuzz.lv2", "gx_sfp"),
    ("GxSupersonic.lv2", "gx_supersonic"),
    ("GxSuppaToneBender.lv2", "gx_vstb"),
    ("GxSVT.lv2", "gx_ampegsvt"),
    ("GxTimRay.lv2", "gx_timray"),
    ("GxToneMachine.lv2", "gx_tonemachine"),
    ("GxTubeDistortion.lv2", "gx_TubeDistortion"),
    ("GxUltraCab.lv2", "gx_ultracab"),
    ("GxUVox720k.lv2", "gx_uvox"),
    ("GxValveCaster.lv2", "gx_valvecaster"),
    ("GxVBassPreAmp.lv2", "gx_voxbass"),
    ("GxVintageFuzzMaster.lv2", "gx_vfm"),
    ("GxVmk2.lv2", "gx_vmk2d"),
    ("GxVoodoFuzz.lv2", "gx_voodoo"),
]

# Plugins with zita-resampler (need extra include paths)
zita_plugins = {
    "GxBoobTube.lv2",
    "GxClubDrive.lv2",
    "GxCreamMachine.lv2",
    "GxEternity.lv2",
    "GxFz1b.lv2",
    "GxShakaTube.lv2",
    "GxSuperFuzz.lv2",
    "GxSuppaToneBender.lv2",
    "GxSVT.lv2",
    "GxTubeDistortion.lv2",
    "GxValveCaster.lv2",
    "GxVBassPreAmp.lv2",
    "GxVmk2.lv2",
}

ANDROID_MK_TEMPLATE = """LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := {module_name}
LOCAL_SRC_FILES := ../plugin/{module_name}.cpp

LOCAL_C_INCLUDES := \\
    $(LOCAL_PATH)/../dsp \\
    $(LOCAL_PATH)/../plugin{zita_includes}\\
    $(LOCAL_PATH)/../../lv2-headers

LOCAL_CPPFLAGS := \\
    -D_FORTIFY_SOURCE=2 \\
    -O3 \\
    -Wall \\
    -fstack-protector \\
    -funroll-loops \\
    -ffast-math \\
    -fomit-frame-pointer \\
    -fstrength-reduce \\
    -fdata-sections \\
    -ffunction-sections \\
    -fvisibility=hidden \\
    -std=c++11

LOCAL_LDFLAGS := \\
    -Wl,--gc-sections \\
    -Wl,--strip-all

LOCAL_LDLIBS := -lm -llog

include $(BUILD_SHARED_LIBRARY)
"""

ANDROID_MK_WITH_ZITA = """LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := {module_name}
LOCAL_SRC_FILES := ../plugin/{module_name}.cpp

LOCAL_C_INCLUDES := \\
    $(LOCAL_PATH)/../dsp \\
    $(LOCAL_PATH)/../dsp/zita-resampler-1.1.0 \\
    $(LOCAL_PATH)/../dsp/zita-resampler-1.1.0/zita-resampler \\
    $(LOCAL_PATH)/../plugin \\
    $(LOCAL_PATH)/../../lv2-headers

LOCAL_CPPFLAGS := \\
    -D_FORTIFY_SOURCE=2 \\
    -O3 \\
    -Wall \\
    -fstack-protector \\
    -funroll-loops \\
    -ffast-math \\
    -fomit-frame-pointer \\
    -fstrength-reduce \\
    -fdata-sections \\
    -ffunction-sections \\
    -fvisibility=hidden \\
    -std=c++11

LOCAL_LDFLAGS := \\
    -Wl,--gc-sections \\
    -Wl,--strip-all

LOCAL_LDLIBS := -lm -llog

include $(BUILD_SHARED_LIBRARY)
"""

APPLICATION_MK = """APP_PLATFORM := android-34
APP_ABI := armeabi-v7a arm64-v8a x86 x86_64
APP_STL := c++_shared
APP_CPPFLAGS := -frtti -fexceptions
APP_OPTIM := release
"""

def generate_files():
    """Generate Android.mk and Application.mk for all plugins"""
    count = 0
    skipped = 0
    
    for plugin_dir, module_name in plugins:
        jni_dir = os.path.join(plugin_dir, "jni")
        android_mk_path = os.path.join(jni_dir, "Android.mk")
        application_mk_path = os.path.join(plugin_dir, "Application.mk")
        
        # Create jni directory if it doesn't exist
        os.makedirs(jni_dir, exist_ok=True)
        
        # Choose template based on zita-resampler presence
        if plugin_dir in zita_plugins:
            android_mk_content = ANDROID_MK_WITH_ZITA.format(module_name=module_name)
        else:
            android_mk_content = ANDROID_MK_TEMPLATE.format(
                module_name=module_name,
                zita_includes=" \\\n    "
            )
        
        # Write Android.mk to jni/
        with open(android_mk_path, "w") as f:
            f.write(android_mk_content)
        
        # Write Application.mk to plugin root
        os.makedirs(plugin_dir, exist_ok=True)
        with open(application_mk_path, "w") as f:
            f.write(APPLICATION_MK)
        
        count += 1
        print(f"Generated {plugin_dir} (zita: {plugin_dir in zita_plugins})")
    
    print(f"\nGenerated {count} plugins")
    return count > 0

if __name__ == "__main__":
    if generate_files():
        sys.exit(0)
    else:
        print("No new files generated")
        sys.exit(1)
