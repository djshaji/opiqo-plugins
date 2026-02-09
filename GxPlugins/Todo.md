- Create Android.mk and Application.mk for each of the plugins
- Target Android API level APP_PLATFORM := android-34
- APP_ABI := armeabi-v7a arm64-v8a x86 x86_64
- Build targets: nogui

- Build the plugins using ndk-build

- Create a directory structure for the plugins in the Android project
  - jniLibs/armeabi-v7a/
  - jniLibs/arm64-v8a/
  - jniLibs/x86/
  - jniLibs/x86_64/

# Agent Plan
## Plan: Android NDK Build System for GxPlugins.lv2

This plan adds Android NDK build support for all 43 LV2 audio plugins, targeting nogui builds (DSP only, no Cairo/X11 GUI dependencies). Each plugin will get Android.mk and Application.mk files compatible with ndk-build, supporting multi-architecture Android deployment (armeabi-v7a, arm64-v8a, x86, x86_64) on API level 34.

**Key Decisions:**
- LV2 headers (lv2.h, lv2_util.h, etc.) will be included in a common `lv2-headers/` directory at workspace root
- Standard NDK output structure (`libs/[abi]/`) will be used; manual copy to `jniLibs/` later via script
- Using C++11 (-std=c++11) for Faust-generated DSP code compatibility
- All 43 plugins follow identical pattern except 3 with zita-resampler dependency (GxBoobTube, GxCreamMachine, GxSVT)

**Steps**

1. **Create common LV2 headers directory**
   - Create [lv2-headers/](lv2-headers/) at workspace root
   - Copy or download minimal LV2 header set (lv2.h, lv2/lv2plug.in/ns/lv2core/lv2.h)
   - These headers define `LV2_Descriptor`, port connection API, etc.

2. **Create template build files for standard plugins** 
   - Create [GxAxisFace.lv2/Android.mk](GxAxisFace.lv2/Android.mk) as reference template:
     - `LOCAL_PATH := $(call my-dir)`
     - `LOCAL_MODULE := gx_AxisFace` (matches NAME in Makefile)
     - `LOCAL_SRC_FILES := plugin/gx_AxisFace.cpp` (single source file)
     - `LOCAL_C_INCLUDES := $(LOCAL_PATH)/dsp $(LOCAL_PATH)/plugin $(LOCAL_PATH)/../../lv2-headers`
     - `LOCAL_CPPFLAGS := -D_FORTIFY_SOURCE=2 -O3 -Wall -fstack-protector -funroll-loops -ffast-math -fomit-frame-pointer -fstrength-reduce -fdata-sections -ffunction-sections -fvisibility=hidden -std=c++11`
     - `LOCAL_LDFLAGS := -Wl,--gc-sections -Wl,--strip-all`
     - `LOCAL_LDLIBS := -lm -llog`
     - `include $(BUILD_SHARED_LIBRARY)`
   
   - Create [GxAxisFace.lv2/Application.mk](GxAxisFace.lv2/Application.mk):
     - `APP_PLATFORM := android-34`
     - `APP_ABI := armeabi-v7a arm64-v8a x86 x86_64`
     - `APP_STL := c++_shared` (for C++ standard library)
     - `APP_CPPFLAGS := -frtti -fexceptions`
     - `APP_OPTIM := release`

3. **Replicate build files to remaining 39 standard plugins**
   - Copy Android.mk template to each plugin directory, modifying:
     - `LOCAL_MODULE` value (e.g., `gx_bottlerocket`, `gx_timray`)
     - `LOCAL_SRC_FILES` to match plugin .cpp file name from Makefile `OBJECTS` variable
   - Copy Application.mk identically (no changes needed)
   - Affected plugins: GxBaJaTubeDriver, GxBlueAmp, GxBottleRocket, GxClubDrive, GxCreamMachine (needs special handling), GxDOP250, GxEpic, GxEternity, GxFz1b, GxFz1s, GxGuvnor, GxHeathkit, GxHotBox, GxHyperion, GxKnightFuzz, GxLiquidDrive, GxLuna, GxMicroAmp, GxPlexi, GxQuack, GxSaturator, GxSD1, GxSD2Lead, GxShakaTube, GxSloopyBlue, GxSlowGear, GxSunFace, GxSuperFuzz, GxSupersonic, GxSuppaToneBender, GxTimRay, GxToneMachine, GxTubeDistortion, GxUltraCab, GxUVox720k, GxValveCaster, GxVBassPreAmp, GxVintageFuzzMaster, GxVmk2, GxVoodoFuzz

4. **Create specialized build files for zita-resampler plugins**
   - Create [GxBoobTube.lv2/Android.mk](GxBoobTube.lv2/Android.mk) with additions:
     - `LOCAL_C_INCLUDES` add: `$(LOCAL_PATH)/dsp/zita-resampler-1.1.0 $(LOCAL_PATH)/dsp/zita-resampler-1.1.0/zita-resampler`
     - `LOCAL_SRC_FILES` add: `dsp/zita-resampler-1.1.0/resampler.cc dsp/zita-resampler-1.1.0/resampler-table.cc` (check actual file names in each plugin's dsp/zita-resampler-1.1.0/ directory)
   - Replicate to [GxCreamMachine.lv2/Android.mk](GxCreamMachine.lv2/Android.mk) and [GxSVT.lv2/Android.mk](GxSVT.lv2/Android.mk)
   - Copy Application.mk identically to all 3

5. **Create root-level build script**
   - Create [build_android_all.sh](build_android_all.sh) at workspace root:
     - Iterates through all `Gx*.lv2/` directories
     - Runs `ndk-build` in each (requires `NDK_PROJECT_PATH` or cd into directory)
     - Collects build success/failure status
     - Logs results
   - Make script executable

6. **Create jniLibs deployment script**
   - Create [copy_to_jniLibs.sh](copy_to_jniLibs.sh):
     - Creates directory structure: `jniLibs/armeabi-v7a/`, `jniLibs/arm64-v8a/`, `jniLibs/x86/`, `jniLibs/x86_64/`
     - Copies all `Gx*.lv2/libs/[abi]/libgx_*.so` to corresponding `jniLibs/[abi]/`
     - Preserves file permissions
   - Make script executable

7. **Create documentation file**
   - Create [ANDROID_BUILD.md](ANDROID_BUILD.md):
     - Prerequisites (Android NDK installation, environment setup)
     - Build instructions (`./build_android_all.sh`)
     - Individual plugin build command (`cd GxAxisFace.lv2 && ndk-build`)
     - Deployment instructions (`./copy_to_jniLibs.sh`)
     - Architecture-specific notes (ARM NEON optimizations handled by NDK automatically)
     - Troubleshooting common issues

**Verification**

- Test build: `cd GxAxisFace.lv2 && ndk-build` should produce `libs/*/libgx_AxisFace.so`
- Verify multi-arch: Check 4 ABI directories exist with .so files
- Test complex plugin: Build GxSVT (has zita-resampler) successfully
- Run full build: `./build_android_all.sh` should build all 43 plugins
- Verify deployment: `./copy_to_jniLibs.sh` creates proper structure with all .so files
- Check file sizes: .so files should be ~50KB-500KB stripped (nogui, no debug symbols)
- Symbol check: `arm-linux-androideabi-nm libgx_*.so` should show `lv2_descriptor` symbol exported

**Technical Notes**

- ARM optimization flags (-march, -mfpu) handled automatically by NDK based on APP_ABI
- SSE flags omitted for x86 (NDK defaults appropriate for target)
- Strip flags in LDFLAGS ensure minimal binary size
- LV2 bundles (.lv2 directory structure with .ttl files) not needed for Android builds - only .so files loaded dynamically

This plan creates a maintainable Android NDK build system by leveraging the existing nogui Makefile pattern and adapting it to NDK's build conventions. The modular approach allows individual plugin rebuilds and easy addition of new plugins following the established template.