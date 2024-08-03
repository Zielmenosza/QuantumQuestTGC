// input_handler.cpp
#include "input_handler.h"

InputHandler::InputHandler(android_app* app)
        : app_(app), touchEvent_(false), touchX_(0), touchY_(0) {}

void InputHandler::handleInput() {
    // Process all pending events
    int ident;
    int events;
    android_poll_source* source;

    while ((ident = ALooper_pollAll(0, nullptr, &events, (void**)&source)) >= 0) {
        if (source != nullptr) {
            source->process(app_, source);
        }

        // Process input events
        if (ident == LOOPER_ID_USER) {
            AInputEvent* event = nullptr;
            while (AInputQueue_getEvent(app_->inputQueue, &event) >= 0) {
                if (AInputQueue_preDispatchEvent(app_->inputQueue, event)) {
                    continue;
                }

                int32_t handled = 0;
                if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION) {
                    touchEvent_ = true;
                    touchX_ = static_cast<int>(AMotionEvent_getX(event, 0));
                    touchY_ = static_cast<int>(AMotionEvent_getY(event, 0));
                    handled = 1;
                }

                AInputQueue_finishEvent(app_->inputQueue, event, handled);
            }
        }

        // Check if we are exiting
        if (app_->destroyRequested != 0) {
            return;
        }
    }
}

bool InputHandler::isTouchEvent() const {
    return touchEvent_;
}

int InputHandler::getTouchX() const {
    return touchX_;
}

int InputHandler::getTouchY() const {
    return touchY_;
}