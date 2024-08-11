import os
import re

project_dir = "C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/app/src/main/java/com/example/quantumquest"

# List of all cards, characters, managers, and other classes that should be imported
class_names = [
    "QuantumAnomalyCard", "ChronoBard", "PixelSorceress", "QuantumKnight",
    "Card", "CharacterCard", "QuestCard", "RoomEffectCard",
    "CardManager", "CharacterManager", "QuestManager", "RoomManager",
    "DragonQuest", "TreasureHunt", "FireRoom", "WaterRoom"
]

# Function to add imports after the package declaration
def add_imports(file_path, imports):
    with open(file_path, 'r') as f:
        content = f.read()

    # Find the package declaration
    package_decl_match = re.search(r'^(package\s+[a-zA-Z0-9\._]+)', content, re.MULTILINE)
    if not package_decl_match:
        print(f"No package declaration found in {file_path}. Skipping import addition.")
        return

    # Add imports right after the package declaration
    package_decl_end = package_decl_match.end()
    updated_content = content[:package_decl_end] + "\n" + "\n".join(imports) + "\n" + content[package_decl_end:]

    with open(file_path, 'w') as f:
        f.write(updated_content)
    print(f"Added missing imports to {file_path}")

# Check all files in the project directory
for subdir, _, files in os.walk(project_dir):
    for file in files:
        if file.endswith(".kt"):
            file_path = os.path.join(subdir, file)
            with open(file_path, 'r') as f:
                content = f.read()
            
            # Check for missing imports
            missing_imports = []
            for class_name in class_names:
                if class_name in content and f"import com.example.quantumquest.{class_name}" not in content:
                    # Class is used but not imported
                    missing_imports.append(f"import com.example.quantumquest.{class_name}")

            # If there are missing imports, add them
            if missing_imports:
                add_imports(file_path, missing_imports)

print("Fixing script executed. Please rebuild your project.")
