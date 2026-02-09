#!/bin/bash
# Build all GxPlugins for Android using NDK
# Usage: ./build_android_all.sh [clean]

set -e

WORKSPACE=$(cd "$(dirname "$0")" && pwd)
LOG_FILE="$WORKSPACE/android_build.log"
BUILD_TIME=$(date "+%Y-%m-%d %H:%M:%S")
TOTAL_PLUGINS=0
SUCCESSFUL=0
FAILED=0
FAILED_PLUGINS=""

# Check if NDK is available
if ! command -v ndk-build &> /dev/null; then
    echo "ERROR: ndk-build not found in PATH"
    echo "Please install Android NDK and add it to PATH"
    echo "Example: export PATH=\$PATH:/path/to/android-ndk-rXX/build/ndk-build"
    exit 1
fi

echo "========================================" | tee "$LOG_FILE"
echo "Android NDK Build for GxPlugins.lv2" | tee -a "$LOG_FILE"
echo "Build started: $BUILD_TIME" | tee -a "$LOG_FILE"
echo "NDK Version: $(ndk-build --version 2>&1 || echo 'unknown')" | tee -a "$LOG_FILE"
echo "========================================" | tee -a "$LOG_FILE"
echo "" | tee -a "$LOG_FILE"

# Clean targets if requested
if [[ "$1" == "clean" ]]; then
    echo "Cleaning build directories..." | tee -a "$LOG_FILE"
    for plugin_dir in "$WORKSPACE"/Gx*.lv2; do
        if [[ -d "$plugin_dir/jni" && -f "$plugin_dir/jni/Android.mk" ]]; then
            echo "Cleaning $(basename "$plugin_dir")..." | tee -a "$LOG_FILE"
            cd "$plugin_dir"
            ndk-build clean &>> "$LOG_FILE" || true
            rm -rf libs obj
            cd "$WORKSPACE"
        fi
    done
    echo "Clean completed." | tee -a "$LOG_FILE"
    exit 0
fi

# Build all plugins
for plugin_dir in "$WORKSPACE"/Gx*.lv2; do
    if [[ -d "$plugin_dir/jni" && -f "$plugin_dir/jni/Android.mk" ]]; then
        plugin_name=$(basename "$plugin_dir")
        TOTAL_PLUGINS=$((TOTAL_PLUGINS + 1))
        
        echo "Building $plugin_name..." | tee -a "$LOG_FILE"
        
        cd "$plugin_dir"
        
        if ndk-build -j4 >> "$LOG_FILE" 2>&1; then
            SUCCESSFUL=$((SUCCESSFUL + 1))
            # Count generated .so files
            so_count=$(find libs -name "*.so" 2>/dev/null | wc -l)
            echo "  ✓ Success ($so_count .so files generated)" | tee -a "$LOG_FILE"
        else
            FAILED=$((FAILED + 1))
            FAILED_PLUGINS="$FAILED_PLUGINS\n  - $plugin_name"
            echo "  ✗ FAILED" | tee -a "$LOG_FILE"
        fi
        
        cd "$WORKSPACE"
    fi
done

# Build summary
echo "" | tee -a "$LOG_FILE"
echo "========================================" | tee -a "$LOG_FILE"
echo "Build Summary" | tee -a "$LOG_FILE"
echo "========================================" | tee -a "$LOG_FILE"
echo "Total plugins: $TOTAL_PLUGINS" | tee -a "$LOG_FILE"
echo "Successful: $SUCCESSFUL" | tee -a "$LOG_FILE"
echo "Failed: $FAILED" | tee -a "$LOG_FILE"

if [[ $FAILED -gt 0 ]]; then
    echo "" | tee -a "$LOG_FILE"
    echo "Failed plugins:" | tee -a "$LOG_FILE"
    echo -e "$FAILED_PLUGINS" | tee -a "$LOG_FILE"
fi

echo "Build finished: $(date "+%Y-%m-%d %H:%M:%S")" | tee -a "$LOG_FILE"
echo "Log file: $LOG_FILE" | tee -a "$LOG_FILE"
echo "========================================" | tee -a "$LOG_FILE"

if [[ $FAILED -eq 0 ]]; then
    echo "" | tee -a "$LOG_FILE"
    echo "Next step: ./copy_to_jniLibs.sh" | tee -a "$LOG_FILE"
    exit 0
else
    exit 1
fi
