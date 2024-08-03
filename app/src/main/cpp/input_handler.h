// input_handler.h
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "C:/Users/Ziel/AppData/Local/Android/Sdk/ndk/26.1.10909125/sources/android/native_app_glue/android_native_app_glue.h"

class InputHandler {
public:
    // Constructor that takes a pointer to the Android app structure
    InputHandler(android_app* app);

    // Method to handle input events
    void handleInput();

    // Method to check if the last event was a touch event
    bool isTouchEvent() const;

    // Getters for touch coordinates
    int getTouchX() const;
    int getTouchY() const;

private:
    android_app* app_;  // Pointer to the Android app structure
    bool touchEvent_;   // Flag to indicate if a touch event occurred
    int touchX_;        // X coordinate of the touch event
    int touchY_;        // Y coordinate of the touch event
};

#endif // INPUT_HANDLER_H