#ifndef CARD_DEFENSE_H
#define CARD_DEFENSE_H

#include <string>
#include "card.h" // Include the Card class header

class Card_Defense : public Card {
public:
    // Constructor with arguments specific to defense cards
    Card_Defense(const std::string& name, const std::string& description, int cost);

    // Method to play the defense card
    void Play(GameState& gameState) override;

private:
    std::string description; // Description of the card
    int cost;                // Mana or resource cost to play the card
    // int defenseValue;     // Uncomment and use if defense value is needed
};

#endif // CARD_DEFENSE_H