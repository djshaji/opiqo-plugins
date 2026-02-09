# Portrait Orientation Guide

How to handle horizontal guitar effect pedals on portrait phone screens.

## The Problem

Most guitar effects pedals are designed **horizontally** (wide × short):
- GxAxisFace: 280×180 pixels
- GxBlueAmp: 300×200 pixels  
- Typical layout: 3-4 knobs arranged left-to-right

On portrait phones (height > width), a 280×180 pedal becomes tiny:
- iPhone SE (375×812): Pedal would be ~100×60 pixels
- Pixel 5 (393×851): Pedal would be ~100×60 pixels
- Unusably small for touch interaction

## Three Solutions

### 1. Rotate 90° (Recommended) ✓

**Best for**: Most 3-4 knob effects

**How it works**:
- Dimensions swapped (280×180 → 180×280)
- Pedal rotated 90° on screen
- Maintains full size and detail

**Skin definition**:
```json
{
  "name": "compact_portrait",
  "width": 140,
  "height": 200,
  "orientation": "portrait",
  "scaling": "rotate_90"
}
```

**Android code**:
```java
private void buildUI() {
    // Dimension variant automatically selected based on orientation
    PluginSkin.Dimension dim = getDimensionForOrientationAndWidth(
        skin, 
        getResources().getConfiguration().orientation,
        screenWidth
    );
    
    // Check if rotation needed
    boolean rotateUI = "rotate_90".equals(dim.scaling);
    
    LinearLayout pedal = new LinearLayout(this);
    if (rotateUI) {
        pedal.setRotation(90f);
    }
    // ... add controls ...
}
```

**Pros**:
- ✓ Full size on screen
- ✓ All details visible
- ✓ Easy to implement (canvas rotation)
- ✓ Works with any number of controls

**Cons**:
- ✗ Rotated UI orientation (controls sideways)
- ✗ Some users might expect vertical layout

**Use for**: Standard guitar effects with 3-4 knobs (Overdrive, Distortion, Fuzz)

---

### 2. Scale to Fit (Less Recommended)

**Best for**: Users who don't mind smaller UI or want native portrait layout

**How it works**:
- Pedal scaled down to fit portrait bounds
- No rotation, maintains normal orientation
- Small but usable on larger screens

**Skin definition**:
```json
{
  "name": "compact_portrait", 
  "width": 240,
  "height": 140,
  "orientation": "portrait",
  "scaling": "scale_fit"
}
```

**Android code**:
```java
// AutoLayout handles scaling
PluginSkin.Dimension dim = getDimensionForOrientationAndWidth(...);

LinearLayout pedal = new LinearLayout(this);
pedal.setLayoutParams(new LinearLayout.LayoutParams(
    dim.width,  // 240px
    dim.height  // 140px
));
```

**Pros**:
- ✓ No rotation, feels natural
- ✓ Native portrait orientation
- ✓ Good for tablets (> 480dp)

**Cons**:
- ✗ Very small on phones (100×60 visible area)
- ✗ Hard to tap individual knobs
- ✗ Users need pinch-to-zoom
- ✗ Audio parameter changes via zoom = poor UX

**Use for**: Only tablets or as fallback

---

### 3. Redesign Layout (Manual Work)

**Best for**: Many controls (5+) or custom effects

**How it works**:
- Create completely new portrait-specific layout
- Arrange controls vertically or in grid
- Custom CSS/positioning work required

**Skin definition**:
```json
{
  "name": "compact_portrait",
  "width": 300,
  "height": 400,
  "orientation": "portrait",
  "layout": {
    // Custom vertical layout
    "controls": [
      { "symbol": "drive", "control_x": 50, "control_y": 50 },
      { "symbol": "tone", "control_x": 150, "control_y": 50 },
      { "symbol": "level", "control_x": 250, "control_y": 50 },
      { "symbol": "bypass", "control_x": 150, "control_y": 150 }
    ]
  }
}
```

**Pros**:
- ✓ Perfect for any layout
- ✓ Fully optimized UX
- ✓ Native portrait feel (not rotated)

**Cons**:
- ✗ Manual design work per plugin
- ✗ 43 plugins × 2 layouts = 86 designs
- ✗ Must match MOD platform CSS changes
- ✗ High maintenance burden

**Use for**: Special cases with many controls only

---

## Recommended Strategy

### For Most Plugins

Use **Option 1 (rotate_90)** because:
- ✓ Works for all 43 plugins automatically
- ✓ No per-plugin design work
- ✓ Full size = better usability
- ✓ Touch interaction remains accurate
- ✓ Easy to implement (Canvas.rotate())

### Implementation Roadmap

1. **Generate base skins** from MOD platform
2. **Add portrait variants** with `scaling: rotate_90`
3. **Enable rotation handling** in AndroidManifest.xml
4. **Test on devices** in both orientations
5. **Optional**: Add scale_fit for tablets if needed

---

## Full Implementation Example

### Step 1: Update Example Skin

```json
{
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
        "orientation": "landscape"
      },
      {
        "name": "compact_portrait",
        "width": 140,
        "height": 200,
        "orientation": "portrait",
        "scaling": "rotate_90"
      }
    ]
  }
}
```

### Step 2: Update PluginActivity

```java
public class PluginActivity extends AppCompatActivity {
    
    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        if (currentSkin != null) {
            buildUI();  // Rebuild with new variant
        }
    }
    
    private void buildUI() {
        uiContainer.removeAllViews();
        
        int orientation = getResources().getConfiguration().orientation;
        int screenWidth = getResources().getDisplayMetrics().widthPixels;
        
        // Auto-select variant based on orientation
        PluginSkin.Dimension dim = getDimensionForOrientationAndWidth(
            currentSkin, orientation, screenWidth);
        
        LinearLayout pedal = new LinearLayout(this);
        pedal.setLayoutParams(new LinearLayout.LayoutParams(
            dim.width, dim.height
        ));
        
        // Apply rotation if variant specifies it
        if ("rotate_90".equals(dim.scaling) && 
            orientation == Configuration.ORIENTATION_PORTRAIT) {
            pedal.setRotation(90f);
        }
        
        // Add controls (coordinates automatically correct for rotation)
        for (PluginSkin.Control control : currentSkin.controls) {
            addControl(pedal, control);
        }
        
        uiContainer.addView(pedal);
    }
}
```

### Step 3: Update AndroidManifest.xml

```xml
<activity android:name=".PluginActivity"
    android:screenOrientation="sensor"
    android:configChanges="orientation|screenSize"
    android:exported="true">
    <intent-filter>
        <action android:name="android.intent.action.VIEW" />
        <category android:name="android.intent.category.DEFAULT" />
    </intent-filter>
</activity>
```

Key attributes:
- `android:screenOrientation="sensor"` - Allow rotation
- `android:configChanges="orientation|screenSize"` - Handle changes in Activity (not destroy/recreate)

### Step 4: Test

```bash
# Generate all skins with portrait variants
python3 theme/python/mod_to_android_converter.py \
    GxPlugins/GxAxisFace.lv2/MOD \
    skins/gx_axisface.json

# Add portrait variant manually or via updated converter
# (Converter can be extended to auto-generate portrait variants)

# Test on device
adb install app-debug.apk
adb shell "start com.opiqo.app/.PluginActivity"

# Rotate phone and observe:
# - Landscape: pedal full width (280×180)
# - Portrait: pedal rotated 90° (180×280)
```

---

## Variant Selection Logic

In `getDimensionForOrientationAndWidth()`:

```
User rotates phone
    ↓
onConfigurationChanged() called
    ↓
Determine orientation (PORTRAIT or LANDSCAPE)
    ↓
Get screen width in dp
    ↓
Find all variants matching orientation
    ↓
Among those, find variant with breakpoint containing screenWidth
    ↓
Return selected Dimension object
    ↓
buildUI() applies Dimension:
    • dim.width/height
    • dim.scaling (rotate_90?) → pedal.setRotation(90f)
    ↓
Pedal renders on screen with correct size & rotation
```

---

## Performance Considerations

### Canvas Rotation
- `View.setRotation()` is GPU-accelerated
- Zero overhead vs drawing rotated bitmap
- Recommended approach

### Avoiding Jank
```java
// ✓ Good: Preload skins before orientation change
themeManager.loadSkinAsync("gx_axisface", skin -> {
    currentSkin = skin;
    // Ready to buildUI() instantly on rotation
});

// ✗ Bad: Load skin during onConfigurationChanged()
@Override
public void onConfigurationChanged(Configuration newConfig) {
    super.onConfigurationChanged(newConfig);
    themeManager.loadSkinAsync("gx_axisface", skin -> {
        // Delays layout by 100-200ms
        buildUI();
    });
}
```

### Touch Coordinate Handling

When pedal is rotated 90°, touch coordinates are automatically adjusted by Android. No additional math needed:

```java
// Touch at (x, y) is still correct
// Android's rotation transform handles the math
pedal.setRotation(90f);  // Canvas handles transformed coordinates

knob.setOnTouchListener((v, event) -> {
    float x = event.getX();  // Already adjusted for rotation
    float y = event.getY();
    // Use x, y directly - no manual rotation math needed
});
```

---

## Future Enhancements

### Auto-Generate Portrait Variants

Update Python converter to automatically create portrait variants:

```python
# In mod_to_android_converter.py
dimensions = {
    "standard": { "width": 280, "height": 180, "orientation": "landscape" },
    "variants": [
        {
            "name": "compact_landscape",
            "width": 200,
            "height": 140,
            "orientation": "landscape"
        },
        {
            # Auto-generated portrait variant
            "name": "compact_portrait",
            "width": 140,  # swapped
            "height": 200,  # swapped
            "orientation": "portrait",
            "scaling": "rotate_90"
        }
    ]
}
```

### Landscape-to-Portrait Redesign Tool

For plugins with many controls (5+), automate vertical layout generation:

```python
# Future: LayoutOptimizer
optimizer = LayoutOptimizer(skin)
portrait_layout = optimizer.generate_vertical_layout()
# Arranges controls in 2-3 columns
```

---

## Summary Table

| Factor | Rotate | Scale | Redesign |
|--------|--------|-------|----------|
| **Complexity** | Easy | Very Easy | Hard |
| **Size on Phone** | Large | Tiny | Medium |
| **Usability** | Good | Poor | Excellent |
| **For 3-4 knobs** | ✓ Best | ✗ | - |
| **For 5+ controls** | OK | ✗ | ✓ Best |
| **Maintenance** | Low | Low | High |
| **Works for all 43** | ✓ Yes | ✓ Yes | ✗ No |

**Bottom line**: Use **rotate_90** for 95% of plugins.

---

## See Also

- [QUICKSTART.md](../QUICKSTART.md#handling-portrait-orientation) - Quick implementation
- [theme/README.md](README.md#responsive-design--orientation) - Design overview  
- [INTEGRATION_GUIDE.md](../INTEGRATION_GUIDE.md#step-2-runtime-integration) - Full Activity code
- [theme/examples/README.md](examples/README.md#dimensions-system) - Example skin variants
