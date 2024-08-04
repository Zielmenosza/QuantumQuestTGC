#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <android/native_activity.h> // Include the correct header
#include <C:\Users\Ziel\AppData\Local\Android\Sdk\ndk\26.1.10909125\sources\android\native_app_glue\android_native_app_glue.h>
#include <iostream>

extern std::ostream aout; // Declare aout if it's a global variable

class InputHandler {
public:
    // Constructor that takes a pointer to the Android app structure
    InputHandler(android_app* app);

    void processInput(const AInputEvent* event); // Add processInput function declaration

    // Method to handle input events
    void handleInput();

    // Method to check if the last event was a touch event
    bool isTouchEvent() const;

    void onTouchDown(int pointerId, float x, float y) {
        // Handle touch down event
        aout << "Touch down: " << pointerId << ", " << x << ", " << y << std::endl;
    }

    void onTouchMove(int pointerId, float x, float y) { // Use float for x
        // Handle touch move event
        aout << "Touch move: " << pointerId << ", " << x << ", " << y << std::endl;
    }

    void onTouchUp(int pointerId) {
        // Handle touch up event
        aout << "Touch up: " << pointerId << std::endl;
    }

    // Getters for touch coordinates
    float getTouchX() const; // Change return type to float
    float getTouchY() const; // Change return type to float

private:
    android_app* app_;  // Pointer to the Android app structure
    bool touchEvent_;   // Flag to indicate if a touch event occurred
    float touchX_;        // X coordinate of the touch event (use float)
    float touchY_;        // Y coordinate of the touch event (use float)
};

#endif // INPUT_HANDLER_H