#ifndef CARD_EFFECT_H
#define CARD_EFFECT_H

#include <string>

class card_effect {
public:
    card_effect(const std::string &name, const std::string &description, int cost);
    // Add other necessary members and functions here

private:
    std::string name_;
    std::string description_;
    int cost_;
};

#endif // CARD_EFFECT_H