#include "card_attack.h"
#include <iostream>

// Constructor definition
CardAttack::CardAttack(
        const std::string& name,
        const std::string& description,
        int cost,
        int attackValue
) : Card(name, description, cost),  // Initialize base class
    attackValue_(attackValue) {
    // Additional initialization if needed
}

// Implementation of the Play method
void CardAttack::Play(GameState& gameState) {
    // Implement logic to modify the game state
    std::cout << "Playing attack card: " << getName() << " with attack value: " << getAttackValue() << std::endl;

    // Example: Apply damage to a target in the game state
    // Assuming gameState has a method to apply damage to a player or enemy
    // gameState.applyDamage(targetID, attackValue_);

    // Example output
    std::cout << getDescription() << std::endl;
}

// Getter for card name
std::string CardAttack::getName() const {
    return Card::getName();
}

// Getter for card cost
int CardAttack::getCost() const {
    return Card::getCost();
}

// Getter for attack value
int CardAttack::getAttackValue() const {
    return attackValue_;
}

// Getter for description
std::string CardAttack::getDescription() const {
    return Card::getDescription();
}