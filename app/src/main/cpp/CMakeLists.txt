cmake_minimum_required(VERSION 3.4.1)

project(QuantumQuest CXX)

# Set the path to the NDK
set(NDK_PATH "C:/Users/Ziel/AppData/Local/Android/Sdk/ndk/26.3.11579264")

# Include directories
include_directories(
        ${NDK_PATH}/sources/android/native_app_glue
        ${CMAKE_CURRENT_SOURCE_DIR}  # Include the current source directory for header files
        # Add more include directories as needed
)

# Set the Android STL
set(ANDROID_STL c++_shared)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -frtti -fexceptions")

# Use GLOB to gather source files
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

# Add native app glue source file
add_library(native_app_glue STATIC
        ${NDK_PATH}/sources/android/native_app_glue/android_native_app_glue.c
)
set_target_properties(native_app_glue PROPERTIES LINKER_LANGUAGE CXX)

# Add your native library
add_library(quantumquest SHARED ${SOURCE_FILES})

# Find libraries
find_library(log-lib log)
find_library(android-lib android)
find_library(EGL-lib EGL)
find_library(GLESv3-lib GLESv3) # Use GLESv3 if targeting OpenGL ES 3.0

# Link libraries
target_link_libraries(quantumquest
        native_app_glue
        ${log-lib}
        ${android-lib}
        ${EGL-lib}
        ${GLESv3-lib} # Link with GLESv3
)

# Set target include directories
target_include_directories(quantumquest PRIVATE
        ${NDK_PATH}/sources/android/native_app_glue
)

# Set target properties
set_target_properties(quantumquest PROPERTIES CXX_STANDARD 17)

# Define compiler flags for different build types
if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("Configuring Debug Build")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
else()
    message("Configuring Release Build")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()

# Additional settings and configurations can be added here
# Add custom commands, build steps, or other configurations as needed