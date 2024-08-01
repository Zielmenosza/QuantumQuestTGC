#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <android/native_app_glue.h>

class InputHandler {
public:
    explicit InputHandler(android_app* app);

    void handleInput();
    bool isTouchEvent() const;
    int getTouchX() const;
    int getTouchY() const;

private:
    android_app* app_;
    bool touchEvent_;
    int touchX_;
    int touchY_;
};

#endif // INPUT_HANDLER_H