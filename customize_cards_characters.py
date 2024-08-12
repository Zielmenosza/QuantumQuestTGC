import os

# Paths to the repository files
card_repo_path = "C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/app/src/main/java/com/example/quantumquest/repository/CardRepository.kt"
character_repo_path = "C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/app/src/main/java/com/example/quantumquest/repository/CharacterRepository.kt"

# Card data to add
cards = [
    {"id": 1, "name": "Fireball", "description": "A powerful fire spell", "power": 10, "rarity": "Common", "cardType": "Spell"},
    {"id": 2, "name": "Sword of Destiny", "description": "Legendary sword with immense power", "power": 20, "rarity": "Rare", "cardType": "Artifact"},
    # Add the remaining 70 cards here...
]

# Character data to add
characters = [
    {"id": 1, "name": "Chrono Knight", "health": 100, "attack": 20, "description": "A warrior with control over time"},
    {"id": 2, "name": "Pixel Sorceress", "health": 80, "attack": 25, "description": "A mage who can manipulate pixels"},
    # Add the remaining characters here...
]

def write_to_repository(file_path, model_name, data):
    """Write the card or character data to the respective repository file."""
    if not os.path.exists(file_path):
        print(f"File not found: {file_path}")
        return

    lines = [
        f"package com.example.quantumquest.repository\n",
        f"import com.example.quantumquest.model.{model_name}\n",
        f"object {model_name}Repository {{\n",
        f"    val {model_name.lower()}s = listOf(\n"
    ]

    for entry in data:
        entry_str = ", ".join([f'{key} = "{value}"' if isinstance(value, str) else f'{key} = {value}' for key, value in entry.items()])
        lines.append(f"        {model_name}({entry_str}),\n")

    lines.append(f"    )\n")
    lines.append(f"}}\n")

    with open(file_path, 'w') as f:
        f.writelines(lines)

    print(f"{model_name} data added to {file_path}")

# Write cards to CardRepository.kt
write_to_repository(card_repo_path, "Card", cards)

# Write characters to CharacterRepository.kt
write_to_repository(character_repo_path, "Character", characters)

print("Cards and characters have been updated in the repositories.")