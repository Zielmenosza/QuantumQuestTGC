#include "card_attack.h"

// Constructor with initialization list
Card_Attack::Card_Attack(const std::string& name, const std::string& description, int cost)
        : Card(name), description(description), cost(cost) {}

// Implementation of Play function
void Card_Attack::Play(GameState& gameState) {
    // Implement attack logic here
    // Example: gameState.reduceHealth(target, attackPower);

    // Example logging of the card play action
    aout << "Playing attack card: " << getName() << " with description: " << description << std::endl;
}