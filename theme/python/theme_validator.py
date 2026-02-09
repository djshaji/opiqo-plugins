#!/usr/bin/env python3
"""
Skin JSON Validator

Validates Android skin JSON files against schema, checks for completeness,
and provides detailed error reporting for debugging theme issues.
"""

import json
import sys
from pathlib import Path
from typing import Dict, List, Tuple, Optional
import logging

logging.basicConfig(
    level=logging.INFO,
    format='%(levelname)s: %(message)s'
)
logger = logging.getLogger(__name__)


class ValidationResult:
    """Holds validation results with errors and warnings"""
    
    def __init__(self):
        self.errors = []
        self.warnings = []
        self.valid = True
    
    def add_error(self, message: str):
        """Add validation error"""
        self.errors.append(message)
        self.valid = False
    
    def add_warning(self, message: str):
        """Add validation warning"""
        self.warnings.append(message)
    
    def is_valid(self) -> bool:
        """Check if validation passed"""
        return self.valid
    
    def __str__(self) -> str:
        """Format results for display"""
        lines = []
        
        if self.errors:
            lines.append(f"\n❌ Validation Failed ({len(self.errors)} errors):")
            for i, error in enumerate(self.errors, 1):
                lines.append(f"   {i}. {error}")
        
        if self.warnings:
            lines.append(f"\n⚠️  Warnings ({len(self.warnings)}):")
            for i, warning in enumerate(self.warnings, 1):
                lines.append(f"   {i}. {warning}")
        
        if self.valid:
            lines.append("\n✅ Validation Passed!")
        
        return '\n'.join(lines)


class SkinValidator:
    """Validates skin JSON against expected schema"""
    
    # Required fields at top level
    REQUIRED_FIELDS = {
        'skin': {
            'plugin': ['uri', 'name', 'brand', 'category'],
            'visual': ['style', 'variant', 'colorScheme', 'dimensions'],
            'assets': ['background'],
            'theme': ['textColor'],
            'layout': ['brand', 'pluginName', 'footswitch'],
            'controls': [],
            'ports': [],
            'presets': []
        }
    }
    
    def __init__(self):
        self.result = ValidationResult()
        self.data = None
    
    def load_json(self, file_path: Path) -> bool:
        """Load and parse JSON file"""
        try:
            with open(file_path, 'r') as f:
                self.data = json.load(f)
            logger.info(f"Loaded JSON: {file_path}")
            return True
        except json.JSONDecodeError as e:
            self.result.add_error(f"Invalid JSON: {e}")
            return False
        except FileNotFoundError:
            self.result.add_error(f"File not found: {file_path}")
            return False
    
    def validate(self) -> ValidationResult:
        """Run all validation checks"""
        if self.data is None:
            self.result.add_error("No data loaded")
            return self.result
        
        # Structural validation
        self._validate_structure()
        
        # Content validation
        if self.result.is_valid():
            self._validate_content()
        
        return self.result
    
    def _validate_structure(self):
        """Validate JSON structure"""
        if 'skin' not in self.data:
            self.result.add_error("Missing 'skin' root object")
            return
        
        skin = self.data['skin']
        
        # Check required top-level fields
        for field in ['version', 'plugin', 'visual', 'assets', 'theme', 'layout', 'controls', 'ports']:
            if field not in skin:
                self.result.add_error(f"Missing required field: skin.{field}")
        
        # Validate plugin object
        if 'plugin' in skin:
            plugin = skin['plugin']
            for field in self.REQUIRED_FIELDS['skin']['plugin']:
                if field not in plugin or not plugin[field]:
                    self.result.add_error(f"Missing or empty: skin.plugin.{field}")
        
        # Validate visual object
        if 'visual' in skin:
            visual = skin['visual']
            for field in self.REQUIRED_FIELDS['skin']['visual']:
                if field not in visual:
                    self.result.add_error(f"Missing: skin.visual.{field}")
        
        # Validate ports
        if 'ports' in skin and isinstance(skin['ports'], list):
            if len(skin['ports']) == 0:
                self.result.add_error("No ports defined in skin.ports")
            else:
                for i, port in enumerate(skin['ports']):
                    for field in ['index', 'symbol', 'name', 'type', 'direction']:
                        if field not in port:
                            self.result.add_error(f"Missing field in port[{i}]: {field}")
    
    def _validate_content(self):
        """Validate content and cross-references"""
        skin = self.data.get('skin', {})
        
        # Validate controls reference ports
        controls = skin.get('controls', [])
        ports_by_symbol = {p['symbol']: p for p in skin.get('ports', []) if 'symbol' in p}
        
        for control in controls:
            symbol = control.get('symbol')
            if symbol and symbol not in ports_by_symbol:
                self.result.add_warning(f"Control '{symbol}' has no corresponding port")
        
        # Validate presets reference ports
        presets = skin.get('presets', [])
        for preset in presets:
            if 'parameters' in preset:
                for param_name in preset['parameters'].keys():
                    if param_name not in ports_by_symbol:
                        self.result.add_warning(
                            f"Preset '{preset.get('name')}' references unknown parameter: {param_name}"
                        )
        
        # Check for at least one default preset
        has_default = any(p.get('default', False) for p in presets)
        if not has_default and presets:
            self.result.add_warning("No default preset specified")
        
        # Validate asset paths
        assets = skin.get('assets', {})
        for asset_name, asset_path in assets.items():
            if not asset_path:
                self.result.add_warning(f"Empty asset path for: {asset_name}")
            elif not isinstance(asset_path, str):
                self.result.add_error(f"Asset path must be string: {asset_name}")
        
        # Validate theme colors
        theme = skin.get('theme', {})
        color_fields = ['textColor', 'brandBorderColor', 'backgroundColor']
        for field in color_fields:
            if field in theme:
                color = theme[field]
                if not self._is_valid_color(color):
                    self.result.add_warning(f"Invalid color format: {field} = {color}")
        
        # Validate port ranges
        for port in skin.get('ports', []):
            if port.get('type') == 'control':
                minimum = port.get('minimum', 0.0)
                maximum = port.get('maximum', 1.0)
                default = port.get('default', 0.5)
                
                if not isinstance(minimum, (int, float)):
                    self.result.add_error(f"Port '{port['symbol']}': minimum must be number")
                if not isinstance(maximum, (int, float)):
                    self.result.add_error(f"Port '{port['symbol']}': maximum must be number")
                if minimum >= maximum:
                    self.result.add_error(
                        f"Port '{port['symbol']}': minimum ({minimum}) >= maximum ({maximum})"
                    )
                if not (minimum <= default <= maximum):
                    self.result.add_warning(
                        f"Port '{port['symbol']}': default ({default}) out of range [{minimum}, {maximum}]"
                    )
    
    @staticmethod
    def _is_valid_color(color: str) -> bool:
        """Check if color string is valid"""
        if not isinstance(color, str):
            return False
        
        # Valid hex color
        if color.startswith('#'):
            if len(color) in [7, 9]:  # #RRGGBB or #AARRGGBB
                try:
                    int(color[1:], 16)
                    return True
                except ValueError:
                    return False
        
        # Named color
        if color in ['transparent', 'black', 'white', 'red', 'green', 'blue']:
            return True
        
        # RGB format
        if color.startswith('rgb('):
            return True
        
        return False
    
    def get_summary(self) -> Dict[str, any]:
        """Get validation summary"""
        if self.data is None:
            return {'status': 'error', 'message': 'No data loaded'}
        
        skin = self.data.get('skin', {})
        
        return {
            'status': 'valid' if self.result.is_valid() else 'invalid',
            'plugin_name': skin.get('plugin', {}).get('name', 'Unknown'),
            'plugin_category': skin.get('plugin', {}).get('category', 'Unknown'),
            'num_controls': len(skin.get('controls', [])),
            'num_ports': len(skin.get('ports', [])),
            'num_presets': len(skin.get('presets', [])),
            'errors': len(self.result.errors),
            'warnings': len(self.result.warnings)
        }


def batch_validate(directory: Path) -> Tuple[int, int, int]:
    """
    Validate all skin JSON files in a directory
    
    Args:
        directory: Path to directory containing skin.json files
        
    Returns:
        Tuple of (total, valid, invalid)
    """
    total = 0
    valid = 0
    invalid = 0
    
    for skin_file in directory.rglob('skin.json'):
        total += 1
        validator = SkinValidator()
        
        if validator.load_json(skin_file):
            result = validator.validate()
            if result.is_valid():
                valid += 1
                logger.info(f"✅ {skin_file}: Valid")
            else:
                invalid += 1
                logger.error(f"❌ {skin_file}: Invalid")
                for error in result.errors:
                    logger.error(f"   - {error}")
        else:
            invalid += 1
    
    return total, valid, invalid


def main():
    """Main entry point"""
    if len(sys.argv) < 2:
        print("Usage: python3 theme_validator.py <skin.json> [--batch <directory>]")
        print("\nExamples:")
        print("  python3 theme_validator.py skin.json")
        print("  python3 theme_validator.py --batch skins/")
        sys.exit(1)
    
    if sys.argv[1] == '--batch' and len(sys.argv) > 2:
        # Batch validation mode
        directory = Path(sys.argv[2])
        if not directory.is_dir():
            print(f"Error: Directory not found: {directory}")
            sys.exit(1)
        
        print(f"Validating all skins in {directory}...")
        total, valid, invalid = batch_validate(directory)
        
        print(f"\nResults: {valid}/{total} valid, {invalid} invalid")
        sys.exit(0 if invalid == 0 else 1)
    
    else:
        # Single file validation
        skin_file = Path(sys.argv[1])
        
        validator = SkinValidator()
        if not validator.load_json(skin_file):
            print(validator.result)
            sys.exit(1)
        
        result = validator.validate()
        print(validator.result)
        
        # Print summary
        print("\n" + "="*50)
        summary = validator.get_summary()
        print(f"Plugin: {summary['plugin_name']} ({summary['plugin_category']})")
        print(f"Controls: {summary['num_controls']}")
        print(f"Ports: {summary['num_ports']}")
        print(f"Presets: {summary['num_presets']}")
        
        sys.exit(0 if result.is_valid() else 1)


if __name__ == "__main__":
    main()
