#include "card_attack.h"

// Implement the constructor
Card_Attack::Card_Attack(const std::string& name, const std::string& description, int cost)
        : name_(name), description_(description), cost_(cost) {}

// Implement the Play function logic here
void Card_Attack::Play(GameState& gameState) {
    // Example attack logic
    // You could manipulate the gameState object to reflect the card's effects
}

// Implement the getName function
std::string Card_Attack::getName() const {
    return name_;
}

// Implement the getCost function
int Card_Attack::getCost() const {
    return cost_;
}