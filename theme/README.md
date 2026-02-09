# Android Theme System for LV2 Plugins

Complete theme and skin management system for porting GxPlugins to Android. Includes Java classes for UI rendering, Python tools for conversion and validation, and JSON-based skin format for visual consistency.

## Structure

```
theme/
├── java/                           # Java classes for theme management
│   ├── ThemeManager.java          # Theme loading and caching
│   ├── SkinParser.java            # JSON parsing and validation
│   ├── ColorUtils.java            # Color manipulation utilities
│   └── UserTheme.java             # User theme customization
├── python/                         # Python utilities for skin management
│   ├── mod_to_android_converter.py # Convert MOD skins to Android
│   └── theme_validator.py         # Validate skin JSON files
└── README.md                       # This file
```

## Java Classes

### ThemeManager

**Purpose**: Central manager for loading, caching, and applying plugin skins.

**Key Features**:
- Asynchronous and synchronous skin loading
- Automatic caching to improve performance
- Asset path management
- Variant selection based on screen size
- Theme customization support

**Usage Example**:
```java
ThemeManager manager = new ThemeManager(context);

// Load skin synchronously
PluginSkin skin = manager.loadSkin("gx_axisface");

// Load asynchronously
manager.loadSkinAsync("gx_axisface", new ThemeManager.SkinLoadListener() {
    @Override
    public void onSkinLoaded(PluginSkin skin) {
        // Apply skin to UI
    }
    
    @Override
    public void onSkinLoadFailed(String pluginName, Exception e) {
        Log.e("ThemeManager", "Failed to load: " + pluginName);
    }
});

// Apply variant for different screen sizes
PluginSkin variant = manager.applyVariant(skin, "boxy50");

// Apply custom theme
UserTheme customTheme = new UserTheme("#333333", "#FF6200EE");
manager.applyCustomTheme(skin, customTheme);
```

### SkinParser

**Purpose**: Parse, validate, and manipulate skin JSON structures.

**Key Features**:
- Grammar validation against schema
- Content validation (port references, parameter ranges)
- Search operations (getPortBySymbol, getControlBySymbol)
- Skin merging for theme overrides
- Detailed validation results with errors/warnings

**Usage Example**:
```java
SkinParser parser = new SkinParser();

// Parse skin JSON
String skinJson = loadJsonString();
PluginSkin skin = parser.parseSkin(skinJson);

// Validate skin
SkinParser.ValidationResult result = parser.validateSkin(skin);
if (!result.isValid()) {
    for (String error : result.getErrors().values()) {
        Log.e("SkinParser", error);
    }
}

// Find specific port
Port bypass = parser.getPortBySymbol(skin, "BYPASS");
float defaultValue = bypass.getDefault();

// Get default preset
Preset defaultPreset = parser.getDefaultPreset(skin);
for (Map.Entry<String, Float> param : defaultPreset.getParameters().entrySet()) {
    String symbol = param.getKey();
    float value = param.getValue();
}
```

### ColorUtils

**Purpose**: Utilities for color manipulation, validation, and accessibility.

**Key Features**:
- Hex color parsing and conversion
- RGB ↔ HSL color space conversion
- Color adjustments (lighten, darken, saturate, hue rotation)
- Color blending and mixing
- WCAG contrast ratio calculation
- Accessibility checks

**Usage Example**:
```java
// Parse hex color
int color = ColorUtils.parseHexColor("#FF6200EE");

// Adjust brightness
int lighter = ColorUtils.lighten(color, 20);
int darker = ColorUtils.darken(color, 10);

// Color space conversion
float[] hsl = ColorUtils.getHSL(color);
hsl[2] += 10; // Increase lightness
int adjusted = ColorUtils.fromHSL(hsl[0], hsl[1], hsl[2]);

// Blend two colors
int color1 = Color.RED;
int color2 = Color.BLUE;
int blended = ColorUtils.blend(color1, color2, 0.5f);

// Check contrast ratio (for accessibility)
float contrast = ColorUtils.getContrastRatio(textColor, backgroundColor);
if (contrast >= 4.5f) {
    // WCAG AA compliant
}

// Get contrasting text color
int textColor = ColorUtils.getContrastingTextColor(backgroundColor);
```

### UserTheme

**Purpose**: User-customizable theme configuration.

**Key Features**:
- Text color customization
- Accent color customization
- Background color customization
- Dark/light mode presets
- Theme cloning

**Usage Example**:
```java
// Create dark mode theme
UserTheme darkTheme = UserTheme.darkMode();

// Create light mode theme
UserTheme lightTheme = UserTheme.lightMode();

// Custom theme
UserTheme custom = new UserTheme("#1a1a1a", "#FF6200EE");
custom.setBackgroundColor("#FFFFFF");
custom.setDarkMode(false);

// Clone and modify
UserTheme modified = custom.clone();
modified.setAccentColor("#2196F3");
```

## Python Scripts

### mod_to_android_converter.py

**Purpose**: Converts MOD platform plugin configuration to Android skin JSON format.

**Command Line Usage**:
```bash
python3 mod_to_android_converter.py <mod_dir> <output_file>

# Example
python3 mod_to_android_converter.py GxPlugins/GxAxisFace.lv2/MOD skin.json
```

**Extraction**:
- Plugin metadata (name, URI, category, description)
- Visual styles and dimensions from CSS
- Layout positioning and spacing
- Color schemes and fonts
- Control definitions
- Port specifications
- Default preset values

**Output**: JSON file with complete skin configuration ready for Android integration

**Programmatic Usage**:
```python
from mod_to_android_converter import ModToAndroidConverter
from pathlib import Path

converter = ModToAndroidConverter(Path("GxPlugins/GxAxisFace.lv2/MOD"))
if converter.convert():
    converter.save(Path("skin.json"))
    print(f"Plugin: {converter.plugin_name}")
```

### theme_validator.py

**Purpose**: Validates skin JSON files for correctness and completeness.

**Command Line Usage**:
```bash
# Validate single file
python3 theme_validator.py skin.json

# Batch validate directory
python3 theme_validator.py --batch skins/
```

**Validation Checks**:
- JSON syntax validity
- Required fields present
- Field type correctness
- Port/control cross-references
- Parameter value ranges
- Color format validation
- Asset path references

**Output**: Detailed validation report with errors, warnings, and summary

**Programmatic Usage**:
```python
from theme_validator import SkinValidator
from pathlib import Path

validator = SkinValidator()
validator.load_json(Path("skin.json"))
result = validator.validate()

if not result.is_valid():
    for error in result.errors:
        print(f"Error: {error}")
    for warning in result.warnings:
        print(f"Warning: {warning}")

summary = validator.get_summary()
print(f"Plugin: {summary['plugin_name']}")
print(f"Controls: {summary['num_controls']}")
print(f"Ports: {summary['num_ports']}")
```

## Integration Workflow

### 1. Convert MOD Skins

```bash
cd theme/python
python3 mod_to_android_converter.py \
    ../../GxPlugins/GxAxisFace.lv2/MOD \
    output/gx_axisface.json
```

### 2. Validate Generated Skins

```bash
python3 theme_validator.py output/gx_axisface.json
```

### 3. Integrate into Android Project

1. Place skin JSON in `app/src/main/assets/skins/<plugin_name>/skin.json`
2. Copy associated PNG graphics from MOD directory
3. Initialize ThemeManager in Activity/Fragment
4. Load skin and apply to PluginPedalView

### 4. Create Android Activity

```java
public class PluginActivity extends AppCompatActivity {
    private ThemeManager themeManager;
    private PluginPedalView pedalView;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        themeManager = new ThemeManager(this);
        
        // Load skin
        PluginSkin skin = themeManager.loadSkin("gx_axisface");
        
        // Apply custom theme if needed
        UserTheme userTheme = UserTheme.darkMode();
        themeManager.applyCustomTheme(skin, userTheme);
        
        // Create UI
        pedalView = new PluginPedalView(this);
        pedalView.loadSkin(skin);
        
        setContentView(pedalView);
    }
}
```

## Batch Processing All Plugins

### Conversion Script

```bash
#!/bin/bash
# Convert all MOD plugins to Android skins

PYTHON=$(which python3)
CONVERTER="theme/python/mod_to_android_converter.py"
OUTPUT_DIR="output_skins"

mkdir -p "$OUTPUT_DIR"

for plugin_dir in GxPlugins/*.lv2/MOD; do
    if [ -d "$plugin_dir" ]; then
        plugin_name=$(basename $(dirname "$plugin_dir") | sed 's/.lv2//')
        output_file="$OUTPUT_DIR/${plugin_name,,}.json"
        
        echo "Converting $plugin_name..."
        $PYTHON "$CONVERTER" "$plugin_dir" "$output_file"
    fi
done

# Validate all
echo "Validating skins..."
$PYTHON "theme/python/theme_validator.py" --batch "$OUTPUT_DIR"
```

## Gradle Integration

### Build Configuration

Add to `build.gradle`:

```gradle
task convertPluginSkins {
    description 'Convert all MOD plugin skins to Android'
    
    doLast {
        def modDir = file('../GxPlugins')
        def outputDir = file('src/main/assets/skins')
        outputDir.mkdirs()
        
        modDir.listFiles().findAll { 
            it.isDirectory() && it.name.endsWith('.lv2') 
        }.forEach { pluginDir ->
            def modSubdir = new File(pluginDir, 'MOD')
            if (modSubdir.exists()) {
                def pluginName = pluginDir.name.replace('.lv2', '').toLowerCase()
                
                exec {
                    commandLine 'python3', 
                        new File(projectDir, 'theme/python/mod_to_android_converter.py'),
                        modSubdir,
                        new File(outputDir, pluginName + '/skin.json')
                }
                
                copy {
                    from new File(modSubdir, 'modgui')
                    into new File(outputDir, pluginName)
                    include '**/*.png'
                }
                
                println "Converted $pluginName"
            }
        }
    }
}

preBuild.dependsOn convertPluginSkins
```

## Responsive Design & Orientation

Most guitar effect pedals are designed **horizontally** (wide × short). The theme system provides multiple strategies to handle different screen sizes and orientations:

### Layout Variants

Define multiple dimension sizes with orientation hints:

```json
"dimensions": {
  "standard": {
    "width": 280,
    "height": 180,
    "orientation": "landscape"
  },
  "variants": [
    {
      "name": "compact_landscape",
      "width": 200,
      "height": 140,
      "breakpoint_min": 0,
      "breakpoint_max": 480,
      "orientation": "landscape"
    },
    {
      "name": "compact_portrait",
      "width": 140,
      "height": 200,
      "breakpoint_min": 0,
      "breakpoint_max": 480,
      "orientation": "portrait",
      "scaling": "rotate_90"
    }
  ]
}
```

### Handling Portrait Orientation

For horizontal pedals on portrait phones, three strategies:

| Strategy | Example Use | Implementation |
|----------|-------------|-----------------|
| **rotate_90** | 3-4 control pedal in portrait | Dimensions swapped, pedal rotated 90° on screen |
| **scale_fit** | Squeeze to fit | Scale down pedal to fit portrait dimension |
| **redesign** | Many controls (5+) | Create custom vertical layout variant |

**Recommended**: Use `rotate_90` for typical 3-4 knob effects.

### Implementation in Android

The PluginActivity automatically handles orientation changes:

```java
@Override
public void onConfigurationChanged(Configuration newConfig) {
    super.onConfigurationChanged(newConfig);
    
    // Automatically select portrait/landscape variant
    if (currentSkin != null) {
        buildUI();  // Rebuilds with appropriate variant
    }
}
```

ThemeManager selects the right variant based on:
1. Current device orientation (portrait/landscape)
2. Screen width in density-independent pixels (dp)
3. Available dimension variants in skin

### Adding to Manifest

Enable rotation handling in `AndroidManifest.xml`:

```xml
<activity android:name=".PluginActivity"
    android:screenOrientation="sensor"
    android:configChanges="orientation|screenSize">
</activity>
```

## Best Practices

### Skin Management

1. **Cache Skins**: Load frequently used skins once and cache them
2. **Lazy Load**: Use async loading for better UI responsiveness
3. **Validate Early**: Validate skins during build, not at runtime
4. **Version Control**: Track skin JSON versions for updates

### Theme Customization

1. **System Theme**: Detect system dark/light mode preference
2. **User Preferences**: Save user theme choices
3. **Accessibility**: Ensure sufficient color contrast
4. **Performance**: Minimize color calculations in render loop

### Color Selection

1. **Avoid Pure Colors**: Use slightly desaturated colors for softer appearance
2. **Maintain Contrast**: Test colors against backgrounds
3. **Consistent Palette**: Use related hues for unified theme
4. **Test on Devices**: Verify colors on various screen types

## Troubleshooting

### Common Issues

**Skin fails to load**:
- Check file paths (case-sensitive on Linux)
- Verify JSON syntax with `theme_validator.py`
- Ensure all asset files exist

**Colors look wrong**:
- Verify hex format (#RRGGBB or #AARRGGBB)
- Check color contrast ratio
- Test on actual device (not just emulator)

**Layout issues**:
- Validate dimensions against screen density
- Check margin/padding values
- Use variant support for different screen sizes

**Performance problems**:
- Monitor cache size
- Use asynchronous loading
- Profile with Android Profiler

## Dependencies

### Java
- Google Gson (for JSON parsing)
- Android Framework

### Python
- Standard library only (json, pathlib, logging, re)
- No external dependencies!

## License

Part of the Opiqo Plugins project. See main LICENSE file for details.

## Related Documentation

- [Android Skin Format Design](../README.md)
- [GxPlugins MOD Directory Analysis](../../GxPlugins/README.md)
- [Android Integration Guide](../../ANDROID_BUILD.md)
