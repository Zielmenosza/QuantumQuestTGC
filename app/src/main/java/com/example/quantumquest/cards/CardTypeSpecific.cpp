
#include "CardTypeSpecific.h"

CardTypeSpecific::CardTypeSpecific(const std::string& name, int power)
    : Card(name), m_power(power) {}

void CardTypeSpecific::activateEffect() {
    // Implement specific card effect
}

int CardTypeSpecific::getPower() const {
    return m_power;
}

