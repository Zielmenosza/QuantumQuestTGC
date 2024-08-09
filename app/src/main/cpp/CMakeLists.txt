cmake_minimum_required(VERSION 3.10)
project(QuantumQuest)

set(NDK_PATH "C:/Users/Ziel/AppData/Local/Android/Sdk/ndk/27.0.12077973")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${NDK_PATH}/sources/android/native_app_glue)  # Correct path to native_app_glue
include_directories(utils)

# Add static library for native_app_glue
add_library(native_app_glue STATIC
        ${NDK_PATH}/sources/android/native_app_glue/android_native_app_glue.c
)
set_target_properties(native_app_glue PROPERTIES LINKER_LANGUAGE C)

# ARCore SDK root (if used)
set(ARCORE_SDK_ROOT "C:/Users/Ziel/AndroidStudioProjects/QuantumQuest/arcore-android-sdk-1.44.0")

# Source files for the shared library
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

# Add the shared library
add_library(quantumquest SHARED ${SOURCE_FILES})

# Find necessary libraries
find_library(log-lib log)
find_library(JNIGRAPHICS_LIB jnigraphics)
find_library(android-lib android)
find_library(egl-lib EGL)
find_library(glesv3-lib GLESv3)

# Link libraries
target_link_libraries(quantumquest
        native_app_glue
        ${log-lib}
        ${android-lib}
        ${egl-lib}
        ${glesv3-lib}
        ${JNIGRAPHICS_LIB}
)

# Set C++ standard
set_target_properties(quantumquest PROPERTIES CXX_STANDARD 17)

# Compiler options
target_compile_options(quantumquest PRIVATE
        -std=c++17
        -frtti
        -fexceptions
)

# Build type-specific configurations
if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("Configuring Debug Build")
    target_compile_options(quantumquest PRIVATE
            -O0
            -g
    )
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message("Configuring Release Build")
    target_compile_options(quantumquest PRIVATE
            -O2
    )
endif()