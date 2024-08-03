# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(QuantumQuest)

# Set the path to the correct NDK version
set(NDK_PATH "C:/Users/Ziel/AppData/Local/Android/Sdk/ndk/26.1.10909125")

# Include directories
include_directories(
        ${NDK_PATH}/sources/android/native_app_glue
        ${CMAKE_SOURCE_DIR}
)

# Add native app glue as a library
add_library(native_app_glue STATIC
        ${NDK_PATH}/sources/android/native_app_glue/android_native_app_glue.c
)

# Ensure the native_app_glue uses C as the linker language
set_target_properties(native_app_glue PROPERTIES LINKER_LANGUAGE C)

# Collect all source files
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

# Create the main library
add_library(quantumquest SHARED ${SOURCE_FILES})

# Find required libraries
find_library(log-lib log)
find_library(android-lib android)
find_library(egl-lib EGL)  # Add EGL library
find_library(glesv3-lib GLESv3)  # Add GLESv3 library

# Link the native app glue and other required libraries
target_link_libraries(quantumquest
        native_app_glue
        ${log-lib}
        ${android-lib}
        ${egl-lib}    # Link EGL library
        ${glesv3-lib} # Link GLESv3 library
)

# Specify the C++ standard version
set_target_properties(quantumquest PROPERTIES CXX_STANDARD 17)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -frtti -fexceptions")

# Define compiler flags for different build types
if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("Configuring Debug Build")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
else()
    message("Configuring Release Build")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()