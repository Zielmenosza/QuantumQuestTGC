#!/bin/bash

# Project base directory
BASE_DIR="C:/Users/Ziel/AndroidStudioProjects/QuantumQuest"

# List of unnecessary directories to be removed
unnecessary_dirs=(
    "$BASE_DIR/app/src/main/java/com/example/arcore"
    "$BASE_DIR/app/src/main/res/raw/ar_samples"
    "$BASE_DIR/app/src/main/libs/third_party_unused"
)

echo "Cleaning up unnecessary files and directories..."

for dir in "${unnecessary_dirs[@]}"; do
    if [ -d "$dir" ]; then
        echo "Removing: $dir"
        rm -rf "$dir"
    fi
done

echo "Cleanup complete."
