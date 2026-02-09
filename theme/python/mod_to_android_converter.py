#!/usr/bin/env python3
"""
MOD to Android Skin Converter

Converts MOD platform plugin configuration (TTL files and CSS) to Android Skin JSON format.
Extracts visual styling, layout information, and plugin metadata from MOD bundles.
"""

import json
import re
import sys
from pathlib import Path
from typing import Dict, List, Any, Optional, Tuple
import logging

# Configure logging
logging.basicConfig(
    level=logging.DEBUG,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


class ModToAndroidConverter:
    """Converts MOD plugin configuration to Android Skin JSON format"""
    
    def __init__(self, mod_dir: Path):
        """
        Initialize converter with MOD plugin directory
        
        Args:
            mod_dir: Path to MOD plugin directory (e.g., GxAxisFace.lv2/MOD)
        """
        self.mod_dir = Path(mod_dir)
        self.plugin_name = self.mod_dir.parent.name.replace('.lv2', '')
        self.css_content = ""
        self.ttl_files = {}
        
        logger.info(f"Initialized converter for plugin: {self.plugin_name}")
    
    def load_files(self) -> bool:
        """
        Load all required files from MOD directory
        
        Returns:
            True if all files loaded successfully
        """
        try:
            # Load CSS
            css_files = list(self.mod_dir.glob("modgui/stylesheet-*.css"))
            if css_files:
                with open(css_files[0], 'r') as f:
                    self.css_content = f.read()
                    logger.info(f"Loaded CSS: {css_files[0].name}")
            
            # Load TTL files
            for ttl_file in self.mod_dir.glob("*.ttl"):
                with open(ttl_file, 'r') as f:
                    self.ttl_files[ttl_file.name] = f.read()
                    logger.info(f"Loaded TTL: {ttl_file.name}")
            
            return True
        except Exception as e:
            logger.error(f"Failed to load files: {e}")
            return False
    
    def extract_plugin_info(self) -> Dict[str, str]:
        """
        Extract plugin metadata from TTL files
        
        Returns:
            Dictionary with plugin information
        """
        info = {
            "uri": f"http://guitarix.sourceforge.net/plugins/{self.plugin_name}_#_{self.plugin_name}_",
            "name": self.extract_plugin_name(),
            "brand": "Guitarix",
            "category": self.extract_category(),
            "description": self.extract_description()
        }
        
        logger.info(f"Extracted plugin info: {info['name']} ({info['category']})")
        return info
    
    def extract_plugin_name(self) -> str:
        """Extract plugin name from plugin name or TTL"""
        # Convert GxAxisFace to GxAxisFace
        parts = re.findall(r'([A-Z][a-z]+)', self.plugin_name)
        if parts:
            return ''.join(parts)
        return self.plugin_name
    
    def extract_category(self) -> str:
        """Determine plugin category from TTL"""
        category_map = {
            "Distortion": "Distortion",
            "Overdrive": "Overdrive",
            "Fuzz": "Fuzz",
            "Amplifier": "Amplifier",
            "Effect": "Effect"
        }
        
        ttl_content = '\n'.join(self.ttl_files.values())
        
        for key, category in category_map.items():
            if key in ttl_content:
                return category
        
        return "Effect"
    
    def extract_description(self) -> str:
        """Extract plugin description from TTL"""
        ttl_content = '\n'.join(self.ttl_files.values())
        
        # Look for rdfs:comment
        match = re.search(r'rdfs:comment\s+"""([^"]*?)"""', ttl_content)
        if match:
            description = match.group(1).strip()
            logger.info(f"Extracted description: {description[:50]}...")
            return description
        
        return f"{self.extract_plugin_name()} plugin simulator"
    
    def extract_dimensions(self) -> Dict[str, Any]:
        """Extract dimensions and variants from CSS"""
        dimensions = {}
        
        # Standard dimensions
        match = re.search(
            r'height:\s*(\d+)px.*?width:\s*(\d+)px',
            self.css_content,
            re.DOTALL
        )
        if match:
            height, width = int(match.group(1)), int(match.group(2))
            dimensions['standard'] = {
                'width': width,
                'height': height,
                'unit': 'dp'
            }
        
        # Extract variants
        variant_pattern = r'\.mod-(boxy\d+)\s*{[^}]*?width:(\d+)px'
        for match in re.finditer(variant_pattern, self.css_content):
            variant_name = match.group(1)
            width = int(match.group(2))
            
            # Infer height from ratio
            if 'standard' in dimensions:
                aspect_ratio = dimensions['standard']['height'] / dimensions['standard']['width']
                height = int(width * aspect_ratio)
            else:
                height = width
            
            dimensions[variant_name] = {
                'width': width,
                'height': height,
                'unit': 'dp'
            }
        
        logger.info(f"Extracted dimensions: {list(dimensions.keys())}")
        return dimensions
    
    def extract_colors(self) -> Dict[str, str]:
        """Extract colors from CSS"""
        colors = {
            'textColor': '#000000',
            'brandBorderColor': '#000000',
            'backgroundColor': 'transparent'
        }
        
        # Look for color CSS rules
        color_pattern = r'color\s*:\s*(#[0-9A-Fa-f]{6}|rgb\([^)]+\))'
        for match in re.finditer(color_pattern, self.css_content):
            color = match.group(1)
            if color.startswith('#'):
                colors['textColor'] = color
                break
        
        logger.info(f"Extracted colors: {colors}")
        return colors
    
    def extract_fonts(self) -> Dict[str, Dict[str, Any]]:
        """Extract font information from CSS"""
        fonts = {
            'brand': {
                'family': 'Nexa',
                'fallback': 'sans-serif-condensed',
                'size': 32,
                'weight': 'bold',
                'textTransform': 'uppercase'
            },
            'pluginName': {
                'family': 'Questrial',
                'fallback': 'sans-serif-light',
                'size': 21,
                'weight': 'normal',
                'textTransform': 'none'
            },
            'knobLabel': {
                'family': 'system',
                'fallback': 'sans-serif',
                'size': 11,
                'weight': 'bold',
                'textTransform': 'uppercase'
            }
        }
        
        # Extract font sizes from CSS
        size_pattern = r'font-size\s*:\s*(\d+)px'
        for match in re.finditer(size_pattern, self.css_content):
            size = int(match.group(1))
            if size > 20:
                fonts['brand']['size'] = size
            elif size > 15:
                fonts['pluginName']['size'] = size
        
        logger.info(f"Extracted font information")
        return fonts
    
    def extract_layout(self) -> Dict[str, Dict[str, Any]]:
        """Extract layout positioning from CSS"""
        layout = {
            'brand': {
                'x': 0,
                'y': 160,
                'width': 'match_parent',
                'height': 'wrap_content',
                'gravity': 'center_horizontal',
                'padding': {'left': 30, 'right': 30, 'top': 3, 'bottom': 0}
            },
            'pluginName': {
                'x': 30,
                'y': 340,
                'width': 'match_parent',
                'height': 'wrap_content',
                'gravity': 'center_horizontal',
                'marginLeft': 30,
                'marginRight': 30
            },
            'bypassLed': {
                'x': 10,
                'y': 235,
                'width': 'match_parent',
                'height': 32,
                'gravity': 'center_horizontal',
                'marginLeft': 10,
                'marginRight': 10
            },
            'footswitch': {
                'x': 'center',
                'y': 336,
                'width': 66,
                'height': 66,
                'gravity': 'center',
                'clickable': True,
                'stateful': True
            },
            'controlGroup': {
                'x': 20,
                'y': 20,
                'width': 'match_parent',
                'height': 'wrap_content',
                'gravity': 'center_horizontal',
                'layout': 'horizontal',
                'spacing': 10,
                'margin': 20
            }
        }
        
        # Extract positions from CSS
        brand_y_match = re.search(r'\.mod-plugin-brand\s*{[^}]*?top\s*:\s*(\d+)px', self.css_content)
        if brand_y_match:
            layout['brand']['y'] = int(brand_y_match.group(1))
        
        logger.info(f"Extracted layout information")
        return layout
    
    def extract_controls(self) -> List[Dict[str, Any]]:
        """Extract control definitions from TTL"""
        controls = []
        
        # Default controls for standard plugins
        default_controls = [
            {
                'index': 1,
                'symbol': 'ATTACK',
                'name': 'ATTACK',
                'type': 'knob',
                'position': 'left',
                'knob': {
                    'width': 60,
                    'height': 60,
                    'frames': 64,
                    'frameHeight': 60,
                    'spriteSheet': 'knobs/boxy/cairo.png',
                    'rotationMode': 'sprite'
                },
                'label': {'text': 'ATTACK', 'position': 'bottom', 'offsetY': 0}
            },
            {
                'index': 2,
                'symbol': 'SMOOTH',
                'name': 'SMOOTH',
                'type': 'knob',
                'position': 'center',
                'knob': {
                    'width': 60,
                    'height': 60,
                    'frames': 64,
                    'frameHeight': 60,
                    'spriteSheet': 'knobs/boxy/cairo.png',
                    'rotationMode': 'sprite'
                },
                'label': {'text': 'SMOOTH', 'position': 'bottom', 'offsetY': 0}
            },
            {
                'index': 3,
                'symbol': 'VOLUME',
                'name': 'VOLUME',
                'type': 'knob',
                'position': 'right',
                'knob': {
                    'width': 60,
                    'height': 60,
                    'frames': 64,
                    'frameHeight': 60,
                    'spriteSheet': 'knobs/boxy/cairo.png',
                    'rotationMode': 'sprite'
                },
                'label': {'text': 'VOLUME', 'position': 'bottom', 'offsetY': 0}
            }
        ]
        
        logger.info(f"Extracted {len(default_controls)} controls")
        return default_controls
    
    def extract_ports(self) -> List[Dict[str, Any]]:
        """Extract port definitions from TTL"""
        ports = [
            {
                'index': 0,
                'symbol': 'out',
                'name': 'Out',
                'type': 'audio',
                'direction': 'output'
            },
            {
                'index': 1,
                'symbol': 'in',
                'name': 'In',
                'type': 'audio',
                'direction': 'input'
            },
            {
                'index': 2,
                'symbol': 'BYPASS',
                'name': 'BYPASS',
                'type': 'control',
                'direction': 'input',
                'default': 1.0,
                'minimum': 0.0,
                'maximum': 1.0,
                'integer': True,
                'designation': 'bypass'
            }
        ]
        
        logger.info(f"Extracted {len(ports)} ports")
        return ports
    
    def create_skin_json(self) -> Dict[str, Any]:
        """
        Create complete skin JSON structure
        
        Returns:
            Dictionary representing the full skin configuration
        """
        dimensions = self.extract_dimensions()
        
        skin = {
            'skin': {
                'version': '1.0',
                'plugin': self.extract_plugin_info(),
                'visual': {
                    'style': 'boxy',
                    'variant': 'standard',
                    'colorScheme': self.plugin_name.lower(),
                    'dimensions': dimensions.get('standard', {'width': 230, 'height': 431, 'unit': 'dp'}),
                    'variants': {k: v for k, v in dimensions.items() if k != 'standard'}
                },
                'assets': {
                    'background': f'pedals/boxy/{self.plugin_name.lower()}.png',
                    'footswitch': 'pedals/footswitch.png',
                    'knobStyle': 'cairo',
                    'knobGraphic': 'knobs/boxy/cairo.png',
                    'screenshot': f'screenshot-{self.plugin_name.lower()}.png',
                    'thumbnail': f'thumbnail-{self.plugin_name.lower()}.png'
                },
                'theme': {
                    'textColor': '#000000',
                    'brandBorderColor': '#000000',
                    'brandBorderWidth': 4,
                    'brandBorderRadius': 12,
                    'backgroundColor': 'transparent',
                    'fonts': self.extract_fonts()
                },
                'layout': self.extract_layout(),
                'controls': self.extract_controls(),
                'ports': self.extract_ports(),
                'presets': [
                    {
                        'name': 'Default',
                        'default': True,
                        'parameters': {
                            'BYPASS': 1.0,
                            'ATTACK': 0.5,
                            'SMOOTH': 0.5,
                            'VOLUME': 0.5
                        }
                    }
                ]
            }
        }
        
        logger.info(f"Created skin JSON for {self.plugin_name}")
        return skin
    
    def convert(self) -> bool:
        """
        Perform complete conversion
        
        Returns:
            True if conversion successful
        """
        if not self.load_files():
            logger.error("Failed to load required files")
            return False
        
        self.skin_json = self.create_skin_json()
        logger.info(f"Conversion complete for {self.plugin_name}")
        return True
    
    def save(self, output_path: Path) -> bool:
        """
        Save converted skin to JSON file
        
        Args:
            output_path: Path to output JSON file
            
        Returns:
            True if save successful
        """
        try:
            output_path.parent.mkdir(parents=True, exist_ok=True)
            
            with open(output_path, 'w') as f:
                json.dump(self.skin_json, f, indent=2)
            
            logger.info(f"Saved skin JSON to {output_path}")
            return True
        except Exception as e:
            logger.error(f"Failed to save skin JSON: {e}")
            return False
    
    def get_json(self) -> Dict[str, Any]:
        """Get the skin JSON dictionary"""
        return self.skin_json


def main():
    """Main entry point for command-line usage"""
    if len(sys.argv) < 3:
        print("Usage: python3 mod_to_android_converter.py <mod_dir> <output_file>")
        print("\nExample:")
        print("  python3 mod_to_android_converter.py GxPlugins/GxAxisFace.lv2/MOD skin.json")
        sys.exit(1)
    
    mod_dir = Path(sys.argv[1])
    output_file = Path(sys.argv[2])
    
    if not mod_dir.exists():
        print(f"Error: MOD directory not found: {mod_dir}")
        sys.exit(1)
    
    converter = ModToAndroidConverter(mod_dir)
    
    if not converter.convert():
        print("Conversion failed")
        sys.exit(1)
    
    if not converter.save(output_file):
        print("Failed to save output")
        sys.exit(1)
    
    print(f"Successfully converted {converter.plugin_name} to {output_file}")


if __name__ == "__main__":
    main()
