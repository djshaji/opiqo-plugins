# Android Skin Format Design for LV2 Plugins

## Overview

A JSON-based skin format that converts MOD platform's HTML/CSS styling to Android-native UI components, preserving the visual design while enabling native performance.

## Design Goals

1. **Preserve Visual Fidelity**: Maintain the look and feel from MOD platform
2. **Native Performance**: Use Android Views, not WebView
3. **Declarative Format**: JSON schema for easy parsing and tooling
4. **Asset Reuse**: Leverage existing PNG graphics (knobs, pedals)
5. **Flexibility**: Support multiple pedal styles (boxy, compact, etc.)
6. **Extensibility**: Easy to add new plugins and variants

## JSON Skin Format Schema

### Complete Example: GxAxisFace

```json
{
  "skin": {
    "version": "1.0",
    "plugin": {
      "uri": "http://guitarix.sourceforge.net/plugins/gx_AxisFace_#_AxisFace_",
      "name": "GxAxisFace",
      "brand": "Guitarix",
      "category": "Distortion",
      "description": "Simulation of the Axis Face Silicon. The controls are Level (volume), Attack (Fuzz), and Smooth (refines the fuzziness)."
    },
    "visual": {
      "style": "boxy",
      "variant": "standard",
      "colorScheme": "axisface",
      "dimensions": {
        "width": 230,
        "height": 431,
        "unit": "dp"
      },
      "variants": {
        "standard": {"width": 230, "height": 431},
        "boxy50": {"width": 301, "height": 315},
        "boxy75": {"width": 326, "height": 431},
        "boxy85": {"width": 364, "height": 431},
        "boxy100": {"width": 421, "height": 431}
      }
    },
    "assets": {
      "background": "pedals/boxy/axisface.png",
      "footswitch": "pedals/footswitch.png",
      "knobStyle": "cairo",
      "knobGraphic": "knobs/boxy/cairo.png",
      "screenshot": "screenshot-gxaxisface.png",
      "thumbnail": "thumbnail-gxaxisface.png"
    },
    "theme": {
      "textColor": "#000000",
      "brandBorderColor": "#000000",
      "brandBorderWidth": 4,
      "brandBorderRadius": 12,
      "backgroundColor": "transparent",
      "fonts": {
        "brand": {
          "family": "Nexa",
          "fallback": "sans-serif-condensed",
          "size": 32,
          "weight": "bold",
          "textTransform": "uppercase"
        },
        "pluginName": {
          "family": "Questrial",
          "fallback": "sans-serif-light",
          "size": 21,
          "weight": "normal",
          "textTransform": "none"
        },
        "knobLabel": {
          "family": "system",
          "fallback": "sans-serif",
          "size": 11,
          "weight": "bold",
          "textTransform": "uppercase"
        }
      }
    },
    "layout": {
      "brand": {
        "x": 0,
        "y": 160,
        "width": "match_parent",
        "height": "wrap_content",
        "gravity": "center_horizontal",
        "padding": {"left": 30, "right": 30, "top": 3, "bottom": 0}
      },
      "pluginName": {
        "x": 30,
        "y": 340,
        "width": "match_parent",
        "height": "wrap_content",
        "gravity": "center_horizontal",
        "marginLeft": 30,
        "marginRight": 30
      },
      "bypassLed": {
        "x": 10,
        "y": 235,
        "width": "match_parent",
        "height": 32,
        "gravity": "center_horizontal",
        "marginLeft": 10,
        "marginRight": 10
      },
      "footswitch": {
        "x": "center",
        "y": 336,
        "width": 66,
        "height": 66,
        "gravity": "center",
        "clickable": true,
        "stateful": true
      },
      "controlGroup": {
        "x": 20,
        "y": 20,
        "width": "match_parent",
        "height": "wrap_content",
        "gravity": "center_horizontal",
        "layout": "horizontal",
        "spacing": 10,
        "margin": 20
      }
    },
    "controls": [
      {
        "index": 0,
        "symbol": "SMOOTH",
        "name": "SMOOTH",
        "type": "knob",
        "position": "left",
        "knob": {
          "width": 60,
          "height": 60,
          "frames": 64,
          "frameHeight": 60,
          "spriteSheet": "knobs/boxy/cairo.png",
          "rotationMode": "sprite"
        },
        "label": {
          "text": "SMOOTH",
          "position": "bottom",
          "offsetY": 0
        }
      },
      {
        "index": 1,
        "symbol": "ATTACK",
        "name": "ATTACK",
        "type": "knob",
        "position": "center",
        "knob": {
          "width": 60,
          "height": 60,
          "frames": 64,
          "frameHeight": 60,
          "spriteSheet": "knobs/boxy/cairo.png",
          "rotationMode": "sprite"
        },
        "label": {
          "text": "ATTACK",
          "position": "bottom",
          "offsetY": 0
        }
      },
      {
        "index": 2,
        "symbol": "VOLUME",
        "name": "VOLUME",
        "type": "knob",
        "position": "right",
        "knob": {
          "width": 60,
          "height": 60,
          "frames": 64,
          "frameHeight": 60,
          "spriteSheet": "knobs/boxy/cairo.png",
          "rotationMode": "sprite"
        },
        "label": {
          "text": "VOLUME",
          "position": "bottom",
          "offsetY": 0
        }
      }
    ],
    "ports": [
      {
        "index": 0,
        "symbol": "out",
        "name": "Out",
        "type": "audio",
        "direction": "output"
      },
      {
        "index": 1,
        "symbol": "in",
        "name": "In",
        "type": "audio",
        "direction": "input"
      },
      {
        "index": 2,
        "symbol": "BYPASS",
        "name": "BYPASS",
        "type": "control",
        "direction": "input",
        "default": 1.0,
        "minimum": 0.0,
        "maximum": 1.0,
        "integer": true,
        "designation": "bypass"
      },
      {
        "index": 3,
        "symbol": "ATTACK",
        "name": "ATTACK",
        "type": "control",
        "direction": "input",
        "default": 0.5,
        "minimum": 0.0,
        "maximum": 1.0,
        "unit": "normalized"
      },
      {
        "index": 4,
        "symbol": "SMOOTH",
        "name": "SMOOTH",
        "type": "control",
        "direction": "input",
        "default": 0.5,
        "minimum": 0.0,
        "maximum": 1.0,
        "unit": "normalized"
      },
      {
        "index": 5,
        "symbol": "VOLUME",
        "name": "VOLUME",
        "type": "control",
        "direction": "input",
        "default": 0.5,
        "minimum": 0.0,
        "maximum": 1.0,
        "unit": "normalized"
      }
    ],
    "presets": [
      {
        "name": "Default",
        "default": true,
        "parameters": {
          "ATTACK": 0.5,
          "BYPASS": 1.0,
          "SMOOTH": 0.5,
          "VOLUME": 0.5
        }
      }
    ]
  }
}
```

## Android Implementation

### 1. View Architecture

```java
// Custom view that renders the plugin UI
public class PluginPedalView extends FrameLayout {
    private PluginSkin skin;
    private final Map<String, KnobView> knobViews = new HashMap<>();
    private FootswitchView footswitchView;
    private LedIndicatorView bypassLedView;
    
    private OnBypassChangedListener onBypassChanged;
    private OnParameterChangedListener onParameterChanged;
    
    public interface OnBypassChangedListener {
        void onBypassChanged(boolean bypassed);
    }
    
    public interface OnParameterChangedListener {
        void onParameterChanged(String symbol, float value);
    }
    
    public PluginPedalView(Context context) {
        super(context);
    }
    
    public PluginPedalView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }
    
    public void loadSkin(String skinJson) {
        skin = PluginSkin.fromJson(skinJson);
        buildUI();
    }
    
    private void buildUI() {
        if (skin == null) return;
        
        // Set background
        setBackgroundFromAsset(skin.getAssets().getBackground());
        
        // Add brand label
        addBrandLabel(skin);
        
        // Add plugin name label
        addPluginNameLabel(skin);
        
        // Add bypass LED
        bypassLedView = new LedIndicatorView(getContext());
        FrameLayout.LayoutParams ledParams = skin.getLayout().getBypassLed().toLayoutParams();
        addView(bypassLedView, ledParams);
        
        // Add control group
        LinearLayout controlGroup = new LinearLayout(getContext());
        controlGroup.setOrientation(LinearLayout.HORIZONTAL);
        controlGroup.setGravity(Gravity.CENTER_HORIZONTAL);
        
        for (Control control : skin.getControls()) {
            KnobView knobView = new KnobView(getContext());
            knobView.loadSpriteSheet(control.getKnob().getSpriteSheet());
            knobView.setFrameCount(control.getKnob().getFrames());
            knobView.setLabel(control.getLabel().getText());
            Port port = skin.getPort(control.getSymbol());
            knobView.setValueRange(port.getMinimum(), port.getMaximum());
            knobView.setValue(port.getDefault());
            
            knobViews.put(control.getSymbol(), knobView);
            controlGroup.addView(knobView);
        }
        
        FrameLayout.LayoutParams controlParams = skin.getLayout().getControlGroup().toLayoutParams();
        addView(controlGroup, controlParams);
        
        // Add footswitch
        footswitchView = new FootswitchView(getContext());
        footswitchView.loadGraphic(skin.getAssets().getFootswitch());
        footswitchView.setOnClickListener(v -> toggleBypass());
        
        FrameLayout.LayoutParams switchParams = skin.getLayout().getFootswitch().toLayoutParams();
        addView(footswitchView, switchParams);
    }
    
    public void setParameterValue(String symbol, float value) {
        KnobView knob = knobViews.get(symbol);
        if (knob != null) {
            knob.setValue(value);
        }
    }
    
    public Float getParameterValue(String symbol) {
        KnobView knob = knobViews.get(symbol);
        return knob != null ? knob.getValue() : null;
    }
    
    private void toggleBypass() {
        boolean newState = !footswitchView.isActive();
        footswitchView.setActive(newState);
        bypassLedView.setOn(newState);
        
        if (onBypassChanged != null) {
            onBypassChanged.onBypassChanged(newState);
        }
    }
    
    public void setOnBypassChangedListener(OnBypassChangedListener listener) {
        this.onBypassChanged = listener;
    }
    
    public void setOnParameterChangedListener(OnParameterChangedListener listener) {
        this.onParameterChanged = listener;
    }
}
```

### 2. Custom UI Components

```java
// Knob view with sprite-based rotation
public class KnobView extends View {
    private Bitmap spriteSheet;
    private int frameCount = 64;
    private int currentFrame = 0;
    private float minValue = 0f;
    private float maxValue = 1f;
    private float currentValue = 0.5f;
    private String label = "";
    
    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint textPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    
    private OnValueChangedListener onValueChanged;
    
    public interface OnValueChangedListener {
        void onValueChanged(float value);
    }
    
    public KnobView(Context context) {
        super(context);
        initPaint();
    }
    
    public KnobView(Context context, AttributeSet attrs) {
        super(context, attrs);
        initPaint();
    }
    
    private void initPaint() {
        textPaint.setTextAlign(Paint.Align.CENTER);
        textPaint.setTextSize(11 * getContext().getResources().getDisplayMetrics().density);
        textPaint.setTypeface(Typeface.DEFAULT_BOLD);
    }
    
    public void loadSpriteSheet(String assetPath) {
        spriteSheet = loadBitmapFromAssets(assetPath);
        invalidate();
    }
    
    public void setFrameCount(int count) {
        frameCount = count;
    }
    
    public void setLabel(String label) {
        this.label = label;
    }
    
    public void setValueRange(float min, float max) {
        minValue = min;
        maxValue = max;
    }
    
    public void setValue(float value) {
        currentValue = Math.max(minValue, Math.min(maxValue, value));
        currentFrame = (int) (((currentValue - minValue) / (maxValue - minValue)) * (frameCount - 1));
        invalidate();
    }
    
    public float getValue() {
        return currentValue;
    }
    
    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        
        if (spriteSheet != null) {
            int frameHeight = spriteSheet.getHeight() / frameCount;
            Rect srcRect = new Rect(
                0, 
                currentFrame * frameHeight, 
                spriteSheet.getWidth(), 
                (currentFrame + 1) * frameHeight
            );
            Rect dstRect = new Rect(0, 0, getWidth(), getWidth());
            canvas.drawBitmap(spriteSheet, srcRect, dstRect, paint);
        }
        
        // Draw label below knob
        float density = getContext().getResources().getDisplayMetrics().density;
        canvas.drawText(label, getWidth() / 2f, getHeight() - 5 * density, textPaint);
    }
    
    @Override
    public boolean onTouchEvent(MotionEvent event) {
        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_MOVE:
                // Calculate new value based on vertical drag
                float deltaY = event.getY() - (getHeight() / 2f);
                float newValue = currentValue - (deltaY / getHeight()) * (maxValue - minValue);
                setValue(newValue);
                
                if (onValueChanged != null) {
                    onValueChanged.onValueChanged(currentValue);
                }
                return true;
        }
        return super.onTouchEvent(event);
    }
    
    public void setOnValueChangedListener(OnValueChangedListener listener) {
        this.onValueChanged = listener;
    }
}

// Footswitch with on/off states
public class FootswitchView extends ImageView {
    private boolean isActive = true;
    private Bitmap onBitmap;
    private Bitmap offBitmap;
    
    public FootswitchView(Context context) {
        super(context);
    }
    
    public FootswitchView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }
    
    public void loadGraphic(String assetPath) {
        // Footswitch sprite has 2 frames (132px tall, 66px per frame)
        Bitmap sprite = loadBitmapFromAssets(assetPath);
        offBitmap = Bitmap.createBitmap(sprite, 0, 0, sprite.getWidth(), sprite.getHeight() / 2);
        onBitmap = Bitmap.createBitmap(
            sprite, 0, sprite.getHeight() / 2, 
            sprite.getWidth(), sprite.getHeight() / 2
        );
        updateState();
    }
    
    private void updateState() {
        setImageBitmap(isActive ? onBitmap : offBitmap);
    }
    
    public boolean isActive() {
        return isActive;
    }
    
    public void setActive(boolean active) {
        isActive = active;
        updateState();
    }
}

// LED indicator for bypass state
public class LedIndicatorView extends View {
    private boolean isOn = true;
    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
    
    public LedIndicatorView(Context context) {
        super(context);
        paint.setStyle(Paint.Style.FILL);
    }
    
    public LedIndicatorView(Context context, AttributeSet attrs) {
        super(context, attrs);
        paint.setStyle(Paint.Style.FILL);
    }
    
    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        
        paint.setColor(isOn ? Color.parseColor("#00FF00") : Color.parseColor("#333333"));
        
        float radius = getHeight() / 2f;
        canvas.drawCircle(getWidth() / 2f, getHeight() / 2f, radius, paint);
    }
    
    public boolean isOn() {
        return isOn;
    }
    
    public void setOn(boolean on) {
        isOn = on;
        invalidate();
    }
}
```

### 3. Skin Data Classes

```java
public class PluginSkin {
    private String version;
    private PluginInfo plugin;
    private VisualStyle visual;
    private AssetPaths assets;
    private Theme theme;
    private Layout layout;
    private List<Control> controls;
    private List<Port> ports;
    private List<Preset> presets;
    
    public static PluginSkin fromJson(String json) {
        return new Gson().fromJson(json, PluginSkin.class);
    }
    
    public Port getPort(String symbol) {
        for (Port port : ports) {
            if (port.getSymbol().equals(symbol)) {
                return port;
            }
        }
        throw new IllegalArgumentException("Port not found: " + symbol);
    }
    
    // Getters and Setters
    public String getVersion() { return version; }
    public void setVersion(String version) { this.version = version; }
    
    public PluginInfo getPlugin() { return plugin; }
    public void setPlugin(PluginInfo plugin) { this.plugin = plugin; }
    
    public VisualStyle getVisual() { return visual; }
    public void setVisual(VisualStyle visual) { this.visual = visual; }
    
    public AssetPaths getAssets() { return assets; }
    public void setAssets(AssetPaths assets) { this.assets = assets; }
    
    public Theme getTheme() { return theme; }
    public void setTheme(Theme theme) { this.theme = theme; }
    
    public Layout getLayout() { return layout; }
    public void setLayout(Layout layout) { this.layout = layout; }
    
    public List<Control> getControls() { return controls; }
    public void setControls(List<Control> controls) { this.controls = controls; }
    
    public List<Port> getPorts() { return ports; }
    public void setPorts(List<Port> ports) { this.ports = ports; }
    
    public List<Preset> getPresets() { return presets; }
    public void setPresets(List<Preset> presets) { this.presets = presets; }
}

public class PluginInfo {
    private String uri;
    private String name;
    private String brand;
    private String category;
    private String description;
    
    // Getters and Setters
    public String getUri() { return uri; }
    public void setUri(String uri) { this.uri = uri; }
    
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    
    public String getBrand() { return brand; }
    public void setBrand(String brand) { this.brand = brand; }
    
    public String getCategory() { return category; }
    public void setCategory(String category) { this.category = category; }
    
    public String getDescription() { return description; }
    public void setDescription(String description) { this.description = description; }
}

public class VisualStyle {
    private String style;
    private String variant;
    private String colorScheme;
    private Dimensions dimensions;
    private Map<String, Dimensions> variants;
    
    // Getters and Setters
    public String getStyle() { return style; }
    public void setStyle(String style) { this.style = style; }
    
    public String getVariant() { return variant; }
    public void setVariant(String variant) { this.variant = variant; }
    
    public String getColorScheme() { return colorScheme; }
    public void setColorScheme(String colorScheme) { this.colorScheme = colorScheme; }
    
    public Dimensions getDimensions() { return dimensions; }
    public void setDimensions(Dimensions dimensions) { this.dimensions = dimensions; }
    
    public Map<String, Dimensions> getVariants() { return variants; }
    public void setVariants(Map<String, Dimensions> variants) { this.variants = variants; }
}

public class Dimensions {
    private int width;
    private int height;
    private String unit = "dp";
    
    // Getters and Setters
    public int getWidth() { return width; }
    public void setWidth(int width) { this.width = width; }
    
    public int getHeight() { return height; }
    public void setHeight(int height) { this.height = height; }
    
    public String getUnit() { return unit; }
    public void setUnit(String unit) { this.unit = unit; }
}

public class AssetPaths {
    private String background;
    private String footswitch;
    private String knobStyle;
    private String knobGraphic;
    private String screenshot;
    private String thumbnail;
    
    // Getters and Setters
    public String getBackground() { return background; }
    public void setBackground(String background) { this.background = background; }
    
    public String getFootswitch() { return footswitch; }
    public void setFootswitch(String footswitch) { this.footswitch = footswitch; }
    
    public String getKnobStyle() { return knobStyle; }
    public void setKnobStyle(String knobStyle) { this.knobStyle = knobStyle; }
    
    public String getKnobGraphic() { return knobGraphic; }
    public void setKnobGraphic(String knobGraphic) { this.knobGraphic = knobGraphic; }
    
    public String getScreenshot() { return screenshot; }
    public void setScreenshot(String screenshot) { this.screenshot = screenshot; }
    
    public String getThumbnail() { return thumbnail; }
    public void setThumbnail(String thumbnail) { this.thumbnail = thumbnail; }
}

public class Theme {
    private String textColor;
    private String brandBorderColor;
    private int brandBorderWidth;
    private int brandBorderRadius;
    private String backgroundColor;
    private Map<String, FontStyle> fonts;
    
    // Getters and Setters
    public String getTextColor() { return textColor; }
    public void setTextColor(String textColor) { this.textColor = textColor; }
    
    public String getBrandBorderColor() { return brandBorderColor; }
    public void setBrandBorderColor(String brandBorderColor) { this.brandBorderColor = brandBorderColor; }
    
    public int getBrandBorderWidth() { return brandBorderWidth; }
    public void setBrandBorderWidth(int brandBorderWidth) { this.brandBorderWidth = brandBorderWidth; }
    
    public int getBrandBorderRadius() { return brandBorderRadius; }
    public void setBrandBorderRadius(int brandBorderRadius) { this.brandBorderRadius = brandBorderRadius; }
    
    public String getBackgroundColor() { return backgroundColor; }
    public void setBackgroundColor(String backgroundColor) { this.backgroundColor = backgroundColor; }
    
    public Map<String, FontStyle> getFonts() { return fonts; }
    public void setFonts(Map<String, FontStyle> fonts) { this.fonts = fonts; }
}

public class FontStyle {
    private String family;
    private String fallback;
    private int size;
    private String weight;
    private String textTransform;
    
    // Getters and Setters
    public String getFamily() { return family; }
    public void setFamily(String family) { this.family = family; }
    
    public String getFallback() { return fallback; }
    public void setFallback(String fallback) { this.fallback = fallback; }
    
    public int getSize() { return size; }
    public void setSize(int size) { this.size = size; }
    
    public String getWeight() { return weight; }
    public void setWeight(String weight) { this.weight = weight; }
    
    public String getTextTransform() { return textTransform; }
    public void setTextTransform(String textTransform) { this.textTransform = textTransform; }
}

public class Layout {
    private LayoutElement brand;
    private LayoutElement pluginName;
    private LayoutElement bypassLed;
    private LayoutElement footswitch;
    private LayoutElement controlGroup;
    
    // Getters and Setters
    public LayoutElement getBrand() { return brand; }
    public void setBrand(LayoutElement brand) { this.brand = brand; }
    
    public LayoutElement getPluginName() { return pluginName; }
    public void setPluginName(LayoutElement pluginName) { this.pluginName = pluginName; }
    
    public LayoutElement getBypassLed() { return bypassLed; }
    public void setBypassLed(LayoutElement bypassLed) { this.bypassLed = bypassLed; }
    
    public LayoutElement getFootswitch() { return footswitch; }
    public void setFootswitch(LayoutElement footswitch) { this.footswitch = footswitch; }
    
    public LayoutElement getControlGroup() { return controlGroup; }
    public void setControlGroup(LayoutElement controlGroup) { this.controlGroup = controlGroup; }
}

public class LayoutElement {
    private Object x; // Can be Integer or "center"
    private int y;
    private String width; // "match_parent", "wrap_content", or Int
    private String height;
    private String gravity;
    private Padding padding;
    private Integer marginLeft;
    private Integer marginRight;
    private Boolean clickable;
    private Boolean stateful;
    private String layout;
    private Integer spacing;
    private Integer margin;
    
    public FrameLayout.LayoutParams toLayoutParams() {
        int widthValue = "match_parent".equals(width) ? 
            ViewGroup.LayoutParams.MATCH_PARENT : ViewGroup.LayoutParams.WRAP_CONTENT;
        int heightValue = "match_parent".equals(height) ? 
            ViewGroup.LayoutParams.MATCH_PARENT : ViewGroup.LayoutParams.WRAP_CONTENT;
        
        FrameLayout.LayoutParams params = new FrameLayout.LayoutParams(widthValue, heightValue);
        
        // Set margins
        float density = Resources.getSystem().getDisplayMetrics().density;
        if (marginLeft != null) params.leftMargin = (int) (marginLeft * density);
        if (marginRight != null) params.rightMargin = (int) (marginRight * density);
        if (margin != null) {
            int marginPixels = (int) (margin * density);
            params.setMargins(marginPixels, marginPixels, marginPixels, marginPixels);
        }
        
        // Set gravity
        if (gravity != null) {
            params.gravity = parseGravity(gravity);
        }
        
        return params;
    }
    
    private static int parseGravity(String gravity) {
        switch (gravity) {
            case "center": return Gravity.CENTER;
            case "center_horizontal": return Gravity.CENTER_HORIZONTAL;
            case "center_vertical": return Gravity.CENTER_VERTICAL;
            case "top": return Gravity.TOP;
            case "bottom": return Gravity.BOTTOM;
            case "left": return Gravity.LEFT;
            case "right": return Gravity.RIGHT;
            default: return Gravity.NO_GRAVITY;
        }
    }
    
    // Getters and Setters
    public Object getX() { return x; }
    public void setX(Object x) { this.x = x; }
    
    public int getY() { return y; }
    public void setY(int y) { this.y = y; }
    
    public String getWidth() { return width; }
    public void setWidth(String width) { this.width = width; }
    
    public String getHeight() { return height; }
    public void setHeight(String height) { this.height = height; }
    
    public String getGravity() { return gravity; }
    public void setGravity(String gravity) { this.gravity = gravity; }
    
    public Padding getPadding() { return padding; }
    public void setPadding(Padding padding) { this.padding = padding; }
    
    public Integer getMarginLeft() { return marginLeft; }
    public void setMarginLeft(Integer marginLeft) { this.marginLeft = marginLeft; }
    
    public Integer getMarginRight() { return marginRight; }
    public void setMarginRight(Integer marginRight) { this.marginRight = marginRight; }
    
    public Boolean getClickable() { return clickable; }
    public void setClickable(Boolean clickable) { this.clickable = clickable; }
    
    public Boolean getStateful() { return stateful; }
    public void setStateful(Boolean stateful) { this.stateful = stateful; }
    
    public String getLayout() { return layout; }
    public void setLayout(String layout) { this.layout = layout; }
    
    public Integer getSpacing() { return spacing; }
    public void setSpacing(Integer spacing) { this.spacing = spacing; }
    
    public Integer getMargin() { return margin; }
    public void setMargin(Integer margin) { this.margin = margin; }
}

public class Padding {
    private int left;
    private int right;
    private int top;
    private int bottom;
    
    // Getters and Setters
    public int getLeft() { return left; }
    public void setLeft(int left) { this.left = left; }
    
    public int getRight() { return right; }
    public void setRight(int right) { this.right = right; }
    
    public int getTop() { return top; }
    public void setTop(int top) { this.top = top; }
    
    public int getBottom() { return bottom; }
    public void setBottom(int bottom) { this.bottom = bottom; }
}

public class Control {
    private int index;
    private String symbol;
    private String name;
    private String type;
    private String position;
    private KnobStyle knob;
    private LabelStyle label;
    
    // Getters and Setters
    public int getIndex() { return index; }
    public void setIndex(int index) { this.index = index; }
    
    public String getSymbol() { return symbol; }
    public void setSymbol(String symbol) { this.symbol = symbol; }
    
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    
    public String getType() { return type; }
    public void setType(String type) { this.type = type; }
    
    public String getPosition() { return position; }
    public void setPosition(String position) { this.position = position; }
    
    public KnobStyle getKnob() { return knob; }
    public void setKnob(KnobStyle knob) { this.knob = knob; }
    
    public LabelStyle getLabel() { return label; }
    public void setLabel(LabelStyle label) { this.label = label; }
}

public class KnobStyle {
    private int width;
    private int height;
    private int frames;
    private int frameHeight;
    private String spriteSheet;
    private String rotationMode;
    
    // Getters and Setters
    public int getWidth() { return width; }
    public void setWidth(int width) { this.width = width; }
    
    public int getHeight() { return height; }
    public void setHeight(int height) { this.height = height; }
    
    public int getFrames() { return frames; }
    public void setFrames(int frames) { this.frames = frames; }
    
    public int getFrameHeight() { return frameHeight; }
    public void setFrameHeight(int frameHeight) { this.frameHeight = frameHeight; }
    
    public String getSpriteSheet() { return spriteSheet; }
    public void setSpriteSheet(String spriteSheet) { this.spriteSheet = spriteSheet; }
    
    public String getRotationMode() { return rotationMode; }
    public void setRotationMode(String rotationMode) { this.rotationMode = rotationMode; }
}

public class LabelStyle {
    private String text;
    private String position;
    private int offsetY;
    
    // Getters and Setters
    public String getText() { return text; }
    public void setText(String text) { this.text = text; }
    
    public String getPosition() { return position; }
    public void setPosition(String position) { this.position = position; }
    
    public int getOffsetY() { return offsetY; }
    public void setOffsetY(int offsetY) { this.offsetY = offsetY; }
}

public class Port {
    private int index;
    private String symbol;
    private String name;
    private String type;
    private String direction;
    private float defaultValue;
    private float minimum;
    private float maximum;
    private boolean integer;
    private String designation;
    private String unit;
    
    // Getters and Setters
    public int getIndex() { return index; }
    public void setIndex(int index) { this.index = index; }
    
    public String getSymbol() { return symbol; }
    public void setSymbol(String symbol) { this.symbol = symbol; }
    
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    
    public String getType() { return type; }
    public void setType(String type) { this.type = type; }
    
    public String getDirection() { return direction; }
    public void setDirection(String direction) { this.direction = direction; }
    
    public float getDefault() { return defaultValue; }
    public void setDefault(float defaultValue) { this.defaultValue = defaultValue; }
    
    public float getMinimum() { return minimum; }
    public void setMinimum(float minimum) { this.minimum = minimum; }
    
    public float getMaximum() { return maximum; }
    public void setMaximum(float maximum) { this.maximum = maximum; }
    
    public boolean isInteger() { return integer; }
    public void setInteger(boolean integer) { this.integer = integer; }
    
    public String getDesignation() { return designation; }
    public void setDesignation(String designation) { this.designation = designation; }
    
    public String getUnit() { return unit; }
    public void setUnit(String unit) { this.unit = unit; }
}

public class Preset {
    private String name;
    private boolean isDefault;
    private Map<String, Float> parameters;
    
    // Getters and Setters
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    
    public boolean isDefault() { return isDefault; }
    public void setDefault(boolean isDefault) { this.isDefault = isDefault; }
    
    public Map<String, Float> getParameters() { return parameters; }
    public void setParameters(Map<String, Float> parameters) { this.parameters = parameters; }
}
```

### 4. Utility Functions

```java
public class ViewUtils {
    private static final Resources resources = Resources.getSystem();
    
    public static int dpToPx(int dp) {
        return (int) TypedValue.applyDimension(
            TypedValue.COMPLEX_UNIT_DIP,
            dp,
            resources.getDisplayMetrics()
        );
    }
    
    public static Bitmap loadBitmapFromAssets(Context context, String path) {
        try (InputStream input = context.getAssets().open("skins/" + path)) {
            return BitmapFactory.decodeStream(input);
        } catch (IOException e) {
            Log.e("ViewUtils", "Failed to load bitmap: " + path, e);
            return null;
        }
    }
    
    public static int parseGravity(String gravity) {
        switch (gravity) {
            case "center":
                return Gravity.CENTER;
            case "center_horizontal":
                return Gravity.CENTER_HORIZONTAL;
            case "center_vertical":
                return Gravity.CENTER_VERTICAL;
            case "top":
                return Gravity.TOP;
            case "bottom":
                return Gravity.BOTTOM;
            case "left":
                return Gravity.LEFT;
            case "right":
                return Gravity.RIGHT;
            default:
                return Gravity.NO_GRAVITY;
        }
    }
}
```

## Conversion Tool: MOD to Android Skin

### Python Script: `convert_mod_to_android_skin.py`

```python
#!/usr/bin/env python3
"""
Convert MOD platform TTL/CSS to Android Skin JSON
"""

import json
import re
from pathlib import Path
from typing import Dict, List, Any
from rdflib import Graph, Namespace, RDF, RDFS

LV2 = Namespace("http://lv2plug.in/ns/lv2core#")
MODGUI = Namespace("http://moddevices.com/ns/modgui#")

class ModToAndroidConverter:
    def __init__(self, mod_dir: Path):
        self.mod_dir = mod_dir
        self.plugin_ttl = self.load_ttl("gx_*.ttl")
        self.modgui_ttl = self.load_ttl("modgui.ttl")
        self.css = self.load_css()
        
    def load_ttl(self, pattern: str) -> Graph:
        """Load TTL file into RDF graph"""
        g = Graph()
        for ttl_file in self.mod_dir.glob(pattern):
            g.parse(ttl_file, format='turtle')
        return g
    
    def load_css(self) -> str:
        """Load CSS stylesheet"""
        css_file = list(self.mod_dir.glob("modgui/stylesheet-*.css"))[0]
        return css_file.read_text()
    
    def extract_plugin_info(self) -> Dict[str, Any]:
        """Extract plugin metadata from TTL"""
        # Query RDF graph for plugin info
        plugin_uri = None
        for s, p, o in self.plugin_ttl.triples((None, RDF.type, LV2.Plugin)):
            plugin_uri = str(s)
            break
        
        name = self.plugin_ttl.value(plugin_uri, Namespace("http://usefulinc.com/ns/doap#").name)
        
        return {
            "uri": plugin_uri,
            "name": str(name),
            "brand": "Guitarix",
            "category": self.extract_category(plugin_uri),
            "description": self.extract_description(plugin_uri)
        }
    
    def extract_category(self, plugin_uri: str) -> str:
        """Determine plugin category"""
        for s, p, o in self.plugin_ttl.triples((plugin_uri, RDF.type, None)):
            category_str = str(o)
            if "Distortion" in category_str:
                return "Distortion"
            elif "Overdrive" in category_str:
                return "Overdrive"
            # Add more categories
        return "Effect"
    
    def extract_ports(self) -> List[Dict[str, Any]]:
        """Extract port definitions from TTL"""
        ports = []
        for s, p, o in self.plugin_ttl.triples((None, LV2.port, None)):
            port_info = self.parse_port(o)
            ports.append(port_info)
        return sorted(ports, key=lambda x: x['index'])
    
    def parse_port(self, port_uri) -> Dict[str, Any]:
        """Parse individual port details"""
        return {
            "index": int(self.plugin_ttl.value(port_uri, LV2.index)),
            "symbol": str(self.plugin_ttl.value(port_uri, LV2.symbol)),
            "name": str(self.plugin_ttl.value(port_uri, LV2.name)),
            "type": self.determine_port_type(port_uri),
            "direction": self.determine_port_direction(port_uri),
            "default": float(self.plugin_ttl.value(port_uri, LV2.default) or 0),
            "minimum": float(self.plugin_ttl.value(port_uri, LV2.minimum) or 0),
            "maximum": float(self.plugin_ttl.value(port_uri, LV2.maximum) or 1),
        }
    
    def extract_css_dimensions(self) -> Dict[str, Any]:
        """Parse CSS for dimensions and layout"""
        dimensions = {}
        
        # Extract standard dimensions
        match = re.search(r'height:(\d+)px;.*?width:(\d+)px', self.css)
        if match:
            dimensions['standard'] = {
                "width": int(match.group(2)),
                "height": int(match.group(1))
            }
        
        # Extract variants (boxy50, boxy75, etc.)
        variant_pattern = r'\.mod-(boxy\d+)\s*{[^}]*background-size:(\d+)px\s+(\d+)px'
        for match in re.finditer(variant_pattern, self.css):
            variant_name = match.group(1)
            dimensions[variant_name] = {
                "width": int(match.group(2)),
                "height": int(match.group(3))
            }
        
        return dimensions
    
    def extract_layout_positions(self) -> Dict[str, Any]:
        """Parse CSS for element positioning"""
        layout = {}
        
        # Brand position
        brand_match = re.search(r'\.mod-plugin-brand\s*{[^}]*top:(\d+)px', self.css)
        if brand_match:
            layout['brand'] = {"x": 0, "y": int(brand_match.group(1))}
        
        # Plugin name position
        name_match = re.search(r'\.mod-plugin-name\s*{[^}]*top:(\d+)px', self.css)
        if name_match:
            layout['pluginName'] = {"x": 30, "y": int(name_match.group(1))}
        
        # LED position
        led_match = re.search(r'\.mod-light\s*{[^}]*top:(\d+)px', self.css)
        if led_match:
            layout['bypassLed'] = {"x": 10, "y": int(led_match.group(1))}
        
        # Footswitch position
        fs_match = re.search(r'\.mod-footswitch\s*{[^}]*bottom:\s*(\d+)px', self.css)
        if fs_match:
            layout['footswitch'] = {"x": "center", "y": 336}
        
        return layout
    
    def extract_controls(self) -> List[Dict[str, Any]]:
        """Extract control definitions from modgui.ttl"""
        controls = []
        
        # Parse modgui.ttl for port ordering
        for s, p, o in self.modgui_ttl.triples((None, MODGUI.port, None)):
            control = {
                "index": int(self.modgui_ttl.value(o, LV2.index)),
                "symbol": str(self.modgui_ttl.value(o, LV2.symbol)),
                "name": str(self.modgui_ttl.value(o, LV2.name)),
                "type": "knob"
            }
            controls.append(control)
        
        # Sort and assign positions
        positions = ["left", "center", "right"]
        for i, control in enumerate(sorted(controls, key=lambda x: x['index'])):
            control['position'] = positions[i] if i < len(positions) else "extra"
        
        return controls
    
    def convert(self) -> Dict[str, Any]:
        """Main conversion function"""
        return {
            "skin": {
                "version": "1.0",
                "plugin": self.extract_plugin_info(),
                "visual": self.extract_visual_info(),
                "assets": self.extract_assets(),
                "theme": self.extract_theme(),
                "layout": self.extract_layout_positions(),
                "controls": self.extract_controls(),
                "ports": self.extract_ports(),
                "presets": self.extract_presets()
            }
        }

def main():
    import argparse
    parser = argparse.ArgumentParser(description='Convert MOD to Android Skin')
    parser.add_argument('mod_dir', type=Path, help='MOD directory path')
    parser.add_argument('output', type=Path, help='Output JSON file')
    
    args = parser.parse_args()
    
    converter = ModToAndroidConverter(args.mod_dir)
    skin_data = converter.convert()
    
    with open(args.output, 'w') as f:
        json.dump(skin_data, f, indent=2)
    
    print(f"Converted skin written to {args.output}")

if __name__ == "__main__":
    main()
```

## Asset Organization

### Android Assets Structure

```
app/src/main/assets/skins/
├── gx_axisface/
│   ├── skin.json                         # Generated from conversion
│   ├── pedals/
│   │   ├── boxy/
│   │   │   └── axisface.png
│   │   └── footswitch.png
│   ├── knobs/
│   │   └── boxy/
│   │       └── cairo.png
│   ├── screenshot-gxaxisface.png
│   └── thumbnail-gxaxisface.png
├── gx_blueamp/
│   ├── skin.json
│   └── ... (similar structure)
└── ... (43 plugins total)
```

## Integration with LV2 Native Code

### JNI Bridge

```java
public class LV2PluginBridge {
    private final String soLibrary;
    private long nativeHandle = 0;
    
    static {
        System.loadLibrary("lv2_bridge");
    }
    
    public LV2PluginBridge(String soLibrary) {
        this.soLibrary = soLibrary;
        System.loadLibrary(soLibrary);
    }
    
    // JNI Methods
    private native long nativeInstantiate(String uri, double sampleRate);
    private native void nativeConnect(long handle, int port, float[] buffer);
    private native void nativeRun(long handle, int sampleCount);
    private native void nativeCleanup(long handle);
    
    public void instantiate(String uri, double sampleRate) {
        nativeHandle = nativeInstantiate(uri, sampleRate);
    }
    
    public void setParameter(int portIndex, float value) {
        float[] buffer = {value};
        nativeConnect(nativeHandle, portIndex, buffer);
    }
    
    public void process(float[] input, float[] output, int sampleCount) {
        nativeConnect(nativeHandle, 1, input);   // Input port
        nativeConnect(nativeHandle, 0, output);  // Output port
        nativeRun(nativeHandle, sampleCount);
    }
    
    public void cleanup() {
        nativeCleanup(nativeHandle);
    }
}
```

### Complete Plugin Activity

```java
public class PluginActivity extends AppCompatActivity {
    private PluginPedalView pedalView;
    private LV2PluginBridge pluginBridge;
    private PluginSkin skin;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Load skin
        String skinJson = loadSkinJson();
        skin = PluginSkin.fromJson(skinJson);
        
        // Initialize plugin bridge
        pluginBridge = new LV2PluginBridge("gx_AxisFace");
        pluginBridge.instantiate(skin.getPlugin().getUri(), 48000.0);
        
        // Create and configure UI
        pedalView = new PluginPedalView(this);
        pedalView.loadSkin(skinJson);
        
        // Wire up callbacks
        final LV2PluginBridge bridge = pluginBridge;
        pedalView.setOnParameterChangedListener((symbol, value) -> {
            Port port = skin.getPort(symbol);
            bridge.setParameter(port.getIndex(), value);
        });
        
        pedalView.setOnBypassChangedListener(bypassed -> {
            Port bypassPort = skin.getPort("BYPASS");
            bridge.setParameter(bypassPort.getIndex(), bypassed ? 1.0f : 0.0f);
        });
        
        setContentView(pedalView);
        
        // Load default preset
        for (Preset preset : skin.getPresets()) {
            if (preset.isDefault()) {
                loadPreset(preset);
                break;
            }
        }
    }
    
    private void loadPreset(Preset preset) {
        for (Map.Entry<String, Float> entry : preset.getParameters().entrySet()) {
            String symbol = entry.getKey();
            float value = entry.getValue();
            
            pedalView.setParameterValue(symbol, value);
            Port port = skin.getPort(symbol);
            pluginBridge.setParameter(port.getIndex(), value);
        }
    }
    
    private String loadSkinJson() {
        try (InputStream input = getAssets().open("skins/gx_axisface/skin.json");
             BufferedReader reader = new BufferedReader(new InputStreamReader(input))) {
            
            StringBuilder sb = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                sb.append(line);
            }
            return sb.toString();
        } catch (IOException e) {
            Log.e("PluginActivity", "Failed to load skin JSON", e);
            return null;
        }
    }
    
    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (pluginBridge != null) {
            pluginBridge.cleanup();
        }
    }
}

## Build System Integration

### Gradle Task: Convert All Skins

```gradle
task convertModSkins {
    description 'Convert MOD skins to Android format'
    
    doLast {
        def modDir = file('../GxPlugins')
        def outputDir = file('src/main/assets/skins')
        outputDir.mkdirs()
        
        modDir.listFiles().findAll { it.isDirectory() && it.name.endsWith('.lv2') }.each { pluginDir ->
            def modSubdir = new File(pluginDir, 'MOD')
            if (modSubdir.exists()) {
                def pluginName = pluginDir.name.replace('.lv2', '').toLowerCase()
                def skinOutput = new File(outputDir, pluginName)
                skinOutput.mkdirs()
                
                // Run conversion script
                exec {
                    commandLine 'python3', '../scripts/convert_mod_to_android_skin.py', 
                                modSubdir.absolutePath, 
                                new File(skinOutput, 'skin.json').absolutePath
                }
                
                // Copy assets
                copy {
                    from new File(modSubdir, 'modgui')
                    into skinOutput
                    include '**/*.png'
                }
                
                println "Converted ${pluginName}"
            }
        }
    }
}

preBuild.dependsOn convertModSkins
```

## Advanced Features

### Responsive Layout Support

```java
public class ResponsivePedalView extends PluginPedalView {
    public ResponsivePedalView(Context context) {
        super(context);
    }
    
    public ResponsivePedalView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }
    
    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        int availableWidth = MeasureSpec.getSize(widthMeasureSpec);
        int availableHeight = MeasureSpec.getSize(heightMeasureSpec);
        
        PluginSkin skin = getSkin();
        if (skin != null) {
            // Choose best variant based on available space
            String bestVariant = "standard";
            int largestWidth = 0;
            
            for (Map.Entry<String, Dimensions> entry : 
                 skin.getVisual().getVariants().entrySet()) {
                
                if (entry.getValue().getWidth() <= availableWidth &&
                    entry.getValue().getWidth() > largestWidth) {
                    
                    bestVariant = entry.getKey();
                    largestWidth = entry.getValue().getWidth();
                }
            }
            
            loadVariant(bestVariant);
        }
        
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);
    }
    
    private void loadVariant(String variant) {
        // Load variant-specific resources if needed
    }
    
    protected PluginSkin getSkin() {
        try {
            return (PluginSkin) getTag();
        } catch (Exception e) {
            return null;
        }
    }
}
```

### Theme Customization

```java
public class ThemeCustomizer {
    public static PluginSkin applyTheme(PluginSkin skin, UserTheme userTheme) {
        Theme originalTheme = skin.getTheme();
        Theme newTheme = new Theme();
        
        newTheme.setTextColor(userTheme.getTextColor() != null ? 
            userTheme.getTextColor() : originalTheme.getTextColor());
        
        newTheme.setBrandBorderColor(userTheme.getAccentColor() != null ?
            userTheme.getAccentColor() : originalTheme.getBrandBorderColor());
        
        // Copy other theme properties
        newTheme.setBrandBorderWidth(originalTheme.getBrandBorderWidth());
        newTheme.setBrandBorderRadius(originalTheme.getBrandBorderRadius());
        newTheme.setBackgroundColor(originalTheme.getBackgroundColor());
        newTheme.setFonts(originalTheme.getFonts());
        
        skin.setTheme(newTheme);
        return skin;
    }
}

public class UserTheme {
    private String textColor;
    private String accentColor;
    
    public String getTextColor() { return textColor; }
    public void setTextColor(String textColor) { this.textColor = textColor; }
    
    public String getAccentColor() { return accentColor; }
    public void setAccentColor(String accentColor) { this.accentColor = accentColor; }
}
```

### Animation Support

```java
public class AnimatedKnobView extends KnobView {
    private ValueAnimator valueAnimator;
    
    public AnimatedKnobView(Context context) {
        super(context);
        initAnimator();
    }
    
    public AnimatedKnobView(Context context, AttributeSet attrs) {
        super(context, attrs);
        initAnimator();
    }
    
    private void initAnimator() {
        valueAnimator = new ValueAnimator();
        valueAnimator.setInterpolator(new DecelerateInterpolator());
    }
    
    public void animateToValue(float targetValue, long duration) {
        valueAnimator.cancel();
        
        valueAnimator.setFloatValues(getValue(), targetValue);
        valueAnimator.setDuration(duration);
        valueAnimator.addUpdateListener(animation -> 
            setValue((Float) animation.getAnimatedValue())
        );
        
        valueAnimator.start();
    }
    
    public void animateToValue(float targetValue) {
        animateToValue(targetValue, 200);
    }
}
```

## Summary

This skin format design provides:

✅ **Complete visual fidelity** from MOD platform  
✅ **Native Android performance** using View system  
✅ **Automated conversion** from existing MOD resources  
✅ **Reusable components** (knobs, footswitches, LEDs)  
✅ **Flexible layouts** with responsive support  
✅ **Easy integration** with LV2 native audio code  
✅ **Extensible architecture** for future enhancements  

The JSON format captures all essential styling While remaining human-readable and maintainable.
