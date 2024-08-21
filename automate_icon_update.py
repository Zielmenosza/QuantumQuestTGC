import os
from PIL import Image

# Paths to directories
icon_source = r'C:\Users\Ziel\AndroidStudioProjects\QuantumQuest\app\src\main\res\drawable\icon_1.png'
project_root = r'C:\Users\Ziel\AndroidStudioProjects\QuantumQuest\app\src\main\res'
mipmap_dirs = {
    'mipmap-mdpi': (48, 48),
    'mipmap-hdpi': (72, 72),
    'mipmap-xhdpi': (96, 96),
    'mipmap-xxhdpi': (144, 144),
    'mipmap-xxxhdpi': (192, 192),
}

def resize_and_save(icon_path, output_path, size):
    """Resize and save the icon to the specified path and size."""
    with Image.open(icon_path) as img:
        img = img.resize(size, Image.ANTIALIAS)
        img.save(output_path, format='png')
    print(f"Saved resized icon to {output_path}")

def main():
    # Create the necessary directories if they don't exist
    for dir_name, (width, height) in mipmap_dirs.items():
        dir_path = os.path.join(project_root, dir_name)
        os.makedirs(dir_path, exist_ok=True)
        output_path = os.path.join(dir_path, 'ic_launcher.png')
        resize_and_save(icon_source, output_path, (width, height))
    
    print("Icon update complete. Please check your project.")

if __name__ == '__main__':
    main()