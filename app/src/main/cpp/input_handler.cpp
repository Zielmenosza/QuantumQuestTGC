#include "input_handler.h"

InputHandler::InputHandler(android_app* app)
        : app_(app), touchEvent_(false), touchX_(0), touchY_(0) {}

void InputHandler::processInput(const AInputEvent* event) {
    if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION){
        touchEvent_ = true;
        touchX_ = AMotionEvent_getX(event, 0);
        touchY_ = AMotionEvent_getY(event, 0);
    }
}

void InputHandler::handleInput() {
    // ... (rest of your handleInput function)
}

bool InputHandler::isTouchEvent() const {
    return touchEvent_;
}

float InputHandler::getTouchX() const {
    return touchX_;
}

float InputHandler::getTouchY() const {
    return touchY_;
}