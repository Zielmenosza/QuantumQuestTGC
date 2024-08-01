#ifndef CARD_ATTACK_H
#define CARD_ATTACK_H

#include "card.h" // Include base class header
#include "GameState.h" // Include GameState class header for access

class Card_Attack : public Card {
public:
    // Constructor with arguments specific to attack cards
    Card_Attack(const std::string& name, const std::string& description, int cost);

    // Method to play the attack card
    void Play(GameState& gameState) override;

private:
    std::string description; // Description of the card
    int cost;                // Mana or resource cost to play the card
    // int attackPower;      // Uncomment and use if attack power is needed
};

#endif  // CARD_ATTACK_H