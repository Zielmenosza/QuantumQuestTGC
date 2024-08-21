#!/bin/bash

# Define the paths to check
PROJECT_PATH="/Users/Ziel/AndroidStudioProjects/QuantumQuest/app/src/main"
DRAWABLE_PATH="$PROJECT_PATH/res/drawable"
MIPMAP_PATH="$PROJECT_PATH/res/mipmap"
MANIFEST_PATH="$PROJECT_PATH/AndroidManifest.xml"
ICON_FILE="icon_1.png"

# Define the paths where the icon should be
DRAWABLE_ICON_PATH="$DRAWABLE_PATH/$ICON_FILE"
MIPMAP_ICON_PATH="$MIPMAP_PATH/ic_launcher.png"

# Check if the icon exists in the drawable folder
if [ -f "$DRAWABLE_ICON_PATH" ]; then
    echo "Icon found in drawable folder: $DRAWABLE_ICON_PATH"
else
    echo "Icon NOT found in drawable folder: $DRAWABLE_ICON_PATH"
fi

# Check if the icon exists in the mipmap folder
if [ -f "$MIPMAP_ICON_PATH" ]; then
    echo "Icon found in mipmap folder: $MIPMAP_ICON_PATH"
else
    echo "Icon NOT found in mipmap folder: $MIPMAP_ICON_PATH"
fi

# Check the AndroidManifest.xml for proper icon reference
if grep -q 'android:icon="@mipmap/ic_launcher"' "$MANIFEST_PATH"; then
    echo "Manifest correctly references the icon."
else
    echo "Manifest does NOT reference the icon correctly."
    echo "Please update AndroidManifest.xml to reference the icon as follows:"
    echo 'android:icon="@mipmap/ic_launcher"'
fi