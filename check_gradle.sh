#!/bin/bash

echo "Checking Gradle installation..."

gradle -v &> /dev/null
if [ $? -ne 0 ]; then
    echo "ERROR: Gradle is not properly configured. Please ensure it is installed and added to your PATH."
    exit 1
else
    echo "Gradle is properly configured."
fi
