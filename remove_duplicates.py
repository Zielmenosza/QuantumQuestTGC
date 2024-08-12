import os

# Paths to the repository files
card_repo_path = "C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/app/src/main/java/com/example/quantumquest/repository/CardRepository.kt"
character_repo_path = "C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/app/src/main/java/com/example/quantumquest/repository/CharacterRepository.kt"

def remove_duplicates(file_path, model_name):
    """Remove duplicate entries from the repository file."""
    if not os.path.exists(file_path):
        print(f"File not found: {file_path}")
        return

    with open(file_path, 'r') as f:
        lines = f.readlines()

    # Extract the data lines that contain the entries
    data_lines = [line.strip() for line in lines if line.strip().startswith(f"{model_name}(")]

    # Remove duplicates by converting the list to a set, then back to a list
    unique_data_lines = list(set(data_lines))

    # Sort the entries by ID or name (optional)
    unique_data_lines.sort()

    # Reconstruct the file content
    start_index = lines.index(next(line for line in lines if line.strip().startswith("val")))
    end_index = start_index + len(data_lines)

    new_lines = lines[:start_index + 1]  # Keep the lines before the data
    for line in unique_data_lines:
        new_lines.append(f"        {line},\n")
    new_lines.append(lines[end_index])  # Add the closing lines

    # Write the updated content back to the file
    with open(file_path, 'w') as f:
        f.writelines(new_lines)

    print(f"Removed duplicates from {file_path}")

# Remove duplicates in CardRepository.kt
remove_duplicates(card_repo_path, "Card")

# Remove duplicates in CharacterRepository.kt
remove_duplicates(character_repo_path, "Character")

print("Duplicates removed successfully.")