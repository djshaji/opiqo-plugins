# Android Integration Guide

Complete walkthrough for integrating the opiqo-plugins theme system into an Android LV2 audio plugin host.

## Overview

The theme system provides:
1. **Java Runtime** (ThemeManager, SkinParser, ColorUtils) - Load and apply themes to views
2. **Python Tooling** (converter, validator) - Generate and validate skin config
3. **JSON Format** - Declarative skin definitions
4. **Example Skins** - Reference implementations

This guide shows how to use all three in a cohesive Android workflow.

## Step 1: Project Setup

### 1.1 Copy Theme System into Android Project

```bash
# From opiqo-plugins root
cp -r theme/ /path/to/android_project/app/src/main/assets/
```

Your assets structure becomes:
```
app/src/main/assets/
├── theme/
│   ├── java/          (Reference - Java source)
│   ├── python/        (Reference - Python tools)
│   ├── examples/      (Reference - Example skins)
│   └── README.md      (Reference - Documentation)
├── skins/             (Generated - Runtime skins)
│   ├── gx_axisface.json
│   ├── gx_crewdriver.json
│   └── ...
└── images/            (Plugin artwork)
    ├── gx_axisface/
    │   ├── pedal_background.png
    │   ├── knob_sprites.png
    │   └── footswitch_sprites.png
    └── ...
```

### 1.2 Add Gradle Dependencies

In `build.gradle` (Module: app):

```gradle
dependencies {
    // Theme system - Gson for JSON parsing
    implementation 'com.google.code.gson:gson:2.10'
    
    // Audio processing (your choice)
    implementation 'org.billthefarmer:opensles-java:1.2.0'
    
    // UI utilities
    implementation 'androidx.appcompat:appcompat:1.6.0'
    implementation 'androidx.constraintlayout:constraintlayout:2.1.4'
}
```

### 1.3 Copy Java Classes into Android Project

```bash
# Create package directory
mkdir -p app/src/main/java/com/opiqo/theme/

# Copy Java classes
cp theme/java/*.java app/src/main/java/com/opiqo/theme/
```

### 1.4 Generate Skins from MOD Platform

From opiqo-plugins root, generate all plugin skins:

```bash
# Create output directory
mkdir -p app/src/main/assets/skins

# Convert all 43 plugins
python3 << 'EOF'
import subprocess
from pathlib import Path

gxplugins = Path("GxPlugins")
python_converter = Path("theme/python/mod_to_android_converter.py")

for plugin_dir in sorted(gxplugins.glob("Gx*.lv2")):
    mod_dir = plugin_dir / "MOD"
    if not mod_dir.exists():
        print(f"⊘ {plugin_dir.name} - No MOD directory")
        continue
    
    plugin_name = plugin_dir.name.replace(".lv2", "")
    output_json = f"app/src/main/assets/skins/{plugin_name.lower()}.json"
    
    try:
        result = subprocess.run(
            ["python3", str(python_converter), str(mod_dir), output_json],
            capture_output=True,
            text=True,
            timeout=10
        )
        if result.returncode == 0:
            print(f"✓ {plugin_name} -> {output_json}")
        else:
            print(f"✗ {plugin_name} - {result.stderr}")
    except Exception as e:
        print(f"✗ {plugin_name} - {e}")
EOF
```

### 1.5 Validate Generated Skins

```bash
python3 theme/python/theme_validator.py \
    --batch app/src/main/assets/skins/
```

Output:
```
Validating skins batch...
✓ gx_axisface.json (3 controls, 6 ports, 3 presets)
✓ gx_blueamp.json (4 controls, 7 ports, 2 presets)
...
Summary: 41/43 valid, 2 with warnings
```

### 1.6 Copy Plugin Assets

Copy MOD GUI artwork to Android assets:

```bash
# Create image directories
mkdir -p app/src/main/assets/images

# Copy all plugin artwork
for plugin_dir in GxPlugins/Gx*.lv2; do
    plugin_name=$(basename "$plugin_dir" | sed 's/.lv2//' | tr '[:upper:]' '[:lower:]')
    mod_dir="$plugin_dir/MOD"
    
    if [[ -d "$mod_dir/modgui" ]]; then
        mkdir -p "app/src/main/assets/images/$plugin_name"
        cp -v "$mod_dir/modgui"/*.png \
            "app/src/main/assets/images/$plugin_name/"
    fi
done
```

## Step 2: Runtime Integration

### 2.1 Initialize ThemeManager

In your main Activity or Application class:

```java
package com.opiqo.app;

import android.app.Application;
import android.content.Context;
import com.opiqo.theme.ThemeManager;

public class AudioPluginApp extends Application {
    private static ThemeManager themeManager;
    
    @Override
    public void onCreate() {
        super.onCreate();
        
        // Initialize theme manager
        themeManager = new ThemeManager(this);
        
        // Preload commonly-used skins
        themeManager.loadSkinAsync("gx_axisface", result -> {
            if (result != null) {
                Log.d("Skin", "GxAxisFace loaded");
            }
        });
    }
    
    public static ThemeManager getThemeManager() {
        return themeManager;
    }
}
```

Register in `AndroidManifest.xml`:

```xml
<application
    android:name="com.opiqo.app.AudioPluginApp"
    ...>
</application>
```

### 2.2 Create Plugin Activity

```java
package com.opiqo.app;

import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import android.widget.LinearLayout;
import android.util.Log;
import com.google.gson.Gson;
import com.opiqo.theme.ThemeManager;
import com.opiqo.theme.SkinParser;
import com.opiqo.theme.SkinParser.PluginSkin;

public class PluginActivity extends AppCompatActivity {
    private static final String TAG = "PluginActivity";
    private ThemeManager themeManager;
    private PluginSkin currentSkin;
    private LinearLayout uiContainer;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Create container
        uiContainer = new LinearLayout(this);
        uiContainer.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT,
            LinearLayout.LayoutParams.MATCH_PARENT
        ));
        setContentView(uiContainer);
        
        // Get theme manager
        themeManager = AudioPluginApp.getThemeManager();
        
        // Load plugin from intent
        String pluginName = getIntent()
            .getStringExtra("plugin_name");
        loadPlugin(pluginName);
    }
    
    private void loadPlugin(String pluginName) {
        // Load skin asynchronously
        themeManager.loadSkinAsync(pluginName, skin -> {
            if (skin != null) {
                currentSkin = skin;
                buildUI();
            } else {
                Log.e(TAG, "Failed to load skin for " + pluginName);
            }
        });
    }
    
    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        
        // Rebuild UI when orientation changes
        if (currentSkin != null) {
            buildUI();
        }
    }
    
    private void buildUI() {
        uiContainer.removeAllViews();
        
        // Get current device metrics
        int screenWidth = getResources().getDisplayMetrics().widthPixels;
        int screenHeight = getResources().getDisplayMetrics().heightPixels;
        int orientation = getResources().getConfiguration().orientation;
        
        // Select dimension variant for current orientation and screen size
        PluginSkin.Dimension dimension = getDimensionForOrientationAndWidth(
            currentSkin, orientation, screenWidth);
        
        Log.d(TAG, "Using dimension: " + dimension.name + 
            " (" + dimension.width + "x" + dimension.height + ")");
        
        // Check if dimension requires 90-degree rotation
        boolean rotateUI = "rotate_90".equals(dimension.scaling) && 
                          Configuration.ORIENTATION_PORTRAIT == orientation;
        
        // Create pedal layout
        LinearLayout pedal = new LinearLayout(this);
        pedal.setLayoutParams(new LinearLayout.LayoutParams(
            dimension.width,
            dimension.height
        ));
        pedal.setBackgroundColor(
            ColorUtils.parseHexColor(
                currentSkin.colors.background.get("default")
            )
        );
        
        // Apply rotation if needed (portrait mode for landscape pedal)
        if (rotateUI) {
            pedal.setRotation(90f);
            // Adjust container to accommodate rotated pedal
            int tempWidth = dimension.height;  // swapped
            int tempHeight = dimension.width;
            LinearLayout.LayoutParams rotatedParams = 
                new LinearLayout.LayoutParams(tempWidth, tempHeight);
            pedal.setLayoutParams(rotatedParams);
        }
        
        // Add controls
        for (PluginSkin.Control control : currentSkin.controls) {
            addControl(pedal, control, rotateUI);
        }
        
        uiContainer.addView(pedal);
    }
    
    private PluginSkin.Dimension getDimensionForOrientationAndWidth(
            PluginSkin skin, int orientation, int screenWidth) {
        
        // Determine orientation suffix
        String orientationSuffix = 
            (orientation == Configuration.ORIENTATION_PORTRAIT) 
            ? "_portrait" 
            : "_landscape";
        
        // Find best matching variant
        PluginSkin.Dimension bestMatch = skin.dimensions.standard;
        
        for (PluginSkin.Dimension variant : skin.dimensions.variants) {
            // Only consider variants matching current orientation
            if (!variant.name.endsWith(orientationSuffix)) {
                continue;
            }
            
            // Check if within breakpoint range
            if (screenWidth >= variant.breakpoint_min && 
                screenWidth <= variant.breakpoint_max) {
                
                // Prefer exact match, fall back to standard
                if (bestMatch == skin.dimensions.standard ||
                    variant.breakpoint_max > bestMatch.breakpoint_max) {
                    bestMatch = variant;
                }
            }
        }
        
        return bestMatch;
    }
    
    private void addControl(LinearLayout parent, 
            PluginSkin.Control control, boolean rotated) {
        
        if ("knob".equals(control.type)) {
            addKnob(parent, control, rotated);
        } else if ("footswitch".equals(control.type)) {
            addFootswitch(parent, control, rotated);
        }
    }
    
    private void addKnob(LinearLayout parent, 
            PluginSkin.Control control, boolean rotated) {
        
        // Create custom KnobView
        KnobView knob = new KnobView(this);
        LinearLayout.LayoutParams params = 
            new LinearLayout.LayoutParams(
                control.size,
                control.size
            );
        
        // Adjust margins if UI is rotated
        int margin_x = control.control_x;
        int margin_y = control.control_y;
        
        if (rotated) {
            // For 90-degree rotation, swap coordinates
            // Original (x,y) becomes (originalHeight - y - size, x)
            // This is handled by the rotation transform on parent
        }
        
        params.leftMargin = margin_x;
        params.topMargin = margin_y;
        knob.setLayoutParams(params);
        
        // Load sprite sheet
        String spritePath = "images/" + currentSkin.plugin_name 
            + "/" + control.sprite_sheet;
        knob.setSprites(
            loadImageFromAssets(spritePath),
            control.sprite_count
        );
        
        // Set value change listener
        int portIndex = control.port_index;
        knob.setOnValueChangeListener(value -> {
            // Update audio engine
            updateAudioParameter(portIndex, value);
        });
        
        parent.addView(knob);
    }
    
    private void addFootswitch(LinearLayout parent, 
            PluginSkin.Control control, boolean rotated) {
        
        FootSwitchView footswitch = new FootSwitchView(this);
        LinearLayout.LayoutParams params = 
            new LinearLayout.LayoutParams(
                control.size,
                control.size
            );
        params.leftMargin = control.control_x;
        params.topMargin = control.control_y;
        footswitch.setLayoutParams(params);
        
        // Load sprites
        String spritePath = "images/" + currentSkin.plugin_name 
            + "/" + control.sprite_sheet;
        footswitch.setSprites(
            loadImageFromAssets(spritePath),
            control.sprite_count
        );
        
        // Toggle on click
        int portIndex = control.port_index;
        footswitch.setOnClickListener(v -> {
            boolean newState = !footswitch.isActive();
            footswitch.setActive(newState);
            updateAudioParameter(portIndex, newState ? 1.0f : 0.0f);
        });
        
        parent.addView(footswitch);
    }
    
    private void updateAudioParameter(int portIndex, float value) {
        // Connect to audio engine
        // nativeSetParameter(portIndex, value);
        Log.d(TAG, "Port " + portIndex + " = " + value);
    }
    
    private Bitmap loadImageFromAssets(String path) {
        try {
            return BitmapFactory.decodeStream(
                getAssets().open(path)
            );
        } catch (IOException e) {
            Log.e(TAG, "Failed to load: " + path, e);
            return null;
        }
    }
}
```

### 2.3 Custom View Classes

Create `KnobView.java`:

```java
package com.opiqo.app.ui;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

public class KnobView extends View {
    private Bitmap spriteSheet;
    private int spriteCount;
    private float value = 0.5f;
    private OnValueChangeListener listener;
    
    public KnobView(Context context) {
        super(context);
    }
    
    public KnobView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }
    
    public void setSprites(Bitmap spriteSheet, int count) {
        this.spriteSheet = spriteSheet;
        this.spriteCount = count;
        invalidate();
    }
    
    public void setValue(float value) {
        this.value = Math.max(0f, Math.min(1f, value));
        invalidate();
    }
    
    public float getValue() {
        return value;
    }
    
    @Override
    protected void onDraw(Canvas canvas) {
        if (spriteSheet == null) return;
        
        // Calculate which sprite frame to show
        int frame = Math.round(value * (spriteCount - 1));
        frame = Math.min(frame, spriteCount - 1);
        
        // Calculate frame dimensions
        int frameWidth = spriteSheet.getWidth() / spriteCount;
        int frameHeight = spriteSheet.getHeight();
        
        // Draw appropriate frame
        canvas.drawBitmap(
            spriteSheet,
            frame * frameWidth,  // source x
            0,                   // source y
            frameWidth,          // source width
            frameHeight,         // source height
            0,                   // dest x
            0,                   // dest y
            getWidth(),          // dest width
            getHeight(),         // dest height
            null
        );
    }
    
    @Override
    public boolean onTouchEvent(MotionEvent event) {
        float touchX = event.getX();
        float touchY = event.getY();
        
        // Convert touch position to value (top = max, bottom = min)
        float newValue = 1f - (touchY / getHeight());
        newValue = Math.max(0f, Math.min(1f, newValue));
        
        if (Math.abs(newValue - value) > 0.01f) {
            setValue(newValue);
            if (listener != null) {
                listener.onValueChanged(value);
            }
        }
        
        return true;
    }
    
    public interface OnValueChangeListener {
        void onValueChanged(float value);
    }
    
    public void setOnValueChangeListener(
            OnValueChangeListener listener) {
        this.listener = listener;
    }
}
```

Create `FootSwitchView.java`:

```java
package com.opiqo.app.ui;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.util.AttributeSet;
import android.view.View;

public class FootSwitchView extends View {
    private Bitmap spriteSheet;
    private boolean active = false;
    
    public FootSwitchView(Context context) {
        super(context);
    }
    
    public FootSwitchView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }
    
    public void setSprites(Bitmap spriteSheet, int count) {
        this.spriteSheet = spriteSheet;
        setOnClickListener(v -> {
            toggle();
        });
    }
    
    public void setActive(boolean active) {
        this.active = active;
        invalidate();
    }
    
    public boolean isActive() {
        return active;
    }
    
    public void toggle() {
        setActive(!active);
    }
    
    @Override
    protected void onDraw(Canvas canvas) {
        if (spriteSheet == null) return;
        
        int frame = active ? 1 : 0;
        int frameWidth = spriteSheet.getWidth() / 2;
        int frameHeight = spriteSheet.getHeight();
        
        canvas.drawBitmap(
            spriteSheet,
            frame * frameWidth, 0,
            frameWidth, frameHeight,
            0, 0,
            getWidth(), getHeight(),
            null
        );
    }
}
```

## Step 3: Advanced Features

### 3.1 Implement Theme Switching

```java
public void applyDarkMode() {
    UserTheme darkTheme = UserTheme.darkMode();
    themeManager.applyCustomTheme(currentSkin, darkTheme);
    buildUI();  // Rebuild with new colors
}

public void applyLightMode() {
    UserTheme lightTheme = UserTheme.lightMode();
    themeManager.applyCustomTheme(currentSkin, lightTheme);
    buildUI();
}
```

### 3.2 Apply Presets

```java
public void applyPreset(String presetName) {
    PluginSkin.Preset preset = currentSkin.getPreset(presetName);
    if (preset != null) {
        // Update all UI controls
        for (String portSymbol : preset.port_values.keySet()) {
            float value = preset.port_values.get(portSymbol);
            updateControlValue(portSymbol, value);
            updateAudioParameter(portSymbol, value);
        }
    }
}
```

### 3.3 Handle Responsive Layout

```java
@Override
public void onConfigurationChanged(Configuration newConfig) {
    super.onConfigurationChanged(newConfig);
    
    // Rebuild UI with new dimensions
    if (currentSkin != null) {
        buildUI();
    }
}
```

## Step 4: Build Automation

### 4.1 Gradle Task for Skin Generation

Create `android_skins.gradle` in `app/`:

```gradle
task generateSkins {
    description = "Generate Android skins from MOD plugins"
    
    doLast {
        def pythonScript = 
            "${project.rootDir}/../opiqo-plugins/theme/python/mod_to_android_converter.py"
        def gxPluginsDir = 
            "${project.rootDir}/../opiqo-plugins/GxPlugins"
        def skinsDir = 
            "${projectDir}/src/main/assets/skins"
        
        file(skinsDir).mkdirs()
        
        file(gxPluginsDir).eachDir { pluginDir ->
            def modDir = new File(pluginDir, "MOD")
            if (modDir.exists()) {
                def pluginName = pluginDir.name
                    .replace(".lv2", "")
                    .toLowerCase()
                def outputJson = 
                    "${skinsDir}/${pluginName}.json"
                
                def cmd = [
                    "python3", pythonScript,
                    modDir.absolutePath,
                    outputJson
                ]
                
                println "Converting ${pluginName}..."
                def process = cmd.execute()
                process.waitFor()
                
                if (process.exitValue() == 0) {
                    println "✓ ${pluginName}"
                } else {
                    println "✗ ${pluginName}"
                }
            }
        }
    }
}

// Run before build
preBuild.dependsOn generateSkins
```

Apply in `build.gradle`:

```gradle
apply from: 'android_skins.gradle'
```

### 4.2 Copy Assets Task

```gradle
task copyPluginAssets {
    description = "Copy plugin PNG assets to Android"
    
    doLast {
        def gxPluginsDir = 
            "${project.rootDir}/../opiqo-plugins/GxPlugins"
        def imagesDir = 
            "${projectDir}/src/main/assets/images"
        
        file(imagesDir).mkdirs()
        
        file(gxPluginsDir).eachDir { pluginDir ->
            def modguiDir = new File(pluginDir, "MOD/modgui")
            if (modguiDir.exists()) {
                def pluginName = pluginDir.name
                    .replace(".lv2", "")
                    .toLowerCase()
                def destDir = 
                    new File(imagesDir, pluginName)
                
                copy {
                    from modguiDir
                    into destDir
                    include "*.png"
                }
            }
        }
    }
}

preBuild.dependsOn copyPluginAssets
```

## Step 5: Manifest Configuration

Complete `AndroidManifest.xml`:

```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="com.opiqo.app">

    <uses-feature
        android:name="android.hardware.audio.low_latency"
        android:required="false" />
    
    <application
        android:name=".AudioPluginApp"
        android:allowBackup="true"
        android:icon="@drawable/icon"
        android:label="@string/app_name"
        android:theme="@style/AppTheme">
        
        <activity
            android:name=".PluginActivity"
            android:screenOrientation="landscape"
            android:exported="true">
            <intent-filter>
                <action android:name="android.intent.action.VIEW" />
                <category android:name="android.intent.category.DEFAULT" />
            </intent-filter>
        </activity>
        
    </application>

    <uses-permission android:name="android.permission.RECORD_AUDIO" />
    <uses-permission 
        android:name="android.permission.ACCESS_SUPERUSER" />

</manifest>
```

## Troubleshooting

### Skin not loading
```bash
# Check if skin file exists
adb shell ls /data/data/com.opiqo.app/assets/skins/

# Validate skin JSON
python3 theme/python/theme_validator.py \
    app/src/main/assets/skins/problematic.json
```

### Image assets not found
```bash
# Check image assets copied correctly
adb shell ls /data/data/com.opiqo.app/assets/images/

# Verify paths in skin.json match actual files
grep "assets/" skins/*.json
```

### Colors not displaying correctly
```java
// Debug color parsing
int color = ColorUtils.parseHexColor("#ff6600");
Log.d("Color", String.format("#%08x", color));

// Check contrast
float contrast = ColorUtils.getContrastRatio(bgColor, fgColor);
Log.d("Contrast", "Ratio: " + contrast);
```

## Performance Optimization

### Cache Skins in Memory
```java
// ThemeManager already caches, but for many plugins:
themeManager.setMaxCacheSize(10);  // Keep 10 skins in memory
```

### Async Loading Best Practices
```java
// Load in background, update UI on main thread
themeManager.loadSkinAsync(pluginName, skin -> {
    runOnUiThread(() -> {
        currentSkin = skin;
        buildUI();
    });
});
```

### Lazy Load Images
```java
// Don't load sprite sheets until control is visible
@Override
protected void onFinishInflate() {
    super.onFinishInflate();
    if (spriteSheet == null) {
        loadSprites();  // Load on demand
    }
}
```

## See Also

- [theme/README.md](../README.md) - Theme system documentation
- [theme/java/README.md](../java/README.md) - Java API reference
- [theme/examples/README.md](../examples/README.md) - Example skin breakdown
