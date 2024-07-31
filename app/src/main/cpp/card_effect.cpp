#include "card_effect.h" // Include the header file
#include <iostream>

CardEffect::CardEffect(const std::string& name, const std::string& description, int cost)
        : Card(name, cost), description(description) {}

void CardEffect::playEffect(Player& targetPlayer) {
    std::cout << "Playing card: " << getName() << std::endl;
    std::cout << "Description: " << description << std::endl;
    targetPlayer.setMovementPoints(targetPlayer.getMovementPoints() + 1);
}