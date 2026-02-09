#!/usr/bin/env python3
"""Reorganize Android.mk files into jni/ directories for proper NDK structure"""

import os
import shutil

workspace = "/home/djshaji/projects/opiqo-plugins/GxPlugins.lv2"

for plugin in os.listdir(workspace):
    plugin_path = os.path.join(workspace, plugin)
    
    if not plugin.endswith(".lv2") or not os.path.isdir(plugin_path):
        continue
    
    android_mk = os.path.join(plugin_path, "Android.mk")
    if not os.path.exists(android_mk):
        continue
    
    # Create jni directory
    jni_dir = os.path.join(plugin_path, "jni")
    os.makedirs(jni_dir, exist_ok=True)
    
    # Move Android.mk to jni/
    jni_android_mk = os.path.join(jni_dir, "Android.mk")
    if os.path.exists(android_mk) and not os.path.exists(jni_android_mk):
        shutil.move(android_mk, jni_android_mk)
        print(f"✓ {plugin}: Moved Android.mk to jni/")
    elif os.path.exists(jni_android_mk):
        os.remove(android_mk)
        print(f"✓ {plugin}: Android.mk already in jni/")

print("\nReorganization complete!")
