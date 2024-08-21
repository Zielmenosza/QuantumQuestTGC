#!/bin/bash

# Define paths
PROJECT_PATH="C:/Users/Ziel/AndroidStudioProjects/QuantumQuest"
SRC_PATH="$PROJECT_PATH/app/src/main/java/com/example/quantumquest"
RES_PATH="$PROJECT_PATH/app/src/main/res"
LOG_DIR="$PROJECT_PATH/logs"

# Create logs directory
mkdir -p "$LOG_DIR"

# Function to check for duplicate files
check_for_duplicates() {
    echo "Checking for duplicate files..." | tee "$LOG_DIR/duplicate_check.log"
    duplicate_files=$(find "$PROJECT_PATH" -type f -printf "%f\n" | sort | uniq -d)

    if [ -n "$duplicate_files" ]; then
        echo "Duplicate files found:" | tee -a "$LOG_DIR/duplicate_check.log"
        echo "$duplicate_files" | tee -a "$LOG_DIR/duplicate_check.log"
    else
        echo "No duplicate files found." | tee -a "$LOG_DIR/duplicate_check.log"
    fi
    echo "" | tee -a "$LOG_DIR/duplicate_check.log"
}

# Function to check for missing files
check_for_missing_files() {
    echo "Checking for missing files..." | tee "$LOG_DIR/missing_files_check.log"

    required_files=(
        "$SRC_PATH/managers/GameManager.h"
        "$SRC_PATH/managers/GameManager.cpp"
        "$SRC_PATH/managers/TutorialManager.h"
        "$SRC_PATH/managers/TutorialManager.cpp"
        "$SRC_PATH/managers/PlayerSelectionManager.h"
        "$SRC_PATH/managers/PlayerSelectionManager.cpp"
        "$SRC_PATH/managers/PlayerInputHandler.h"
        "$SRC_PATH/managers/PlayerInputHandler.cpp"
        "$SRC_PATH/databases/CardDatabase.h"
        "$SRC_PATH/databases/CardDatabase.cpp"
        "$SRC_PATH/ui/TutorialActivity.java"
        "$RES_PATH/layout/activity_tutorial.xml"
        "$RES_PATH/drawable/icon_1.png"
    )

    for file in "${required_files[@]}"; do
        if [ ! -f "$file" ]; then
            echo "Missing file: $file" | tee -a "$LOG_DIR/missing_files_check.log"
        fi
    done

    echo "Missing file check complete." | tee -a "$LOG_DIR/missing_files_check.log"
    echo "" | tee -a "$LOG_DIR/missing_files_check.log"
}

# Function to check for incorrect file placement
check_file_placement() {
    echo "Checking file placements..." | tee "$LOG_DIR/file_placement_check.log"

    incorrect_files=$(find "$PROJECT_PATH" -type f -name "*.h" -o -name "*.cpp" -o -name "*.java" -o -name "*.xml" -o -name "*.png" | grep -v -E "($SRC_PATH/managers|$SRC_PATH/databases|$SRC_PATH/ui|$RES_PATH/layout|$RES_PATH/drawable)")

    if [ -n "$incorrect_files" ]; then
        echo "Incorrectly placed files:" | tee -a "$LOG_DIR/file_placement_check.log"
        echo "$incorrect_files" | tee -a "$LOG_DIR/file_placement_check.log"
    else
        echo "All files are correctly placed." | tee -a "$LOG_DIR/file_placement_check.log"
    fi
    echo "" | tee -a "$LOG_DIR/file_placement_check.log"
}

# Function to summarize the progress
summarize_progress() {
    echo "Summarizing project progress..." | tee "$LOG_DIR/progress_summary.log"

    echo "Number of .h files:" | tee -a "$LOG_DIR/progress_summary.log"
    find "$SRC_PATH" -name "*.h" | wc -l | tee -a "$LOG_DIR/progress_summary.log"

    echo "Number of .cpp files:" | tee -a "$LOG_DIR/progress_summary.log"
    find "$SRC_PATH" -name "*.cpp" | wc -l | tee -a "$LOG_DIR/progress_summary.log"

    echo "Number of .java files:" | tee -a "$LOG_DIR/progress_summary.log"
    find "$SRC_PATH" -name "*.java" | wc -l | tee -a "$LOG_DIR/progress_summary.log"

    echo "Number of layout files:" | tee -a "$LOG_DIR/progress_summary.log"
    find "$RES_PATH/layout" -name "*.xml" | wc -l | tee -a "$LOG_DIR/progress_summary.log"

    echo "Number of drawable resources:" | tee -a "$LOG_DIR/progress_summary.log"
    find "$RES_PATH/drawable" -name "*.png" -o -name "*.xml" | wc -l | tee -a "$LOG_DIR/progress_summary.log"

    echo "Project structure summary complete." | tee -a "$LOG_DIR/progress_summary.log"
    echo "" | tee -a "$LOG_DIR/progress_summary.log"
}

# Function to perform error checking
check_for_errors() {
    echo "Performing error checks..." | tee "$LOG_DIR/error_check.log"

    if ! gradle build > "$LOG_DIR/gradle_build.log" 2>&1; then
        echo "Gradle build failed. Please check the logs." | tee -a "$LOG_DIR/error_check.log"
        echo "See $LOG_DIR/gradle_build.log for details." | tee -a "$LOG_DIR/error_check.log"
    else
        echo "Gradle build successful." | tee -a "$LOG_DIR/error_check.log"
    fi

    echo "Error checks complete." | tee -a "$LOG_DIR/error_check.log"
    echo "" | tee -a "$LOG_DIR/error_check.log"
}

# Main script execution
check_for_duplicates
check_for_missing_files
check_file_placement
summarize_progress
check_for_errors

echo "Project check complete. Logs can be found in $LOG_DIR."