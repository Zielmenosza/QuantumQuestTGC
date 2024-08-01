// player.cpp

#include "player.h"
#include <iostream> // For debug printing, if needed

// Constructor
Player::Player(const std::string& name, int maxHealth, int shield)
        : name_(name), max_health_(maxHealth), current_health_(maxHealth), shield_(shield) {}

// Add a card to the player's hand
void Player::addToHand(const std::shared_ptr<Card>& card) {
    hand_.push_back(card);
    std::cout << "Added card to hand: " << card->getName() << std::endl;
}

// Reduce incoming damage, example implementation
void Player::reduceIncomingDamage(int damage) {
    int effective_damage = damage - shield_; // Reduce damage by shield's protection value
    effective_damage = std::max(0, effective_damage); // Ensure damage isn't negative
    current_health_ -= effective_damage;
    current_health_ = std::max(0, current_health_); // Ensure health isn't negative

    // Debug output
    std::cout << name_ << " takes " << effective_damage << " damage, health is now " << current_health_ << std::endl;
}

// Get current health
int Player::getHealth() const {
    return current_health_;
}

// Get player's hand
const std::vector<std::shared_ptr<Card>>& Player::getHand() const {
    return hand_;
}

// Additional methods can be implemented here
// e.g., methods for using cards, discarding cards, etc.