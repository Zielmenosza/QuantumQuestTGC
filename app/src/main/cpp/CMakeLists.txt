cmake_minimum_required(VERSION 3.4.1)

project(QuantumQuest CXX)

set(CPP_DIR${CMAKE_SOURCE_DIR}/src/main/cpp)
include_directories(${ANDROID_NDK}/sources/android/native_app_glue)
set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> qc <TARGET> <LINK_FLAGS> <OBJECTS>")
set(CMAKE_C_ARCHIVE_FINISH "<CMAKE_RANLIB> <TARGET>")

set(SOURCE_FILES
        AndroidOut.cpp
        AndroidOut.h
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
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c
)

add_library(app-glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)
add_library(quantum_quest_game SHARED ${SOURCE_FILES})
target_include_directories(app-glue PUBLIC
        ${ANDROID_NDK}/sources/android/native_app_glue)
set_target_properties(app-glue PROPERTIES LINKER_LANGUAGE C)

find_library(log-lib log)
find_library(android-lib android)
find_library(EGL-lib EGL)
find_library(GLESv3-lib GLESv3)

target_link_libraries(quantum_quest_game PUBLIC
        ${log-lib}
        ${android-lib}
        ${EGL-lib}
        ${GLESv3-lib}
        app-glue
)

target_compile_options(quantum_quest_game PRIVATE -DANDROID_PLATFORM=android-21)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER "${ANDROID_TOOLCHAIN_PREFIX}clang")
set(CMAKE_CXX_COMPILER "${ANDROID_TOOLCHAIN_PREFIX}clang++")