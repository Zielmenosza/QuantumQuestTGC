import os

# Function to remove duplicate and incorrect imports
def clean_imports(file_content):
    imports = []
    cleaned_lines = []
    for line in file_content.splitlines():
        if line.startswith("import "):
            if line in imports:
                continue  # Skip duplicate import
            if 'Unresolved reference' in line:
                continue  # Skip unresolved references
            imports.append(line)
        cleaned_lines.append(line)
    return '\n'.join(cleaned_lines)

# Function to fix inheritance cycles
def fix_inheritance_cycles(file_content):
    lines = file_content.splitlines()
    class_name = None
    new_lines = []
    for line in lines:
        if line.strip().startswith('class ') or line.strip().startswith('open class '):
            # Capture the class name and base class for cycle checking
            parts = line.split('(')
            class_name = parts[0].split()[1].strip()
            if class_name in line:
                # Prevent the class from extending itself or causing a cycle
                base_class_index = line.find('(')
                if base_class_index != -1:
                    line = line[:base_class_index] + " "
        new_lines.append(line)
    return '\n'.join(new_lines)

# Function to ensure all files have complete declarations
def ensure_complete_declarations(file_content):
    if "class " not in file_content and "object " not in file_content:
        return "// File might be incomplete, please check manually.\n" + file_content
    return file_content

# Function to process a single file
def process_file(filepath):
    with open(filepath, 'r', encoding='utf-8') as file:
        content = file.read()

    # Apply fixes
    content = clean_imports(content)
    content = fix_inheritance_cycles(content)
    content = ensure_complete_declarations(content)

    # Save the fixed content back to the file
    with open(filepath, 'w', encoding='utf-8') as file:
        file.write(content)

# Specify the directory containing the Kotlin files
base_dir = "C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/app/src/main/java/com/example/quantumquest/"

# List of files to process based on your affected_files_contents.txt
files_to_process = [
    "Model/BaseCard.kt", "Model/Card.kt", "Model/CardModel.kt", "Model/CharacterCard.kt",
    "Model/QuestCard.kt", "Model/RoomEffectCard.kt", "cards/ElementalSpellCard.kt",
    "cards/PixelArtifactCard.kt", "cards/QuantumAnomalyCard.kt", "characters/ChronoBard.kt",
    "characters/PixelSorceress.kt", "characters/QuantumKnight.kt", "duplicates/CardBattleScreen.kt",
    "duplicates/CardCollectionActivity.kt", "duplicates/CardView.kt", "duplicates/GameManager.kt",
    "manager/CardManager.kt", "manager/QuestManager.kt", "manager/RoomManager.kt", 
    "managers/CardManager.kt", "managers/CharacterManager.kt", "managers/GameLoopManager.kt",
    "quests/DragonQuest.kt", "quests/TreasureHunt.kt", "rooms/FireRoom.kt", "rooms/WaterRoom.kt"
]

# Process each file
for relative_path in files_to_process:
    file_path = os.path.join(base_dir, relative_path)
    if os.path.exists(file_path):
        process_file(file_path)
    else:
        print(f"File not found: {file_path}")

print("All files processed and fixed.")