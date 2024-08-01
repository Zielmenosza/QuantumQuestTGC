#include "card_effect.h"
#include <iostream>

// Correct implementation of the declared function in the header file
void CardEffect::applyEffect(Player& player) {
    // Example logic: Apply effect to the player
    player.reduceIncomingDamage(10);  // Assuming this function exists in the Player class
}

int main() {
    // Assuming Player has a constructor that takes a string
    Player p("Alice");
    CardEffect speed_boost("Speed Boost", "Increases movement points", 1);

    // Correct function call as declared in the header file
    speed_boost.applyEffect(p);

    // Correctly accessing a hypothetical function, ensure this is declared and defined in Player
    std::cout << "Movement Points: " << p.getMovementPoints() << std::endl; // Replace or implement getMovementPoints in Player class

    return 0;
}