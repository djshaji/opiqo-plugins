# Quick Start Guide

Fast track to integrating opiqo-plugins into your Android audio app.

## 5-Minute Setup

### 1. Copy Theme System
```bash
cp -r theme/ your_android_app/app/src/main/assets/
```

### 2. Add Dependency
In `build.gradle` (app module):
```gradle
implementation 'com.google.code.gson:gson:2.10'
```

### 3. Copy Java Classes
```bash
mkdir -p app/src/main/java/com/opiqo/theme
cp theme/java/*.java app/src/main/java/com/opiqo/theme/
```

### 4. Generate Skins
From opiqo-plugins root:
```bash
mkdir -p ../your_app/app/src/main/assets/skins

python3 theme/python/mod_to_android_converter.py \
    GxPlugins/GxAxisFace.lv2/MOD \
    ../your_app/app/src/main/assets/skins/gx_axisface.json
```

### 5. Copy Images
```bash
mkdir -p ../your_app/app/src/main/assets/images/gx_axisface
cp GxPlugins/GxAxisFace.lv2/MOD/modgui/*.png \
   ../your_app/app/src/main/assets/images/gx_axisface/
```

## Next Steps

### Load Skins in Your Activity
```java
public class PluginActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        ThemeManager tm = new ThemeManager(this);
        tm.loadSkinAsync("gx_axisface", skin -> {
            if (skin != null) {
                displayUI(skin);
            }
        });
    }
}
```

### Create UI from Skin
```java
private void displayUI(PluginSkin skin) {
    LinearLayout container = new LinearLayout(this);
    container.setBackgroundColor(
        ColorUtils.parseHexColor(
            skin.colors.background.get("default")
        )
    );
    
    for (PluginSkin.Control control : skin.controls) {
        if ("knob".equals(control.type)) {
            addKnobView(container, control, skin);
        }
    }
    
    setContentView(container);
}
```

### Add Custom Views
Use the example implementations in [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md):
- `KnobView` - Rotary control with sprite animation
- `FootSwitchView` - Toggle button

## Batch Processing (All 43 Plugins)

### Handling Portrait Orientation

Most guitar effects are designed horizontally. When users rotate their phone to portrait, you have options:

**Option 1: Rotate (Recommended)** ← Easiest
```json
{
  "name": "compact_portrait",
  "width": 140,
  "height": 200,
  "scaling": "rotate_90",
  "orientation": "portrait"
}
```
The pedal appears rotated 90° on screen, maintaining full size/detail.

**Option 2: Scale to Fit** 
```json
{
  "name": "compact_portrait",
  "width": 240,
  "height": 140,
  "scaling": "scale_fit",
  "orientation": "portrait"
}
```
The pedal shrinks to fit portrait bounds (may look tiny on phones).

**Option 3: Redesign Layout**
Create custom portrait layout with controls arranged vertically (manual work).

### Android Handle Orientation Changes

In your `PluginActivity`:

```java
@Override
public void onConfigurationChanged(Configuration newConfig) {
    super.onConfigurationChanged(newConfig);
    if (currentSkin != null) {
        buildUI();  // Auto-selects portrait/landscape variant
    }
}
```

In `AndroidManifest.xml`:
```xml
<activity android:name=".PluginActivity"
    android:screenOrientation="sensor"
    android:configChanges="orientation|screenSize">
</activity>
```

The system automatically picks the right variant:
- Screen < 480dp + portrait → `compact_portrait` (rotate_90)
- Screen < 480dp + landscape → `compact_landscape`
- Screen > 480dp + portrait → `tablet_portrait` (rotate_90)
- Screen > 480dp + landscape → `tablet`

This lets users rotate their phone and the UI adapts automatically.

## Batch Processing (All 43 Plugins)

Run this Python script to convert all plugins:

```python
#!/usr/bin/env python3
import subprocess
from pathlib import Path

converter = Path("theme/python/mod_to_android_converter.py")
output_dir = Path("../android_app/app/src/main/assets/skins")
output_dir.mkdir(parents=True, exist_ok=True)

for plugin_dir in sorted(Path("GxPlugins").glob("Gx*.lv2")):
    mod_dir = plugin_dir / "MOD"
    if not mod_dir.exists():
        continue
    
    plugin_name = plugin_dir.name.replace(".lv2", "").lower()
    output = output_dir / f"{plugin_name}.json"
    
    print(f"Converting {plugin_name}...", end=" ")
    result = subprocess.run(
        ["python3", str(converter), str(mod_dir), str(output)],
        capture_output=True
    )
    print("✓" if result.returncode == 0 else "✗")
```

Save as `convert_all_skins.py` and run:
```bash
python3 convert_all_skins.py
```

## Verify Setup

### Check Skin Files
```bash
ls -la app/src/main/assets/skins/ | wc -l
# Should show ~44 (43 plugins + .)
```

### Validate All Skins
```bash
python3 theme/python/theme_validator.py \
    --batch app/src/main/assets/skins/
```

### Check Images
```bash
ls -d app/src/main/assets/images/gx* | wc -l
# Should show ~43
```

## Complete File Structure

After setup, your app should have:

```
app/src/main/
├── AndroidManifest.xml
├── java/com/opiqo/
│   ├── app/
│   │   ├── AudioPluginApp.java
│   │   ├── PluginActivity.java
│   │   └── ui/
│   │       ├── KnobView.java
│   │       └── FootSwitchView.java
│   └── theme/
│       ├── ThemeManager.java
│       ├── SkinParser.java
│       ├── ColorUtils.java
│       └── UserTheme.java
└── assets/
    ├── theme/
    │   ├── java/
    │   ├── python/
    │   ├── examples/
    │   └── README.md
    ├── skins/
    │   ├── gx_axisface.json
    │   ├── gx_blueamp.json
    │   ├── gx_boobTube.json
    │   └── ... (43 total)
    └── images/
        ├── gx_axisface/
        │   ├── pedal_background.png
        │   ├── knob_sprites.png
        │   └── footswitch_sprites.png
        ├── gx_blueamp/
        │   └── ... (PNG files)
        └── ... (43 plugin directories)
```

## Common Issues

### "skin.json not found"
```bash
# Check if file was generated
ls app/src/main/assets/skins/gx_*.json | head -3

# Check conversion log
python3 theme/python/mod_to_android_converter.py \
    GxPlugins/GxAxisFace.lv2/MOD \
    test_output.json -v
```

### "Image assets not loaded"
```bash
# Copy images directory structure
for plugin in GxPlugins/Gx*.lv2; do
    name=$(basename "$plugin" .lv2 | tr '[:upper:]' '[:lower:]')
    mkdir -p app/src/main/assets/images/$name
    cp $plugin/MOD/modgui/*.png \
       app/src/main/assets/images/$name/ 2>/dev/null
done
```

### "Color parsing error"
```java
// Test color parsing
try {
    int color = ColorUtils.parseHexColor("#ff6600");
    Log.d("Color", "Parsed: " + Integer.toHexString(color));
} catch (IllegalArgumentException e) {
    Log.e("Color", "Invalid value, expected #RRGGBB");
}
```

## Documentation Reference

| Document | Purpose |
|----------|---------|
| [theme/README.md](theme/README.md) | Complete theme system overview |
| [theme/java/README.md](theme/java/README.md) | Java API documentation |
| [theme/python/README.md](theme/python/README.md) | Python tools documentation |
| [theme/examples/README.md](theme/examples/README.md) | Skin format breakdown |
| [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) | Full Android integration |
| [README.md](README.md) | Project overview & 43 plugins |

## Audio Engine Integration

Once UI is loading, connect to your audio processing:

```java
// In KnobView value change listener
knob.setOnValueChangeListener(value -> {
    // Update LV2 control port
    audioEngine.setControlValue(portIndex, value);
});

// In audioThread/AudioRecord callback
private void audioCallback(float[] inputBuffer, float[] outputBuffer) {
    // Process audio with current control values
    nativeLV2Process(inputBuffer, outputBuffer);
}

// JNI declaration
private native void nativeLV2Process(float[] in, float[] out);
```

## Next Level Features

### Dark Mode Support
```java
UserTheme darkMode = UserTheme.darkMode();
themeManager.applyCustomTheme(skin, darkMode);
buildUI();
```

### Apply Presets
```java
PluginSkin.Preset preset = skin.getPreset("High Gain");
for (String port : preset.port_values.keySet()) {
    float value = preset.port_values.get(port);
    updateControl(port, value);
}
```

### Responsive Layouts
```java
int screenWidth = getResources().getDisplayMetrics().widthPixels;
PluginSkin.Dimension dim = skin.getDimensionForWidth(screenWidth);
// UI automatically scales for compact/tablet/desktop
```

## Testing

### Manual Test Single Plugin
```bash
# 1. Convert
python3 theme/python/mod_to_android_converter.py \
    GxPlugins/GxAxisFace.lv2/MOD out.json

# 2. Validate
python3 theme/python/theme_validator.py out.json

# 3. Check contents
cat out.json | python3 -m json.tool | head -50
```

### Unit Test in Android Studio
```java
@Test
public void testSkinLoading() throws IOException {
    String json = readAsset("skins/gx_axisface.json");
    PluginSkin skin = parser.parseSkin(json);
    
    assertNotNull(skin);
    assertEquals("GxAxisFace", skin.plugin_name);
    assertEquals(3, skin.controls.size());
    
    SkinParser.ValidationResult result = 
        parser.validateSkin(skin);
    assertTrue(result.is_valid());
}
```

## Performance Tips

- **Lazy load images**: Load sprite sheets only when control becomes visible
- **Cache skins**: ThemeManager caches up to 10 skins by default
- **Async loading**: Use `loadSkinAsync()` to prevent UI freezing
- **Asset compression**: Convert PNG→WebP for ~30% size reduction

## Getting Help

1. **Check examples**: `theme/examples/gx_axisface_example.json`
2. **Read API docs**: `theme/java/README.md`
3. **Review integration**: `INTEGRATION_GUIDE.md`
4. **Validate skins**: `python3 theme/python/theme_validator.py`

---

**Ready to build?** Start with copying the theme/ folder and follow the 5-minute setup above!
