cmake_minimum_required(VERSION 3.4.1)

project(QuantumQuest CXX)

# Set the path to the NDK
set(NDK_PATH "C:/Users/Ziel/AppData/Local/Android/Sdk/ndk/26.3.11579264")

# Include directories
include_directories(
        ${NDK_PATH}/sources/android/native_app_glue
)

set(ANDROID_STL c++_shared)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -frtti -fexceptions")

# Source files
set(SOURCE_FILES
        AndroidOut.cpp
        AndroidOut.h
        native-lib.cpp   # Include native-lib.cpp
        battle.h
        card.cpp
        card.h
        card_attack.h
        card_defence.h
        card_effect.cpp
        card_effect.h
        card_pool.cpp
        card_pool.h
        card_type.h
        character.cpp
        character.h
        deck.h
        Direction.h
        element.cpp
        enemy.h
        game_board.cpp
        game_board.h
        game_manager.h
        game_state.h
        input_handler.h
        item.h
        jni_interface.cpp
        jni_interface.h
        main.cpp
        Model.h
        observer_effect.cpp
        observer_effect.h
        Obstacle.h
        player.cpp
        player.h
        player_id.h
        PlayerID.h
        Position.h
        quantum_quest_game.cpp
        quantum_quest_game.h
        quantum_state.cpp
        quantum_state.h
        random_generator.cpp
        random_generator.h
        Renderer.cpp
        Renderer.h
        room.cpp
        room.h
        Shader.cpp
        Shader.h
        specific_card.h
        spell.cpp
        spell.h
        texture.h
        TextureAsset.cpp
        TextureAsset.h
        ui.h
        Utility.cpp
        Utility.h
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
find_library(GLESv1_CM-lib GLESv1_CM) # Use GLESv1_CM

# Link libraries
target_link_libraries(quantumquest
        native_app_glue
        ${log-lib}
        ${android-lib}
        ${EGL-lib}
        ${GLESv1_CM-lib} # Link with GLESv1_CM
)

# Set target properties
target_include_directories(quantumquest PRIVATE
        ${NDK_PATH}/sources/android/native_app_glue
)
set_target_properties(quantumquest PROPERTIES CXX_STANDARD 17)
target_compile_options(quantumquest PRIVATE -DANDROID_PLATFORM=android-17)