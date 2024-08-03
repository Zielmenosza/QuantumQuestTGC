#include "card_effect.h"
#include <iostream>
#include <utility>

// Constructor for CardEffect, initializing name, description, and cost
CardEffect::CardEffect(const std::string& name, const std::string& description, int cost)
        : Card(name, cost), description(description) {}

// Implementation of the applyEffect function
void CardEffect::applyEffect(Player& player) {
    // Example logic: Apply effect to the player
    player.reduceIncomingDamage(10);  // Assuming this function exists in the Player class

    // Log the effect application for debugging purposes
    std::cout << "Applied effect: " << description << " to player: " << player.getName() << std::endl;
}

// Implement the Play function (inherited from Card)
void CardEffect::Play(GameState& gameState) {
    // Implement your logic to play the card within the game
    std::cout << "Playing card: " << getName() << std::endl;
}

// Getter for the name
std::string CardEffect::getName() const {
    return Card::getName();
}

// Getter for the cost
int CardEffect::getCost() const {
    return Card::getCost();
}

// Getter for the description
std::string CardEffect::getDescription() const {
    return description;
}

// Example main function demonstrating CardEffect usage
int main() {
    // Assuming Player has a constructor that takes a name and relevant methods
    Player p("Alice", 100, 10);  // Use appropriate constructor for Player

    // Create a CardEffect object with appropriate attributes
    CardEffect speedBoost("Speed Boost", "Increases movement points", 1);

    // Apply the card effect to the player
    speedBoost.applyEffect(p);

    // Access player's attributes or methods to check effect results
    // Ensure getMovementPoints is a valid function in the Player class
    // std::cout << "Movement Points: " << p.getMovementPoints() << std::endl;

    return 0;
}