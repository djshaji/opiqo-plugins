# Opiqo Plugins

A comprehensive collection of 43 LV2 audio effect plugins for guitar, bass, and audio processing, optimized for Android devices. This repository packages the GxPlugins.lv2 suite with full Android NDK build support for integration into mobile audio applications.

## Overview

Opiqo Plugins is based on the [GxPlugins.lv2](https://github.com/brummer10/GxPlugins.lv2) project, providing high-quality guitar amp and effects simulations. Each plugin is modeled after classic hardware pedals, amplifiers, and effects units, delivering authentic analog sound on Android devices.

## Features

- **43 Professional Audio Plugins** including overdrives, fuzzes, distortions, amplifiers, and effects
- **Multi-Architecture Android Support**: ARMv7-a, ARM64-v8a, x86, x86_64
- **Real-Time Performance**: Optimized DSP code with no memory allocation in audio path
- **No-GUI Builds**: Headless versions perfect for embedded audio applications
- **Classic Hardware Emulations**: Based on legendary pedals and amplifiers
- **LV2 Standard Compliant**: Industry-standard plugin format

## Plugin Categories

### Overdrive Pedals (14 plugins)
- GxBottleRocket - Mesa V1 Bottle Rocket tube overdrive
- GxSD1 - Boss SD-1 Super Overdrive
- GxSD2Lead - Boss SD-2 Dual Overdrive
- GxGuvnor - Marshall "The Guv'nor"
- GxHotBox - Matchless Hot Box tube overdrive
- GxValveCaster - Valve Caster tube effect
- GxBoobTube - Boob Tube overdrive
- GxShakaTube - ShakaTube overdrive
- GxBaJaTubeDriver - BaJa Tube Driver
- GxTimRay - Vemuram Jan Ray
- GxLuna - Gnarly overdrive
- GxSloopyBlue - Overdrive simulation
- GxEternity - Low compression overdrive
- GxClubDrive - EF86 Pentode Valve simulation

### Fuzz & Distortion (16 plugins)
- GxAxisFace - Axis Face Silicon fuzz
- GxFz1b - Maestro FZ-1B (Moog-designed)
- GxFz1s - Maestro FZ-1S Super-Fuzz
- GxHyperion - Devi Ever FX Hyperion
- GxKnightFuzz - Basic Audio Knight Fuzz
- GxLiquidDrive - Modified Ross Distortion
- GxSunFace - Analog Man Sun Face
- GxSuperFuzz - Univox Super-Fuzz
- GxToneMachine - Foxx Tone Machine
- GxSuppaToneBender - Vox Supa Tonebender
- GxSaturator - Vox Satchurator (Joe Satriani)
- GxVintageFuzzMaster - Devi Ever Vintage Fuzz Master
- GxVoodoFuzz - Voodoo Lab SuperFuzz
- GxTubeDistortion - Generic tube distortion
- GxHeathkit - Heathkit TA-28 distortion/booster
- GxDOP250 - DOD OD-250 Yellow Overdrive

### Amplifiers (10 plugins)
- GxMicroAmp - Simple booster
- GxVBassPreAmp - Vox Venue Bass 100 Pre Amp
- GxSVT - Ampeg SVT-CL Bass Head
- GxVmk2 - Vox MKII solid state preamp
- GxUvox720k - Univox 720k keyboard amp
- GxCreamMachine - Power amplifier
- GxEpic - Valve Junior inspired
- GxSupersonic - Power amplifier
- GxBlueAmp - Late 1950s Fender-inspired
- GxPlexi - Power amp simulation

### Other Effects (3 plugins)
- GxQuack - Autowah
- GxSlowGear - Attack-smoothing auto-swelling
- GxUltraCab - Cabinet simulator

## Quick Start

### For Linux Development

```bash
cd GxPlugins
make
sudo make install  # installs to /usr/lib/lv2
# OR
make install       # installs to ~/.lv2
```

### For Android Development

```bash
cd GxPlugins
./build_android_all.sh           # Build all plugins for all architectures
./copy_to_jniLibs.sh            # Copy to jniLibs structure
# Then copy jniLibs/ to your Android project
```

See the detailed [Android Build Guide](GxPlugins/ANDROID_BUILD.md) for complete instructions.

## Requirements

### Linux Build Dependencies
- libc6-dev
- libcairo2-dev
- libx11-dev
- x11proto-dev
- lv2-dev

```bash
sudo apt install libc6-dev libcairo2-dev libx11-dev x11proto-dev lv2-dev
```

### Android Build Requirements
- Android NDK r26 or later
- Bash shell
- Standard Unix tools (find, sed, grep)

## Android Integration

### Build Output Structure

After building for Android, each plugin generates:

```
GxAxisFace.lv2/libs/
├── armeabi-v7a/libgx_AxisFace.so
├── arm64-v8a/libgx_AxisFace.so
├── x86/libgx_AxisFace.so
└── x86_64/libgx_AxisFace.so
```

### Integration Steps

1. Build all plugins: `cd GxPlugins && ./build_android_all.sh`
2. Deploy libraries: `./copy_to_jniLibs.sh`
3. Copy to Android project: `cp -r jniLibs /path/to/AndroidProject/app/src/main/`
4. Load in Java/Kotlin: `System.loadLibrary("gx_AxisFace")`

## Performance

### CPU Usage (Approximate)
- **Simple plugins**: 2-5% per instance (GxAxisFace, GxMicroAmp)
- **Medium plugins**: 5-15% per instance (GxBlueAmp, GxClubDrive)
- **Complex plugins**: 15-25% per instance (GxSVT, GxSupersonic)

*Estimates based on 48kHz buffer sizes on modern ARM devices*

### File Sizes (Release builds)
- Simple plugins: ~50-150 KB per architecture
- Complex plugins: ~250-500 KB per architecture
- With resampler: +100-200 KB

## Project Structure

```
opiqo-plugins/
├── README.md                    # This file
└── GxPlugins/                   # Main plugin suite
    ├── README.md                # Detailed plugin documentation
    ├── ANDROID_BUILD.md         # Android build guide
    ├── Makefile                 # Linux build system
    ├── build_android_all.sh     # Android batch build script
    ├── copy_to_jniLibs.sh      # Android deployment script
    ├── generate_android_mk.py   # Android.mk generator
    ├── lv2-headers/             # LV2 API headers
    ├── assets/                  # Plugin asset bundles
    ├── GxAxisFace.lv2/         # Individual plugin (example)
    │   ├── Android.mk           # NDK build config
    │   ├── Application.mk       # NDK app config
    │   ├── Makefile            # Linux build
    │   ├── dsp/                # DSP processing code
    │   ├── gui/                # GUI code (not used in Android)
    │   ├── plugin/             # Plugin wrapper
    │   └── libs/               # Android build output
    └── [42 more plugin directories...]
```

## Documentation

- [Main Plugin Documentation](GxPlugins/README.md) - Complete plugin list with images
- [Android Build Guide](GxPlugins/ANDROID_BUILD.md) - Detailed Android NDK build instructions
- [Linux Build Instructions](GxPlugins/README.md#build-and-installation) - Linux desktop build guide

## Trademark Notice

The product names modeled in this software are trademarks of their respective companies that do not endorse and are not associated or affiliated with these simulations. All trademarks are the property of their respective holders.

## License

GxPlugins.lv2 is licensed under the GNU General Public License. See [LICENSE](GxPlugins/LICENSE) for details.

## Credits

- **Original GxPlugins.lv2**: [brummer10/GxPlugins.lv2](https://github.com/brummer10/GxPlugins.lv2)
- **Guitarix Project**: [guitarix.org](https://guitarix.org)
- **Android Port**: Opiqo Plugins project

## Support

For build issues, Android integration questions, or bug reports:
1. Check the [Android Build Guide](GxPlugins/ANDROID_BUILD.md) troubleshooting section
2. Review build logs: `cat GxPlugins/android_build.log`
3. Try verbose single-plugin builds to diagnose issues

## Contributing

Contributions are welcome! Please ensure:
- Code builds successfully on both Linux and Android
- Follow existing code style and structure
- Test on multiple Android architectures
- Update documentation for any API changes
