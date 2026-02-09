package com.opiqo.theme;

/**
 * UserTheme represents user-customizable theme attributes.
 * Allows customization of colors and visual properties without modifying the base skin.
 */
public class UserTheme {
    private String textColor;
    private String accentColor;
    private String backgroundColor;
    private boolean darkMode;
    
    public UserTheme() {
        this.darkMode = false;
    }
    
    /**
     * Create theme with specific colors
     * @param textColor Color for text (hex format)
     * @param accentColor Color for accents/borders (hex format)
     */
    public UserTheme(String textColor, String accentColor) {
        this.textColor = textColor;
        this.accentColor = accentColor;
        this.darkMode = false;
    }
    
    /**
     * Create dark mode theme
     * @return Dark theme preset
     */
    public static UserTheme darkMode() {
        UserTheme theme = new UserTheme();
        theme.setTextColor("#FFFFFF");
        theme.setAccentColor("#BB86FC");
        theme.setBackgroundColor("#121212");
        theme.setDarkMode(true);
        return theme;
    }
    
    /**
     * Create light mode theme (default)
     * @return Light theme preset
     */
    public static UserTheme lightMode() {
        UserTheme theme = new UserTheme();
        theme.setTextColor("#000000");
        theme.setAccentColor("#2196F3");
        theme.setBackgroundColor("#FFFFFF");
        theme.setDarkMode(false);
        return theme;
    }
    
    /**
     * Get color for text elements
     * @return Text color in hex format
     */
    public String getTextColor() {
        return textColor;
    }
    
    /**
     * Set color for text elements
     * @param textColor Color in hex format (e.g., "#000000")
     */
    public void setTextColor(String textColor) {
        this.textColor = textColor;
    }
    
    /**
     * Get color for accent elements (borders, highlights)
     * @return Accent color in hex format
     */
    public String getAccentColor() {
        return accentColor;
    }
    
    /**
     * Set color for accent elements
     * @param accentColor Color in hex format
     */
    public void setAccentColor(String accentColor) {
        this.accentColor = accentColor;
    }
    
    /**
     * Get background color
     * @return Background color in hex format
     */
    public String getBackgroundColor() {
        return backgroundColor;
    }
    
    /**
     * Set background color
     * @param backgroundColor Color in hex format
     */
    public void setBackgroundColor(String backgroundColor) {
        this.backgroundColor = backgroundColor;
    }
    
    /**
     * Check if dark mode is enabled
     * @return true if dark mode
     */
    public boolean isDarkMode() {
        return darkMode;
    }
    
    /**
     * Set dark mode
     * @param darkMode true for dark mode, false for light mode
     */
    public void setDarkMode(boolean darkMode) {
        this.darkMode = darkMode;
    }
    
    /**
     * Clone this theme
     * @return Copy of this theme
     */
    public UserTheme clone() {
        UserTheme clone = new UserTheme();
        clone.textColor = this.textColor;
        clone.accentColor = this.accentColor;
        clone.backgroundColor = this.backgroundColor;
        clone.darkMode = this.darkMode;
        return clone;
    }
    
    @Override
    public String toString() {
        return "UserTheme{" +
                "textColor='" + textColor + '\'' +
                ", accentColor='" + accentColor + '\'' +
                ", backgroundColor='" + backgroundColor + '\'' +
                ", darkMode=" + darkMode +
                '}';
    }
}
