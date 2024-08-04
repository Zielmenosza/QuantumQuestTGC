cmake_minimum_required(VERSION 3.10)
project(QuantumQuest)

set(NDK_PATH "C:/Users/Ziel/AppData/Local/Android/Sdk/ndk/26.1.10909125")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${ANDROID_NDK}/sources/android/native_app_glue)
include_directories(utils)

add_library(native_app_glue STATIC
        ${NDK_PATH}/sources/android/native_app_glue/android_native_app_glue.c
)
set_target_properties(native_app_glue PROPERTIES LINKER_LANGUAGE C)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_library(quantumquest SHARED ${SOURCE_FILES})

find_library(log-lib log)
find_library(android-lib android)
find_library(egl-lib EGL)
find_library(glesv2-lib GLESv2)

target_link_libraries(quantumquest
        native_app_glue
        ${log-lib}
        ${android-lib}
        ${egl-lib}
        ${glesv2-lib})

set_target_properties(quantumquest PROPERTIES CXX_STANDARD 17)

target_compile_options(quantumquest PRIVATE
        -std=c++17
        -frtti
        -fexceptions
)

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