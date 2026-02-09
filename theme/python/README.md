# Python Theme System - No External Dependencies

The Python theme utilities (`mod_to_android_converter.py` and `theme_validator.py`) use only 
Python standard library:

- `json` - JSON parsing and serialization
- `pathlib` - Cross-platform file path handling
- `logging` - Debug logging
- `re` - Regular expressions
- `sys` - System utilities
- `typing` - Type hints

## Installation

Simply copy the Python files to your project:

```bash
cp theme/python/*.py /path/to/your/project
```

## Running Scripts

```bash
# Convert MOD skin
python3 mod_to_android_converter.py <mod_dir> <output.json>

# Validate skin
python3 theme_validator.py <skin.json>
```

No pip install required! All utilities work with Python 3.6+.
