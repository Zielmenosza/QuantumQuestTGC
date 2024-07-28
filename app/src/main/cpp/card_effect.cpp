#include "card_effect.h"

Card_Effect::Card_Effect(const std::string& name, const std::string& description, int cost)
        : Card(name, cost), description(description) {}

// Example implementation of a playEffect method (modify or add more based on your game logic)
void Card_Effect::playEffect(Player& targetPlayer) {
    // Implement the specific effect of the card here (e.g., modify targetPlayer's attributes)
    // This is just a placeholder example, modify based on your game design
    std::cout << "Playing card: " << getName() << std::endl;
    std::cout << "Description: " << description << std::endl;
    // Example effect: Grant target player +1 movement point
    targetPlayer.setMovementPoints(targetPlayer.getMovementPoints() + 1);
}