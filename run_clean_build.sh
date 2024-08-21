#!/bin/bash

# Project base directory
BASE_DIR="C:/Users/Ziel/AndroidStudioProjects/QuantumQuest"

cd "$BASE_DIR" || exit

echo "Running a clean build..."
./gradlew clean build

echo "Build complete."