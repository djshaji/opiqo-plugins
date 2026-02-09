package com.opiqo.theme;

import android.util.Log;
import com.google.gson.Gson;
import com.google.gson.JsonSyntaxException;
import java.util.HashMap;
import java.util.Map;

/**
 * SkinParser handles parsing and validation of JSON skin files.
 * Provides methods for extracting specific sections and validating structure.
 */
public class SkinParser {
    private static final String TAG = "SkinParser";
    private final Gson gson;
    
    public SkinParser() {
        this.gson = new Gson();
    }
    
    /**
     * Parse a complete skin JSON string
     * @param json Raw JSON string
     * @return Parsed PluginSkin object
     * @throws JsonSyntaxException if JSON is invalid
     */
    public PluginSkin parseSkin(String json) throws JsonSyntaxException {
        Log.d(TAG, "Parsing skin JSON");
        return gson.fromJson(json, PluginSkin.class);
    }
    
    /**
     * Validate skin JSON for required fields
     * @param skin The skin to validate
     * @return Validation result with errors if any
     */
    public ValidationResult validateSkin(PluginSkin skin) {
        ValidationResult result = new ValidationResult();
        
        if (skin == null) {
            result.addError("Skin is null");
            return result;
        }
        
        // Validate plugin info
        if (skin.getPlugin() == null) {
            result.addError("Plugin info is missing");
        } else {
            if (skin.getPlugin().getUri() == null || skin.getPlugin().getUri().isEmpty()) {
                result.addError("Plugin URI is missing");
            }
            if (skin.getPlugin().getName() == null || skin.getPlugin().getName().isEmpty()) {
                result.addError("Plugin name is missing");
            }
        }
        
        // Validate visual style
        if (skin.getVisual() == null) {
            result.addError("Visual style is missing");
        } else {
            if (skin.getVisual().getDimensions() == null) {
                result.addError("Dimensions are missing");
            }
        }
        
        // Validate assets
        if (skin.getAssets() == null) {
            result.addError("Assets are missing");
        } else {
            if (skin.getAssets().getBackground() == null) {
                result.addWarning("Background asset not specified");
            }
        }
        
        // Validate controls
        if (skin.getControls() == null || skin.getControls().isEmpty()) {
            result.addWarning("No controls defined");
        }
        
        // Validate ports
        if (skin.getPorts() == null || skin.getPorts().isEmpty()) {
            result.addError("No ports defined");
        }
        
        Log.d(TAG, "Validation result: " + (result.isValid() ? "VALID" : "INVALID"));
        return result;
    }
    
    /**
     * Extract plugin metadata from skin
     * @param skin The skin to extract from
     * @return PluginInfo object
     */
    public PluginInfo extractPluginInfo(PluginSkin skin) {
        if (skin != null && skin.getPlugin() != null) {
            return skin.getPlugin();
        }
        return new PluginInfo();
    }
    
    /**
     * Extract visual style from skin
     * @param skin The skin to extract from
     * @return VisualStyle object
     */
    public VisualStyle extractVisualStyle(PluginSkin skin) {
        if (skin != null && skin.getVisual() != null) {
            return skin.getVisual();
        }
        return new VisualStyle();
    }
    
    /**
     * Extract theme configuration from skin
     * @param skin The skin to extract from
     * @return Theme object
     */
    public Theme extractTheme(PluginSkin skin) {
        if (skin != null && skin.getTheme() != null) {
            return skin.getTheme();
        }
        return new Theme();
    }
    
    /**
     * Extract layout configuration from skin
     * @param skin The skin to extract from
     * @return Layout object
     */
    public Layout extractLayout(PluginSkin skin) {
        if (skin != null && skin.getLayout() != null) {
            return skin.getLayout();
        }
        return new Layout();
    }
    
    /**
     * Get port by symbol name
     * @param skin The skin to search in
     * @param symbol Port symbol name
     * @return Port object or null if not found
     */
    public Port getPortBySymbol(PluginSkin skin, String symbol) {
        if (skin == null || skin.getPorts() == null) {
            return null;
        }
        
        for (Port port : skin.getPorts()) {
            if (symbol.equals(port.getSymbol())) {
                return port;
            }
        }
        return null;
    }
    
    /**
     * Get control by symbol name
     * @param skin The skin to search in
     * @param symbol Control symbol name
     * @return Control object or null if not found
     */
    public Control getControlBySymbol(PluginSkin skin, String symbol) {
        if (skin == null || skin.getControls() == null) {
            return null;
        }
        
        for (Control control : skin.getControls()) {
            if (symbol.equals(control.getSymbol())) {
                return control;
            }
        }
        return null;
    }
    
    /**
     * Get preset by name
     * @param skin The skin to search in
     * @param presetName Preset name
     * @return Preset object or null if not found
     */
    public Preset getPresetByName(PluginSkin skin, String presetName) {
        if (skin == null || skin.getPresets() == null) {
            return null;
        }
        
        for (Preset preset : skin.getPresets()) {
            if (presetName.equals(preset.getName())) {
                return preset;
            }
        }
        return null;
    }
    
    /**
     * Get default preset
     * @param skin The skin to search in
     * @return Default Preset or null if not found
     */
    public Preset getDefaultPreset(PluginSkin skin) {
        if (skin == null || skin.getPresets() == null) {
            return null;
        }
        
        for (Preset preset : skin.getPresets()) {
            if (preset.isDefault()) {
                return preset;
            }
        }
        return null;
    }
    
    /**
     * Merge multiple skins (useful for theme overrides)
     * @param baseSkin Base skin configuration
     * @param overrideSkin Skin with overrides
     * @return Merged skin
     */
    public PluginSkin mergeSkins(PluginSkin baseSkin, PluginSkin overrideSkin) {
        if (baseSkin == null) {
            return overrideSkin;
        }
        if (overrideSkin == null) {
            return baseSkin;
        }
        
        PluginSkin merged = new PluginSkin();
        
        // Use base values, override with non-null override values
        merged.setVersion(baseSkin.getVersion());
        merged.setPlugin(baseSkin.getPlugin());
        merged.setVisual(overrideSkin.getVisual() != null ? 
            overrideSkin.getVisual() : baseSkin.getVisual());
        merged.setAssets(baseSkin.getAssets());
        merged.setTheme(overrideSkin.getTheme() != null ? 
            overrideSkin.getTheme() : baseSkin.getTheme());
        merged.setLayout(overrideSkin.getLayout() != null ? 
            overrideSkin.getLayout() : baseSkin.getLayout());
        merged.setControls(baseSkin.getControls());
        merged.setPorts(baseSkin.getPorts());
        merged.setPresets(baseSkin.getPresets());
        
        Log.d(TAG, "Merged skins successfully");
        return merged;
    }
    
    /**
     * Create a minimal valid skin
     * @param pluginName Name of the plugin
     * @return Minimal PluginSkin with required fields
     */
    public PluginSkin createMinimalSkin(String pluginName) {
        PluginSkin skin = new PluginSkin();
        
        PluginInfo info = new PluginInfo();
        info.setUri("http://example.com/plugin/" + pluginName);
        info.setName(pluginName);
        info.setBrand("Unknown");
        info.setCategory("Effect");
        skin.setPlugin(info);
        
        skin.setVersion("1.0");
        
        Log.d(TAG, "Created minimal skin for: " + pluginName);
        return skin;
    }
    
    /**
     * Explains skin structure for debugging
     * @param skin The skin to analyze
     * @return Detailed description of skin structure
     */
    public String describeSkin(PluginSkin skin) {
        StringBuilder sb = new StringBuilder();
        
        if (skin == null) {
            return "Skin is null";
        }
        
        sb.append("Plugin: ").append(skin.getPlugin().getName()).append("\n");
        sb.append("URI: ").append(skin.getPlugin().getUri()).append("\n");
        sb.append("Version: ").append(skin.getVersion()).append("\n");
        
        if (skin.getControls() != null) {
            sb.append("Controls: ").append(skin.getControls().size()).append("\n");
        }
        
        if (skin.getPorts() != null) {
            sb.append("Ports: ").append(skin.getPorts().size()).append("\n");
        }
        
        if (skin.getPresets() != null) {
            sb.append("Presets: ").append(skin.getPresets().size()).append("\n");
        }
        
        return sb.toString();
    }
    
    /**
     * Validation result holder
     */
    public static class ValidationResult {
        private boolean valid = true;
        private final Map<String, String> errors = new HashMap<>();
        private final Map<String, String> warnings = new HashMap<>();
        
        public void addError(String message) {
            valid = false;
            errors.put(String.valueOf(errors.size()), message);
        }
        
        public void addWarning(String message) {
            warnings.put(String.valueOf(warnings.size()), message);
        }
        
        public boolean isValid() {
            return valid;
        }
        
        public Map<String, String> getErrors() {
            return errors;
        }
        
        public Map<String, String> getWarnings() {
            return warnings;
        }
        
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (!errors.isEmpty()) {
                sb.append("Errors:\n");
                errors.forEach((k, v) -> sb.append("  - ").append(v).append("\n"));
            }
            if (!warnings.isEmpty()) {
                sb.append("Warnings:\n");
                warnings.forEach((k, v) -> sb.append("  - ").append(v).append("\n"));
            }
            return sb.toString();
        }
    }
}
