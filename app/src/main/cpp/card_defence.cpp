#include "card_defence.h"

// Constructor with initialization list
Card_Defense::Card_Defense(const std::string& name, const std::string& description, int cost)
        : Card(name), description(description), cost(cost) {}

// Implementation of Play function
void Card_Defense::Play(GameState& gameState) {
    // Implement defense logic here
    // Example: gameState.increaseDefense(target, defenseValue);

    // Example logging of the card play action
    aout << "Playing defense card: " << getName() << " with description: " << description << std::endl;
}