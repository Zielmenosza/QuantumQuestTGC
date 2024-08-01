#include "card_effect.h"
#include <iostream>

// Constructor for CardEffect, initializing name, description, and cost
CardEffect::CardEffect(const std::string& name, const std::string& description, int cost)
        : Card(name), description(description), cost(cost) {}

// Implementation of the applyEffect function
void CardEffect::applyEffect(Player& player) {
    // Example logic: Apply effect to the player
    player.reduceIncomingDamage(10);  // Assuming this function exists in the Player class

    // Log the effect application for debugging purposes
    std::cout << "Applied effect: " << description << " to player: " << player.getName() << std::endl;
}

int main() {
    // Assuming Player has a constructor that takes a string and relevant methods
    Player p("Alice");

    // Create a CardEffect object with appropriate attributes
    CardEffect speed_boost("Speed Boost", "Increases movement points", 1);

    // Apply the card effect to the player
    speed_boost.applyEffect(p);

    // Access player's attributes or methods to check effect results
    // Ensure getMovementPoints is a valid function in the Player class
    std::cout << "Movement Points: " << p.getMovementPoints() << std::endl;

    return 0;
}