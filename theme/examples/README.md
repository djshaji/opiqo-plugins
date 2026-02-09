# Theme System - Example Skin Files

This directory contains annotated example skin.json files demonstrating the complete skin format structure.

## Files

### gx_axisface_example.json
Complete example of a fully-featured guitar overdrive effect skin.

**Plugin Details:**
- Name: GxAxisFace
- Category: Overdrive
- Controls: 3 knobs (Drive, Tone, Level) + 1 footswitch (Bypass)
- Audio Ports: Stereo In/Out

**Demonstrates:**
- Multi-dimensional layout system (standard, compact, tablet variants)
- Color theming with dark/light mode support
- Font styling for labels and values
- Knob sprite sheet configuration
- Footswitch button styling
- Control parameter ranges and defaults
- Preset system with 3 example presets
- Asset management with image metadata
- Complete metadata and validation flags

**Usage:**
1. Reference this file as a template for other plugins
2. Use with the theme validator:
   ```bash
   python3 theme/python/theme_validator.py theme/examples/gx_axisface_example.json
   ```
3. Load in ThemeManager:
   ```java
   String exampleJson = readFile("theme/examples/gx_axisface_example.json");
   PluginSkin skin = new SkinParser().parseSkin(exampleJson);
   ```

## Example Structure Breakdown

### Root Level Fields
```json
{
  "plugin_name": "GxAxisFace",           // Plugin identifier
  "plugin_uri": "http://...",            // LV2 plugin URI
  "version": "1.0",                      // Skin version
  "category": "Overdrive",               // Plugin category
  "description": "...",                  // Human-readable description
  "author": "Guitarix Team",             // Creator attribution
  "dimensions": {...},                   // Layout definitions
  "colors": {...},                       // Color palette
  "fonts": {...},                        // Typography settings
  "layout": {...},                       // UI element positioning
  "controls": [...],                     // Interactive controls
  "ports": [...],                        // LV2 audio/control ports
  "presets": [...],                      // Saved parameter combinations
  "theme_overrides": {...},              // Dark/light mode variants
  "assets": {...},                       // Image and media files
  "metadata": {...}                      // Generation and validation info
}
```

### Dimensions System

The example demonstrates **responsive design** through dimensions variants:

```json
"dimensions": {
  "standard": {
    "width": 280,
    "height": 180,
    "unit": "pixels"
  },
  "variants": [
    {
      "name": "compact",
      "width": 200,
      "height": 140,
      "breakpoint_min": 0,
      "breakpoint_max": 480        // For phones < 480dp
    },
    {
      "name": "tablet",
      "width": 400,
      "height": 280,
      "breakpoint_min": 481,
      "breakpoint_max": 1280       // For tablets 481-1280dp
    }
  ]
}
```

**ThemeManager Usage:**
```java
themeManager.applyVariant(skin, "compact");   // Switches to compact layout
```

### Colors

Colors support both **default (dark)** and **light_mode** variants:

```json
"colors": {
  "background": {
    "default": "#1a1a1a",          // Dark mode
    "light_mode": "#e8e8e8"        // Light mode
  },
  "text": {
    "default": "#ffffff",
    "light_mode": "#000000"
  },
  "accent": {
    "primary": "#ff6600",          // Orange
    "secondary": "#ffaa00",        // Light orange
    "highlight": "#ffff00"         // Yellow
  }
}
```

**ColorUtils Integration:**
```java
// Parse colors
int accentColor = ColorUtils.parseHexColor("#ff6600");

// Adjust for light theme
int lightAccent = ColorUtils.lighten(accentColor, 20);

// Check contrast ratio
boolean isAccessible = ColorUtils.getContrastRatio(
    bgColor, textColor
) >= 4.5;  // WCAG AA standard
```

### Layout Positioning

The layout maps visual element positions within the pedal:

```json
"layout": {
  "pedal": {
    "x": 0,
    "y": 0,
    "width": 280,
    "height": 180,
    "image": "pedal_background.png"    // Base artwork
  },
  "controls": [
    {
      "symbol": "drive",              // Control identifier
      "name": "Drive",               // Display label
      "label_x": 50,                 // Label position
      "label_y": 10,
      "control_x": 40,               // Knob position
      "control_y": 50,
      "type": "knob",
      "size": 60                      // Pixel size
    }
  ]
}
```

### Controls (Interactive Elements)

Each control definition:

```json
{
  "symbol": "drive",                 // LV2 port symbol
  "name": "Drive",                   // Human-readable name
  "type": "knob",                    // knob | footswitch | slider
  "port_index": 0,                   // Reference to ports array
  "default_value": 0.5,              // Initial value (0.0-1.0)
  "sprite_sheet": "knob_sprites.png",
  "sprite_count": 64,                // Total animation frames
  "sprite_size": 60                  // Frame dimension in pixels
}
```

**Android Integration:**
```java
KnobView driveKnob = new KnobView(context);
driveKnob.setSprites(spriteSheet, 64);
driveKnob.setValue(skin.getControl("drive").default_value);
driveKnob.setOnValueChangeListener((value) -> {
    // Update DSP parameter
    audioEngine.setParameter(0, value);
});
```

### Ports (LV2 Definition)

Ports define the actual audio/control I/O:

```json
{
  "symbol": "drive",                 // Must match control symbol
  "name": "Drive",
  "port_index": 0,                   // Position in control array
  "type": "control",                 // control | audio
  "flow": "input",                   // input | output
  "minimum": 0.0,
  "maximum": 1.0,
  "default": 0.5,
  "scale_points": [                  // Optional labeled values
    {
      "label": "Off",
      "value": 0.0
    }
  ]
}
```

**Audio Ports:**
```json
{
  "symbol": "audio_in",
  "port_index": 4,
  "type": "audio",
  "flow": "input"
}
```

### Presets

Pre-configured parameter combinations:

```json
{
  "name": "Clean",
  "description": "Minimal overdrive for clean tone",
  "is_default": true,
  "port_values": {
    "drive": 0.2,
    "tone": 0.5,
    "level": 0.7
  }
}
```

**ThemeManager Usage:**
```java
PluginSkin skin = themeManager.loadSkin("GxAxisFace");
PluginSkin.Preset cleanPreset = skin.getPreset("Clean");
engine.applyPreset(cleanPreset.port_values);
```

### Theme Overrides

Define alternative color schemes for dark/light modes:

```json
"theme_overrides": {
  "dark": {
    "colors": {
      "background": "#0a0a0a",       // Even darker
      "text": "#ffffff"
    }
  },
  "light": {
    "colors": {
      "background": "#f0f0f0",       // Very light
      "text": "#000000"
    }
  }
}
```

**Custom Theming Example:**
```java
UserTheme userTheme = UserTheme.darkMode()
    .withAccentColor(ColorUtils.parseHexColor("#00ff00"));
themeManager.applyCustomTheme(skin, userTheme);
```

### Assets

Media file references with metadata:

```json
{
  "name": "pedal_background.png",
  "type": "pedal_base",              // Asset category
  "format": "PNG",
  "path": "assets/gx_axisface/pedal_background.png",
  "width": 280,                      // Optional dimensions
  "height": 180
}
```

## Validation Rules

The example passes all validator checks:

```bash
✓ Required fields present
✓ No type mismatches
✓ All controls referenced in ports
✓ All presets reference valid ports
✓ Color formats valid (#RRGGBB)
✓ Numeric ranges: min < max < value bounds
✓ Asset paths non-empty
✓ At least one port defined
```

## Creating New Skins

1. **Copy the Example:**
   ```bash
   cp theme/examples/gx_axisface_example.json theme/output/new_plugin.json
   ```

2. **Automate with Converter:**
   ```bash
   python3 theme/python/mod_to_android_converter.py \
       GxPlugins/NewPlugin.lv2/MOD \
       theme/output/new_plugin.json
   ```

3. **Validate:**
   ```bash
   python3 theme/python/theme_validator.py theme/output/new_plugin.json
   ```

4. **Deploy to Android:**
   ```bash
   cp theme/output/new_plugin.json app/src/main/assets/skins/
   cp GxPlugins/NewPlugin.lv2/MOD/modgui/* app/src/main/assets/images/
   ```

## Key Differences by Plugin Category

### Overdrive/Distortion
- 3-4 control knobs (Drive, Tone, Level, sometimes Treble)
- Typical range: 0.0-1.0 normalized
- Primary colors: Orange/Red

### Fuzz Effects
- 2-3 knobs (Fuzz, Tone, Volume)
- Often include bias/sustain controls
- Primary colors: Purple/Pink trademarks

### Amplifiers
- 4-6 EQ controls (Bass, Mid, Treble, etc.)
- May include presence, gain stages
- Primary colors: Black with brand colors

### Modulation/Delay
- Time-based parameters (rate, depth)
- Feedback loops (regeneration)
- Blend knob (dry/wet)
- Primary colors: Blue/Cyan

## Testing Skins Locally

Read the example, validate it, then load it programmatically:

```java
// Read example
String json = readAsset("skins/gx_axisface_example.json");

// Parse
PluginSkin skin = parser.parseSkin(json);

// Validate
SkinParser.ValidationResult result = parser.validateSkin(skin);
if (!result.is_valid()) {
    Log.e("Skin", "Validation failed: " + result);
    return;
}

// Display
displaySkinUI(skin);
```

## See Also

- [../java/README.md](../java/README.md) - Java class documentation
- [../python/README.md](../python/README.md) - Python converter tools
- [../README.md](../README.md) - Complete theme system guide
