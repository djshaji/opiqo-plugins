#!/bin/bash
# Copy built .so files from NDK build output to jniLibs directory structure
# This script is typically run after build_android_all.sh succeeds
# Usage: ./copy_to_jniLibs.sh

WORKSPACE=$(cd "$(dirname "$0")" && pwd)
JNILIBS_DIR="$WORKSPACE/jniLibs"
ARCHITECTURES=("armeabi-v7a" "arm64-v8a" "x86" "x86_64")

echo "=========================================="
echo "Copying .so files to jniLibs structure"
echo "=========================================="
echo ""

# Create jniLibs directory structure
echo "Creating directory structure..."
for abi in "${ARCHITECTURES[@]}"; do
    mkdir -p "$JNILIBS_DIR/$abi"
done
echo "Directory structure created in: $JNILIBS_DIR"
echo ""

# Copy .so files
copied=0
for plugin_dir in "$WORKSPACE"/Gx*.lv2; do
    if [[ -d "$plugin_dir/libs" ]]; then
        plugin_name=$(basename "$plugin_dir")
        
        for abi in "${ARCHITECTURES[@]}"; do
            src_dir="$plugin_dir/libs/$abi"
            if [[ -d "$src_dir" ]]; then
                so_files=$(find "$src_dir" -maxdepth 1 -name "*.so" 2>/dev/null)
                
                while IFS= read -r so_file; do
                    if [[ -n "$so_file" ]]; then
                        so_name=$(basename "$so_file")
                        cp "$so_file" "$JNILIBS_DIR/$abi/$so_name"
                        echo "  ✓ $plugin_name/$abi/$so_name"
                        copied=$((copied + 1))
                    fi
                done <<< "$so_files"
            fi
        done
    fi
done

echo ""
echo "=========================================="
echo "Summary"
echo "=========================================="
echo "Total .so files copied: $copied"
echo "Output directory: $JNILIBS_DIR"
echo ""

# Show directory structure
echo "Created structure:"
for abi in "${ARCHITECTURES[@]}"; do
    count=$(find "$JNILIBS_DIR/$abi" -name "*.so" 2>/dev/null | wc -l)
    echo "  $abi/: $count .so files"
done

echo ""
echo "Ready for Android project integration!"
