# Theme System Navigation Guide

Complete index to the opiqo-plugins theme system for Android LV2 audio plugins.

## Quick Navigation

### I want to...

**Integrate into my Android app** → [QUICKSTART.md](QUICKSTART.md)
- 5-minute setup guide
- Step-by-step checklist
- Common issues
**Make my horizontal pedal work in portrait mode** → [ORIENTATION_GUIDE.md](ORIENTATION_GUIDE.md)
- Three strategies explained (rotate_90, scale_fit, redesign)
- Recommended approach with full code examples
- Performance considerations and future enhancements
**Understand the architecture** → [theme/README.md](theme/README.md)
- System overview
- Component descriptions
- Workflows and dataflow

**Use the Java API** → [theme/java/README.md](theme/java/README.md)
- ThemeManager, SkinParser, ColorUtils, UserTheme
- Method signatures and examples
- Gradle integration

**Use the Python tools** → [theme/python/README.md](theme/python/README.md)
- MOD to Android converter
- JSON validator
- CLI usage and batch processing

**See a complete example** → [theme/examples/README.md](theme/examples/README.md)
- Full skin.json breakdown
- Control definitions
- Color and layout details
- Reference for creating new skins

**Full Android integration** → [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md)
- Complete PluginActivity.java
- Custom View implementations
- Gradle build tasks
- Performance optimization

**Explore available plugins** → [README.md](README.md)
- Full catalog of 43 plugins
- Categories and descriptions
- Build instructions

---

## Directory Structure

```
opiqo-plugins/
├── README.md                                    ← Project overview & 43 plugins
├── QUICKSTART.md                                ← 5-minute setup guide
├── INTEGRATION_GUIDE.md                         ← Full Android integration
├── THEMENAV.md                                  ← This file
│
├── GxPlugins/                                   ← 43 Guitar Rig clone plugins
│   ├── GxAxisFace.lv2/
│   │   ├── MOD/                                 ← MOD platform config
│   │   │   ├── manifest.ttl
│   │   │   ├── modgui/
│   │   │   │   ├── bground.png                  ← Pedal artwork
│   │   │   │   ├── knobs.png                    ← Knob sprites
│   │   │   │   └── ...
│   │   │   └── stylesheet.css                   ← Layout & colors
│   │   ├── dsp/                                 ← Audio processing
│   │   ├── jni/                                 ← Android JNI bridge
│   │   └── ...
│   └── ... (42 more plugins)
│
└── theme/                                       ← Complete theme system
    ├── README.md                                ← System documentation
    ├── THEMENAV.md                              ← Theme navigation (you are here)
    │
    ├── java/                                    ← Production Java code
    │   ├── README.md                            ← Java API & setup
    │   ├── ThemeManager.java                    ← Main manager (233 lines)
    │   │   • loadSkin()
    │   │   • loadSkinAsync()
    │   │   • applyVariant()
    │   │   • applyCustomTheme()
    │   │   • skinExists()
    │   │   • getAvailableSkins()
    │   │
    │   ├── SkinParser.java                      ← Parsing & validation (380 lines)
    │   │   • parseSkin()
    │   │   • validateSkin()
    │   │   • createMinimalSkin()
    │   │   • mergeSkins()
    │   │
    │   ├── ColorUtils.java                      ← Color manipulation (320 lines)
    │   │   • parseHexColor()
    │   │   • RGB ↔ HSL conversion
    │   │   • lighten(), saturate(), adjustHue()
    │   │   • WCAG contrast checking
    │   │
    │   └── UserTheme.java                       ← Custom themes (110 lines)
    │       • darkMode()
    │       • lightMode()
    │       • clone()
    │
    ├── python/                                  ← Build-time utilities
    │   ├── README.md                            ← Python setup
    │   ├── __init__.py                          ← Package init
    │   │
    │   ├── mod_to_android_converter.py          ← MOD → JSON (400 lines)
    │   │   • extract_plugin_info()
    │   │   • extract_dimensions()
    │   │   • extract_colors()
    │   │   • extract_controls()
    │   │   • extract_ports()
    │   │   Usage: python3 mod_to_android_converter.py <mod_dir> <output.json>
    │   │
    │   └── theme_validator.py                   ← JSON validator (350 lines)
    │       • validateSkin()
    │       • batch validation
    │       • detailed error reporting
    │       Usage: python3 theme_validator.py <skin.json>
    │
    └── examples/                                ← Reference implementations
        ├── README.md                            ← Example breakdown
        │   • Skin structure explanation
        │   • Control definitions
        │   • Creating new skins
        │   • Testing locally
        │
        └── gx_axisface_example.json             ← Complete example skin
            • Full-featured overdrive effect
            • Multiple control types
            • Theme variants
            • Asset definitions
```

---

## Component Overview

### Java Theme System (Runtime)

**ThemeManager** (233 lines)
- Role: Central orchestration
- Responsibilities:
  - Load skin JSON (sync/async)
  - Cache recently-used skins
  - Apply theme variants for responsive layout
  - Manage custom user themes
- Used by: PluginActivity, UI components
- Dependencies: Gson, Android Framework

**SkinParser** (380 lines)
- Role: JSON ↔ Java object conversion
- Responsibilities:
  - Parse skin.json into PluginSkin objects
  - Comprehensive validation (schema + content)
  - Cross-reference checking (controls ↔ ports)
  - Skin merging for theme overrides
- Used by: ThemeManager
- Dependencies: Gson

**ColorUtils** (320 lines)
- Role: Color science and manipulation
- Responsibilities:
  - Parse hex colors (#RRGGBB, #AARRGGBB)
  - RGB ↔ HSL conversion for intuitive adjustments
  - Brightness/saturation/hue modifications
  - WCAG AA/AAA contrast ratio checking
  - Automatic text color selection for accessibility
- Used by: UI rendering, theme application
- Dependencies: Android Framework math

**UserTheme** (110 lines)
- Role: User customization container
- Responsibilities:
  - Hold user color preferences
  - Provide dark/light mode presets
  - Support cloning for safe modifications
- Used by: ThemeManager, preference storage
- Dependencies: None (POJO)

### Python Build Tools (Offline)

**mod_to_android_converter.py** (400 lines)
- Input: MOD platform plugin directory
- Output: Android-compatible skin.json
- Functions:
  - TTL parsing (manifest metadata)
  - CSS parsing (layout & colors)
  - Sprite sheet extraction
  - Port/control definitions
- Usage: `python3 mod_to_android_converter.py <mod_dir> <output.json>`
- Dependencies: Python stdlib only (no pip packages)

**theme_validator.py** (350 lines)
- Input: skin.json files
- Output: Validation report
- Checks:
  - Required fields present
  - Type correctness
  - Cross-reference validity
  - Value ranges
  - Color format
  - Asset paths
- Usage: `python3 theme_validator.py <skin.json>`
- Batch mode: `--batch <directory>`
- Dependencies: Python stdlib only

### Data Format (skin.json)

**Root Level Fields:**
```
plugin_name, plugin_uri, version, category, description, author
dimensions, colors, fonts, layout, controls, ports, presets
theme_overrides, assets, metadata
```

**Key Sections:**

| Section | Purpose | Example |
|---------|---------|---------|
| `dimensions` | Responsive layout breakpoints | standard (280x180), compact (200x140), tablet (400x280) |
| `colors` | Color palette with dark/light variants | background, text, border, accent primary/secondary |
| `fonts` | Typography settings | label (sans-serif, 12pt), value (monospace, 10pt) |
| `layout` | Absolute positioning of UI elements | x/y coords for each control |
| `controls` | Interactive UI elements | knobs, footswitches, sliders |
| `ports` | LV2 audio/control I/O | audio_in, audio_out, control parameters |
| `presets` | Pre-configured parameter sets | "Clean", "Crunch", "High Gain" |
| `theme_overrides` | Dark/light mode variants | color substitutions |
| `assets` | Media file references | PNG sprite sheets, backgrounds |
| `metadata` | Generation info & validation | format version, generation date |

---

## Workflow: From MOD to Android

### Phase 1: Offline Conversion
```
GxAxisFace.lv2/MOD/
├── manifest.ttl          ──┐
├── stylesheet.css        ──┼─→ mod_to_android_converter.py
├── modgui/bground.png    ──┤
└── modgui/*.png          ──┘
                               ↓
                        gx_axisface.json
```

Command:
```bash
python3 theme/python/mod_to_android_converter.py \
    GxPlugins/GxAxisFace.lv2/MOD \
    app/src/main/assets/skins/gx_axisface.json
```

### Phase 2: Validation
```
gx_axisface.json ──→ theme_validator.py
                        ↓
                    ✓ or ✗ detailed report
```

Command:
```bash
python3 theme/python/theme_validator.py \
    app/src/main/assets/skins/gx_axisface.json
```

### Phase 3: Runtime Loading
```
Android Assets
├── skins/gx_axisface.json ──┐
├── images/gx_axisface/*.png ┤
└── ...                       ├──→ ThemeManager.loadSkin()
                              │
GxPlugins Artwork             ↓
└── Copy PNG files  ──────────┘    SkinParser.parseSkin()
                                    ↓
                            PluginSkin object
                                    ↓
                        UI Rendering & Audio DSP
                                    ↓
                            ColorUtils (theming)
                                    ↓
                        Final Android View hierarchy
```

Java Code:
```java
ThemeManager tm = new ThemeManager(context);
tm.loadSkinAsync("gx_axisface", skin -> {
    // Build UI from skin definition
    displayUI(skin);
    // Connect to audio engine
    connectAudioPorts(skin);
});
```

---

## Learning Paths

### Path A: "I want to integrate into my app"
1. Read [QUICKSTART.md](QUICKSTART.md) (5 mins)
2. Run 5-minute setup
3. Refer to [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) for details
4. Copy example code from PluginActivity.java

### Path B: "I want to understand the system"
1. Read [theme/README.md](theme/README.md) - Overview
2. Read [README.md](README.md) - Plugin catalog context
3. Study [theme/examples/README.md](theme/examples/README.md) - Data format
4. Review [theme/java/README.md](theme/java/README.md) - API details
5. Review [theme/python/README.md](theme/python/README.md) - Tool details

### Path C: "I want to create custom skins"
1. Study [theme/examples/gx_axisface_example.json](theme/examples/gx_axisface_example.json)
2. Understand [theme/examples/README.md](theme/examples/README.md) breakdown
3. Use Python converter: `mod_to_android_converter.py`
4. Validate: `theme_validator.py`
5. Test locally with [ThemeManager API](theme/java/README.md)

### Path D: "I want to extend the system"
1. Study Java architecture in [theme/java/README.md](theme/java/README.md)
2. Read skinPython tools in [theme/python/README.md](theme/python/README.md)
3. Review [theme/examples/README.md](theme/examples/README.md) for format
4. Create new `*Utils.java` classes or Python parsers as needed
5. Validate changes with existing tests

---

## Common Tasks and Resources

### Task: "Generate all 43 plugin skins"
→ See [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) → **Step 1.4** → Batch conversion script

### Task: "Validate my skin.json file"
→ Use `theme_validator.py` command in [theme/python/README.md](theme/python/README.md)

### Task: "Load a skin in my Activity"
→ See code examples in [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) → **Step 2.2** → PluginActivity.java

### Task: "Implement dark mode"
→ See [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) → **Step 3.1** → applyDarkMode()

### Task: "Customize colors"
→ Use ColorUtils methods in [theme/java/README.md](theme/java/README.md)

### Task: "Create sprite-based animations"
→ See KnobView/FootSwitchView in [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) → **Step 2.3**

### Task: "Apply presets programmatically"
→ See [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) → **Step 3.2** → applyPreset()

### Task: "Handle horizontal pedal on portrait phone"
→ Read [ORIENTATION_GUIDE.md](ORIENTATION_GUIDE.md) → Compares all 3 strategies with examples
→ Recommended: Use `scaling: rotate_90` in skin variants
→ See [QUICKSTART.md](../QUICKSTART.md#handling-portrait-orientation) → Implementation checklist

---

## File Inventory

### Documentation (Markdown)
| File | Lines | Purpose |
|------|-------|---------|
| [README.md](README.md) | 500+ | Project overview, 43 plugins |
| [QUICKSTART.md](QUICKSTART.md) | 300+ | 5-minute integration guide |
| [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) | 800+ | Complete Android integration |
| [theme/README.md](theme/README.md) | 500+ | Theme system documentation |
| [theme/java/README.md](theme/java/README.md) | 400+ | Java API reference |
| [theme/python/README.md](theme/python/README.md) | 50+ | Python dependencies |
| [theme/examples/README.md](theme/examples/README.md) | 600+ | Example skin breakdown |
| [theme/ORIENTATION_GUIDE.md](ORIENTATION_GUIDE.md) | 300+ | Portrait orientation strategies |

### Code (Java)
| File | Lines | Purpose |
|------|-------|---------|
| [theme/java/ThemeManager.java](theme/java/ThemeManager.java) | 233 | Central orchestration |
| [theme/java/SkinParser.java](theme/java/SkinParser.java) | 380+ | Parse & validate JSON |
| [theme/java/ColorUtils.java](theme/java/ColorUtils.java) | 320+ | Color manipulation |
| [theme/java/UserTheme.java](theme/java/UserTheme.java) | 110+ | Theme customization |

### Tools (Python)
| File | Lines | Purpose |
|------|-------|---------|
| [theme/python/mod_to_android_converter.py](theme/python/mod_to_android_converter.py) | 400+ | MOD → JSON converter |
| [theme/python/theme_validator.py](theme/python/theme_validator.py) | 350+ | JSON validator |

### Examples (Data)
| File | Size | Purpose |
|------|------|---------|
| [theme/examples/gx_axisface_example.json](theme/examples/gx_axisface_example.json) | 5KB | Complete skin reference |

**Total: ~7,500 lines of code, documentation, and tools**

---

## Architecture Diagram

```
┌─────────────────────────────────────────────────────────────┐
│                    Android Application                      │
│                                                              │
│  ┌──────────────────────────────────────────────────────┐  │
│  │              PluginActivity.java                     │  │
│  │  • Load skin from assets                             │  │
│  │  • Create UI from PluginSkin object                  │  │
│  │  • Connect controls to audio engine                  │  │
│  └────────────────┬─────────────────────────────────────┘  │
│                   │                                         │
│                   ↓                                         │
│  ┌──────────────────────────────────────────────────────┐  │
│  │              ThemeManager.java                       │  │
│  │  • loadSkin(String pluginName)                       │  │
│  │  • loadSkinAsync()                                   │  │
│  │  • applyVariant(), applyCustomTheme()               │  │
│  └────────────────┬─────────────────────────────────────┘  │
│                   │                                         │
│          ┌────────┴────────┬──────────────────┐             │
│          ↓                 ↓                  ↓             │
│  ┌─────────────────┐ ┌──────────────┐ ┌────────────────┐  │
│  │ SkinParser.java │ │ColorUtils    │ │ UserTheme.java │  │
│  │ · parseSkin()   │ │· parseHex()  │ │ · darkMode()   │  │
│  │ · validate()    │ │· convert HSL │ │ · lightMode()  │  │
│  └────────┬────────┘ └──────────────┘ │ · customize()  │  │
│           │                            └────────────────┘  │
│           ↓                                                │
│  ┌──────────────────────────────────────────────────────┐  │
│  │        Android Assets (/skins/)                      │  │
│  │  • gx_axisface.json                                  │  │
│  │  • gx_blueamp.json                                   │  │
│  │  • ... (43 total)                                    │  │
│  │                                                       │  │
│  │        Android Assets (/images/)                     │  │
│  │  • gx_axisface/pedal_background.png                  │  │
│  │  • gx_axisface/knob_sprites.png                      │  │
│  │  • ... (PNG files for each plugin)                   │  │
│  └──────────────────────────────────────────────────────┘  │
│                                                              │
│  ┌──────────────────────────────────────────────────────┐  │
│  │   Custom Views (KnobView, FootSwitchView, etc.)     │  │
│  │  • Sprite sheet animation                            │  │
│  │  • Touch interaction                                 │  │
│  │  • Value callbacks to audio engine                   │  │
│  └──────────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────────┘
          ↓
    ┌─────────────────────────────────┐
    │  Native Audio Engine (JNI)       │
    │  • LV2 plugin processing         │
    │  • Parameter updates             │
    │  • Audio I/O callbacks           │
    └─────────────────────────────────┘
          ↓
    ┌─────────────────────────────────┐
    │        Audio Output              │
    │  • Device speakers/headphones    │
    └─────────────────────────────────┘


┌─────────────────────────────────────────────────────────────┐
│           Build-Time Conversion (Python)                   │
│                                                             │
│                 GxPlugins/*/MOD/                           │
│           · manifest.ttl                                   │
│           · stylesheet.css                                 │
│           · modgui/*.png                                   │
│                     │                                      │
│            ┌────────↓────────┐                            │
│            │     converter.py │                            │
│            │ – parse TTL/CSS  │                            │
│            │ – extract colors │                            │
│            │ – extract layout │                            │
│            └────────┬────────┘                            │
│                    │                                       │
│              skins/*.json                                 │
│            (Android skin format)                          │
│                    │                                       │
│            ┌───────↓─────────┐                           │
│            │  validator.py   │                           │
│            │ – validate JSON │                           │
│            │ – check refs    │                           │
│            │ – verify colors │                           │
│            └────────┬────────┘                           │
│                    │                                      │
│            ✓ or ✗ Report                                │
│                                                          │
└──────────────────────────────────────────────────────────┘
```

---

## Key Concepts

### Responsive Design
Multiple dimension variants allow single skin to adapt to phone/tablet:
- **compact**: 200x140  (phones, < 480dp)
- **standard**: 280x180 (default)
- **tablet**: 400x280   (tablets, > 480dp)

### Theme Variants
Dark/light mode via color overrides:
```json
"theme_overrides": {
  "dark": { "colors": { "background": "#0a0a0a" } },
  "light": { "colors": { "background": "#f0f0f0" } }
}
```

### Control Types
- **knob**: Rotary control (60-80px, sprite-animated)
- **footswitch**: Toggle button (40-50px, 2-frame sprite)
- **slider**: Linear control (future)
- **dial**: Rotary variant (future)

### Color Systems
- **Hex**: #RRGGBB, #AARRGGBB for storage
- **RGB**: [R, G, B] for computation
- **HSL**: [H, S, L] for intuitive adjustments
- **WCAG**: Contrast ratios for accessibility

---

## Glossary

| Term | Meaning |
|------|---------|
| Skin | Complete visual definition for one plugin (JSON) |
| Plugin | LV2 audio effect (e.g., GxAxisFace) |
| Control | Interactive UI element (knob, button) |
| Port | LV2 audio or control I/O |
| Preset | Named parameter configuration |
| Variant | Responsive layout variant |
| Sprite | Animation frame in sprite sheet |
| TTL | Turtle RDF format (MOD metadata) |
| Pedal | Visual representation of effect |

---

## Support & Troubleshooting

**Issue: Skin not loading**
→ Check [theme/python/theme_validator.py](theme/python/theme_validator.py) for validation errors

**Issue: Colors look wrong**
→ Review color definitions in [theme/examples/README.md](theme/examples/README.md) → Colors section

**Issue: Images not found**
→ Verify asset copy step in [QUICKSTART.md](QUICKSTART.md) → Step 5

**Issue: Touch not responding**
→ Check KnobView implementation in [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) → Step 2.3

**Issue: Audio parameters not updating**
→ Ensure JNI bridge connects correctly per [INTEGRATION_GUIDE.md](INTEGRATION_GUIDE.md) → Step 5

---

## Contributing

To extend the theme system:

1. Create new Java classes in `theme/java/`
2. Create new Python utilities in `theme/python/`
3. Document in appropriate README.md files
4. Validate with existing tests
5. Update this navigation guide

---

**Last Updated**: January 2024  
**Version**: 1.0  
**Status**: Complete and ready for integration
