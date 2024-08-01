#ifndef CARD_EFFECT_H
#define CARD_EFFECT_H

#include <string>
#include "player.h"

class CardEffect {
public:
    CardEffect(const std::string& name, const std::string& description, int value)
            : name(name), description(description), value(value) {}

    void applyEffect(Player& player);

private:
    std::string name;
    std::string description;
    int value;
};

#endif // CARD_EFFECT_H