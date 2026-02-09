package com.opiqo.theme;

import android.content.Context;
import android.content.res.AssetManager;
import android.util.Log;
import com.google.gson.Gson;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

/**
 * ThemeManager handles loading, caching, and applying plugin skins/themes.
 * Manages the lifecycle of PluginSkin objects and provides utilities for theme operations.
 */
public class ThemeManager {
    private static final String TAG = "ThemeManager";
    private static final String SKIN_BASE_PATH = "skins/";
    private static final String SKIN_FILENAME = "skin.json";
    
    private final Context context;
    private final Gson gson;
    private final Map<String, PluginSkin> skinCache;
    
    public interface SkinLoadListener {
        void onSkinLoaded(PluginSkin skin);
        void onSkinLoadFailed(String pluginName, Exception e);
    }
    
    /**
     * Initialize ThemeManager with application context
     */
    public ThemeManager(Context context) {
        this.context = context.getApplicationContext();
        this.gson = new Gson();
        this.skinCache = new HashMap<>();
    }
    
    /**
     * Load a plugin skin from assets synchronously
     * @param pluginName Name of the plugin (e.g., "gx_axisface")
     * @return PluginSkin object or null if loading fails
     */
    public PluginSkin loadSkin(String pluginName) {
        // Check cache first
        if (skinCache.containsKey(pluginName)) {
            Log.d(TAG, "Returning cached skin for: " + pluginName);
            return skinCache.get(pluginName);
        }
        
        try {
            String skinJson = loadSkinJson(pluginName);
            PluginSkin skin = PluginSkin.fromJson(skinJson);
            
            // Cache the loaded skin
            skinCache.put(pluginName, skin);
            Log.d(TAG, "Loaded skin for: " + pluginName);
            
            return skin;
        } catch (Exception e) {
            Log.e(TAG, "Failed to load skin: " + pluginName, e);
            return null;
        }
    }
    
    /**
     * Load a plugin skin asynchronously
     * @param pluginName Name of the plugin
     * @param listener Callback for skin loading completion
     */
    public void loadSkinAsync(final String pluginName, final SkinLoadListener listener) {
        new Thread(() -> {
            try {
                PluginSkin skin = loadSkin(pluginName);
                if (skin != null) {
                    listener.onSkinLoaded(skin);
                } else {
                    listener.onSkinLoadFailed(pluginName, 
                        new Exception("Failed to parse skin JSON"));
                }
            } catch (Exception e) {
                listener.onSkinLoadFailed(pluginName, e);
            }
        }).start();
    }
    
    /**
     * Get a cached skin without loading
     * @param pluginName Name of the plugin
     * @return PluginSkin from cache or null
     */
    public PluginSkin getCachedSkin(String pluginName) {
        return skinCache.get(pluginName);
    }
    
    /**
     * Clear the skin cache
     */
    public void clearCache() {
        skinCache.clear();
        Log.d(TAG, "Skin cache cleared");
    }
    
    /**
     * Clear a specific plugin's skin from cache
     */
    public void clearCache(String pluginName) {
        skinCache.remove(pluginName);
        Log.d(TAG, "Cleared cache for: " + pluginName);
    }
    
    /**
     * Get the path to a skin asset
     * @param pluginName Name of the plugin
     * @param assetPath Relative path within the skin directory
     * @return Full asset path
     */
    public String getAssetPath(String pluginName, String assetPath) {
        return SKIN_BASE_PATH + pluginName + "/" + assetPath;
    }
    
    /**
     * Check if a skin exists in assets
     * @param pluginName Name of the plugin
     * @return true if skin exists
     */
    public boolean skinExists(String pluginName) {
        try {
            String skinPath = getAssetPath(pluginName, SKIN_FILENAME);
            context.getAssets().open(skinPath).close();
            return true;
        } catch (IOException e) {
            return false;
        }
    }
    
    /**
     * Get list of all available skins
     * @return Array of plugin names with available skins
     */
    public String[] getAvailableSkins() {
        try {
            String[] files = context.getAssets().list(SKIN_BASE_PATH.replaceAll("/$", ""));
            if (files == null) files = new String[0];
            return files;
        } catch (IOException e) {
            Log.e(TAG, "Failed to list available skins", e);
            return new String[0];
        }
    }
    
    /**
     * Apply a theme variant to a skin
     * @param skin The base skin
     * @param variantName Name of the variant (e.g., "boxy50", "boxy75")
     * @return Modified skin with variant applied
     */
    public PluginSkin applyVariant(PluginSkin skin, String variantName) {
        if (skin == null || skin.getVisual() == null) {
            return skin;
        }
        
        Dimensions variantDimensions = skin.getVisual()
            .getVariants()
            .get(variantName);
        
        if (variantDimensions != null) {
            skin.getVisual().setVariant(variantName);
            Log.d(TAG, "Applied variant: " + variantName);
        }
        
        return skin;
    }
    
    /**
     * Apply color theme customization to a skin
     * @param skin The base skin
     * @param customTheme User-provided theme customization
     * @return Skin with custom theme applied
     */
    public PluginSkin applyCustomTheme(PluginSkin skin, UserTheme customTheme) {
        if (skin == null || skin.getTheme() == null || customTheme == null) {
            return skin;
        }
        
        Theme theme = skin.getTheme();
        
        if (customTheme.getTextColor() != null) {
            theme.setTextColor(customTheme.getTextColor());
        }
        if (customTheme.getAccentColor() != null) {
            theme.setBrandBorderColor(customTheme.getAccentColor());
        }
        if (customTheme.getBackgroundColor() != null) {
            theme.setBackgroundColor(customTheme.getBackgroundColor());
        }
        
        Log.d(TAG, "Applied custom theme");
        return skin;
    }
    
    /**
     * Load raw skin JSON from assets
     * @param pluginName Name of the plugin
     * @return Skin JSON string
     */
    private String loadSkinJson(String pluginName) throws IOException {
        String skinPath = getAssetPath(pluginName, SKIN_FILENAME);
        AssetManager assets = context.getAssets();
        
        try (InputStream input = assets.open(skinPath);
             BufferedReader reader = new BufferedReader(new InputStreamReader(input))) {
            
            StringBuilder sb = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                sb.append(line);
            }
            return sb.toString();
        }
    }
    
    /**
     * Reload a skin from disk (bypass cache)
     * @param pluginName Name of the plugin
     * @return Fresh PluginSkin instance
     */
    public PluginSkin reloadSkin(String pluginName) {
        clearCache(pluginName);
        return loadSkin(pluginName);
    }
    
    /**
     * Get skin statistics
     * @return Map with cache statistics
     */
    public Map<String, Object> getStatistics() {
        Map<String, Object> stats = new HashMap<>();
        stats.put("cached_skins", skinCache.size());
        stats.put("available_skins", getAvailableSkins().length);
        return stats;
    }
}
