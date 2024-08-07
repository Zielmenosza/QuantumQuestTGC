#include "card_defence.h"
#include <iostream>

// Constructor implementation for CardDefense
CardDefense::CardDefense(const std::string& name, const std::string& description, int cost)
        : Card(name, description, cost) { // Call Card constructor
    // ... other initialization ...
}

// Implement Play method
void CardDefense::Play(GameState&gameState) { // Matching declaration
    // Implement the actual game logic here
    // Example: Increase player's defense or shield
    // gameState.getCurrentPlayer().increaseDefense(10); // Assuming this method exists
}

// Getter method for name
std::string CardDefense::getName() const {
    return Card::getName();
}

// Getter method for cost
int CardDefense::getCost() const {
    return Card::getCost();
}

// Getter method for description
std::string CardDefense::getDescription() const {
    return description;
}