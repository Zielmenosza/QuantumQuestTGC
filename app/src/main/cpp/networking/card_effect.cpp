#include "card_effect.h"
#include "card.h"
#include <iostream>
#include <utility>

CardEffect::CardEffect(const std::string& name, const std::string& description, int cost)
        : Card(name, description, cost) {} // Provide all three arguments to Card constructor

// Implementation of the applyEffect function
void CardEffect::activateEffect(Player& player) { // Remove const
    // Implement effect activation logic here, e.g.,
    if (getName() == "Speed Boost") {
        player.increaseMovementPoints(2);
    } else if (getName() == "Heal") {
        player.heal(10);
    } // Add more effects for other cards
}

// Implement the Play function (inherited from Card)
void CardEffect::Play(GameState& gameState) {
    // Implement your logic to play the card within the game, e.g.,
    Player currentPlayer = gameState.getCurrentPlayer(); // Get the current player
    activateEffect(currentPlayer); // Call activateEffect with the player object
    // Add logic for removing the card from hand, etc.}
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