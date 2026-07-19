#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <android/native_activity.h>
#include <android_native_app_glue.h>
#include <iostream>

extern std::ostream aout;

class InputHandler {
public:
    explicit InputHandler(android_app* app);

    void processInput(const AInputEvent* event);
    void handleInput();
    bool isTouchEvent() const;

    void onTouchDown(int pointerId, float x, float y) {
        aout << "Touch down: " << pointerId << ", " << x << ", " << y << std::endl;
    }

    void onTouchMove(int pointerId, float x, float y) {
        aout << "Touch move: " << pointerId << ", " << x << ", " << y << std::endl;
    }

    void onTouchUp(int pointerId) {
        aout << "Touch up: " << pointerId << std::endl;
    }

    float getTouchX() const;
    float getTouchY() const;

private:
    android_app* app_;
    bool touchEvent_;
    float touchX_;
    float touchY_;
};

#endif // INPUT_HANDLER_H
