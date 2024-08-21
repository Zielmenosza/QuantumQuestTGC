#!/bin/bash

# Project base directory
BASE_DIR="C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/app/src/main/java/com/example/quantumquest"

# Files to update with correct paths
files_to_fix=(
    "$BASE_DIR/databases/CardDatabase.cpp"
    "$BASE_DIR/managers/CardManager.cpp"
    "$BASE_DIR/managers/GameManager.cpp"
    "$BASE_DIR/ui/UIIntegration.cpp"
)

# Ensure all required header files are in the correct directory
header_files=(
    "$BASE_DIR/databases/CardDatabase.h"
    "$BASE_DIR/managers/CardManager.h"
    "$BASE_DIR/managers/GameManager.h"
    "$BASE_DIR/ui/UIIntegration.h"
)

# Update the include paths in the C++ files
echo "Fixing pathing issues..."

for file in "${files_to_fix[@]}"; do
    if [ -f "$file" ]; then
        echo "Updating: $file"
        sed -i 's|#include "Card.h"|#include "../cards/Card.h"|' "$file"
        sed -i 's|#include "Player.h"|#include "../players/Player.h"|' "$file"
        sed -i 's|#include "CardRepository.h"|#include "../repositories/CardRepository.h"|' "$file"
    fi
done

echo "Pathing issues fixed."
