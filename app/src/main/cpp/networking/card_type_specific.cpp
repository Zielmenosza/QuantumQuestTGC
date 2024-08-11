#include "card_type_specific.h"
#include <iostream>

// Constructor implementation using initializer list to call the base class constructor
CardTypeSpecific::CardTypeSpecific(const std::string& name, const std::string& description, int cost, int power)
        : Card(name, description, cost), power_(power) {} // Description already present

// Getter for power
int CardTypeSpecific::getPower() const {
    return power_;
}

// Activate card effect
void CardTypeSpecific::activateEffect() {
    // Implement effect logic here
    std::cout << "Effect of " << getName() << " activated with power " << power_ << std::endl;
}