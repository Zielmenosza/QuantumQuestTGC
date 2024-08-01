// player.cpp

#include "player.h"
#include <iostream> // For debug printing, if needed

// Add a card to the player's hand
void Player::addToHand(const std::shared_ptr<Card>& card) {
    hand_.push_back(card);
}

// Reduce incoming damage, example implementation
void Player::reduceIncomingDamage(int damage) {
    // Implement your logic here, e.g., reduce damage based on player's armor
    // For example, if player has a shield, reduce damage by shield's protection value

    // For illustration, let's print the damage reduced
    std::cout << "Reducing damage by: " << damage << std::endl;

    // Assuming you have a member variable, `current_health_`, to track player's health
    // int effective_damage = damage - armor;
    // current_health_ -= std::max(0, effective_damage);
}