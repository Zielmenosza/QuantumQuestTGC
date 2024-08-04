#include <jni.h>
#include <android/native_activity.h>
#include <android_native_app_glue.h>
#include <android/input.h>
#include <memory>
#include "Renderer.h"
#include "player.h"
#include "card.h"
#include "card_effect.h"
#include "AndroidOut.h"

void handle_cmd(android_app* pApp, int32_t cmd);
int32_t input_event_filter_func(const android_app* app, const AInputEvent* event);

void handle_cmd(android_app* pApp, int32_t cmd) {
    switch (cmd) {
        case APP_CMD_INIT_WINDOW:
            break;
        case APP_CMD_TERM_WINDOW:
            if (pApp->userData) {
                auto* pRenderer = reinterpret_cast<Renderer*>(pApp->userData);
                pApp->userData = nullptr;
                delete pRenderer;
            }
            break;
        default:
            break;
    }
}

int32_t input_event_filter_func(const android_app* app, const AInputEvent* event) {
    if (AInputEvent_getType(event) != AINPUT_EVENT_TYPE_MOTION) {
        return 0; // Not a motion event
    }
    auto source = AInputEvent_getSource(event);
    auto sourceClass = source & AINPUT_SOURCE_CLASS_MASK;
    return (sourceClass == AINPUT_SOURCE_CLASS_POINTER ||
            sourceClass == AINPUT_SOURCE_CLASS_JOYSTICK);
}

void android_main(struct android_app* pApp) {
    aout << "Welcome to android_main" << std::endl;

    pApp->onAppCmd = handle_cmd;
    pApp->onInputEvent = reinterpret_cast<int32_t (*)(android_app *,
                                                      AInputEvent *)>(input_event_filter_func);

    InputHandler inputHandler(pApp);
    pApp->userData = new Renderer(pApp, inputHandler);

    Player player;
    std::shared_ptr<Card> card1 = std::make_shared<CardEffect>("Ace of Spades", "Powerful card", 5);
    std::shared_ptr<Card> card2 = std::make_shared<CardEffect>("King of Hearts", "Strong card", 3);

    player.addToHand(card1);
    player.addToHand(card2);

    while (pApp->destroyRequested == 0) {
        int events;
        android_poll_source* source;
        while (ALooper_pollAll(0, nullptr, &events, (void**)&source) >= 0) {
            if (source != nullptr) {
                source->process(pApp, source);
            }

            if (pApp->destroyRequested != 0) {
                break;
            }
        }

        if (pApp->userData) {
            auto* pRenderer = reinterpret_cast<Renderer*>(pApp->userData);
            pRenderer->render();
        }

        const auto& hand = player.getHand();
        for (const auto& card : hand) {
            aout << "Player has card: " << card->getName() << std::endl;
        }

        player.reduceIncomingDamage(5);
    }
}