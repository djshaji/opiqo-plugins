package com.opiqo.theme;

import android.graphics.Color;
import android.util.Log;

/**
 * ColorUtils provides utilities for parsing, manipulating, and converting colors.
 * Handles hex colors, RGB, HSL, and color adjustments for theming.
 */
public class ColorUtils {
    private static final String TAG = "ColorUtils";
    
    /**
     * Parse hex color string to Android Color int
     * @param hexColor Color in hex format (#RRGGBB or #AARRGGBB)
     * @return Android color int or Color.BLACK if parsing fails
     */
    public static int parseHexColor(String hexColor) {
        if (hexColor == null || hexColor.isEmpty()) {
            Log.w(TAG, "Empty hex color string");
            return Color.BLACK;
        }
        
        try {
            return Color.parseColor(hexColor);
        } catch (IllegalArgumentException e) {
            Log.e(TAG, "Invalid hex color: " + hexColor, e);
            return Color.BLACK;
        }
    }
    
    /**
     * Convert Android color int to hex string
     * @param color The color as int
     * @param includeAlpha Whether to include alpha channel
     * @return Hex string (e.g., "#FF0000" or "#FFFF0000")
     */
    public static String colorToHex(int color, boolean includeAlpha) {
        if (includeAlpha) {
            return String.format("#%08X", color);
        } else {
            return String.format("#%06X", color & 0xFFFFFF);
        }
    }
    
    /**
     * Get RGB components from color
     * @param color The color as int
     * @return Array [R, G, B] in range 0-255
     */
    public static int[] getRGB(int color) {
        return new int[]{
            Color.red(color),
            Color.green(color),
            Color.blue(color)
        };
    }
    
    /**
     * Get HSL (Hue, Saturation, Lightness) components from color
     * @param color The color as int
     * @return Array [H(0-360), S(0-100), L(0-100)]
     */
    public static float[] getHSL(int color) {
        float r = Color.red(color) / 255f;
        float g = Color.green(color) / 255f;
        float b = Color.blue(color) / 255f;
        
        float max = Math.max(r, Math.max(g, b));
        float min = Math.min(r, Math.min(g, b));
        float l = (max + min) / 2f;
        
        float h = 0, s = 0;
        
        if (max != min) {
            float d = max - min;
            s = l > 0.5f ? d / (2 - max - min) : d / (max + min);
            
            if (max == r) {
                h = ((g - b) / d + (g < b ? 6 : 0)) / 6f;
            } else if (max == g) {
                h = ((b - r) / d + 2) / 6f;
            } else {
                h = ((r - g) / d + 4) / 6f;
            }
        }
        
        return new float[]{h * 360, s * 100, l * 100};
    }
    
    /**
     * Create color from HSL components
     * @param h Hue (0-360)
     * @param s Saturation (0-100)
     * @param l Lightness (0-100)
     * @return Color as int
     */
    public static int fromHSL(float h, float s, float l) {
        h = h % 360;
        s = Math.max(0, Math.min(100, s)) / 100f;
        l = Math.max(0, Math.min(100, l)) / 100f;
        
        float c = (1 - Math.abs(2 * l - 1)) * s;
        float hp = h / 60f;
        float x = c * (1 - Math.abs(hp % 2 - 1));
        
        float r = 0, g = 0, b = 0;
        
        if (hp < 1) {
            r = c; g = x;
        } else if (hp < 2) {
            r = x; g = c;
        } else if (hp < 3) {
            g = c; b = x;
        } else if (hp < 4) {
            g = x; b = c;
        } else if (hp < 5) {
            r = x; b = c;
        } else {
            r = c; b = x;
        }
        
        float m = l - c / 2;
        return Color.rgb(
            Math.round((r + m) * 255),
            Math.round((g + m) * 255),
            Math.round((b + m) * 255)
        );
    }
    
    /**
     * Lighten a color
     * @param color The original color
     * @param amount Amount to lighten (0-100, where 50 is neutral)
     * @return Lightened color
     */
    public static int lighten(int color, float amount) {
        float[] hsl = getHSL(color);
        hsl[2] = Math.min(100, hsl[2] + amount);
        return fromHSL(hsl[0], hsl[1], hsl[2]);
    }
    
    /**
     * Darken a color
     * @param color The original color
     * @param amount Amount to darken (0-100)
     * @return Darkened color
     */
    public static int darken(int color, float amount) {
        return lighten(color, -amount);
    }
    
    /**
     * Saturate a color (increase saturation)
     * @param color The original color
     * @param amount Amount to saturate (0-100)
     * @return Saturated color
     */
    public static int saturate(int color, float amount) {
        float[] hsl = getHSL(color);
        hsl[1] = Math.min(100, hsl[1] + amount);
        return fromHSL(hsl[0], hsl[1], hsl[2]);
    }
    
    /**
     * Desaturate a color (decrease saturation)
     * @param color The original color
     * @param amount Amount to desaturate (0-100)
     * @return Desaturated color
     */
    public static int desaturate(int color, float amount) {
        return saturate(color, -amount);
    }
    
    /**
     * Adjust hue of a color
     * @param color The original color
     * @param degrees Degrees to rotate hue (0-360)
     * @return Color with adjusted hue
     */
    public static int adjustHue(int color, float degrees) {
        float[] hsl = getHSL(color);
        hsl[0] = (hsl[0] + degrees) % 360;
        return fromHSL(hsl[0], hsl[1], hsl[2]);
    }
    
    /**
     * Get complementary color
     * @param color The original color
     * @return Complementary color (opposite on color wheel)
     */
    public static int getComplementary(int color) {
        return adjustHue(color, 180);
    }
    
    /**
     * Blend two colors
     * @param color1 First color
     * @param color2 Second color
     * @param ratio Blend ratio (0-1, where 0 is color1 and 1 is color2)
     * @return Blended color
     */
    public static int blend(int color1, int color2, float ratio) {
        ratio = Math.max(0, Math.min(1, ratio));
        
        int r1 = Color.red(color1);
        int g1 = Color.green(color1);
        int b1 = Color.blue(color1);
        int a1 = Color.alpha(color1);
        
        int r2 = Color.red(color2);
        int g2 = Color.green(color2);
        int b2 = Color.blue(color2);
        int a2 = Color.alpha(color2);
        
        return Color.argb(
            Math.round(a1 * (1 - ratio) + a2 * ratio),
            Math.round(r1 * (1 - ratio) + r2 * ratio),
            Math.round(g1 * (1 - ratio) + g2 * ratio),
            Math.round(b1 * (1 - ratio) + b2 * ratio)
        );
    }
    
    /**
     * Calculate contrast ratio between two colors (WCAG)
     * @param color1 First color
     * @param color2 Second color
     * @return Contrast ratio (1-21)
     */
    public static float getContrastRatio(int color1, int color2) {
        float l1 = getRelativeLuminance(color1);
        float l2 = getRelativeLuminance(color2);
        
        float lighter = Math.max(l1, l2);
        float darker = Math.min(l1, l2);
        
        return (lighter + 0.05f) / (darker + 0.05f);
    }
    
    /**
     * Get relative luminance (WCAG)
     * @param color The color
     * @return Relative luminance (0-1)
     */
    private static float getRelativeLuminance(int color) {
        float r = Color.red(color) / 255f;
        float g = Color.green(color) / 255f;
        float b = Color.blue(color) / 255f;
        
        r = r <= 0.03928f ? r / 12.92f : (float) Math.pow((r + 0.055f) / 1.055f, 2.4f);
        g = g <= 0.03928f ? g / 12.92f : (float) Math.pow((g + 0.055f) / 1.055f, 2.4f);
        b = b <= 0.03928f ? b / 12.92f : (float) Math.pow((b + 0.055f) / 1.055f, 2.4f);
        
        return 0.2126f * r + 0.7152f * g + 0.0722f * b;
    }
    
    /**
     * Check if a color is perceived as light
     * @param color The color to check
     * @return true if color is light, false if dark
     */
    public static boolean isLight(int color) {
        return getRelativeLuminance(color) > 0.5f;
    }
    
    /**
     * Get contrasting text color (black or white) for a background
     * @param backgroundColor The background color
     * @return Color.BLACK or Color.WHITE
     */
    public static int getContrastingTextColor(int backgroundColor) {
        return isLight(backgroundColor) ? Color.BLACK : Color.WHITE;
    }
    
    /**
     * Apply alpha channel to color
     * @param color The base color
     * @param alpha Alpha value (0-255)
     * @return Color with new alpha
     */
    public static int withAlpha(int color, int alpha) {
        return Color.argb(
            alpha,
            Color.red(color),
            Color.green(color),
            Color.blue(color)
        );
    }
    
    /**
     * Get alpha channel from color
     * @param color The color
     * @return Alpha value (0-255)
     */
    public static int getAlpha(int color) {
        return Color.alpha(color);
    }
    
    /**
     * Invert a color
     * @param color The color to invert
     * @return Inverted color
     */
    public static int invert(int color) {
        return Color.argb(
            Color.alpha(color),
            255 - Color.red(color),
            255 - Color.green(color),
            255 - Color.blue(color)
        );
    }
}
