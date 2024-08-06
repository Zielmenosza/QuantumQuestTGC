#include <jni.h>
#include <android/native_activity.h>
#include <android_native_app_glue.h>
#include <android/input.h>
#include <memory>
#include "enemy.h"
#include "match.h"
#include "adventure_match.h"
#include "Renderer.h"
#include "player.h"
#include "card.h"
#include "card_effect.h"
#include "input_handler.h"
#include "AndroidOut.h"

void handle_cmd(android_app* pApp, int32_t cmd);
int32_t input_event_filter_func(const android_app* app, const AInputEvent* event) {
    if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION) {
        if (AMotionEvent_getAction(event) == AMOTION_EVENT_ACTION_DOWN) {
            float x = AMotionEvent_getX(event, 0);
            float y = AMotionEvent_getY(event, 0);
            aout << "Motion event down: " << x << ", " << y << std::endl;
            return 1; // Indicate that the event was handled
        }
    }
    return 0; // Indicate that the event was not handled
}