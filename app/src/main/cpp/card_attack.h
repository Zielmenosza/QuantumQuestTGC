#ifndef CARD_ATTACK_H
#define CARD_ATTACK_H

#include "card.h" // Include base class header

class Card_Attack : public Card {
public:
    // Constructor with arguments specific to attack cards (replace with actual implementation)
    Card_Attack(const std::string& name, const std::string& description, int cost);

    // Placeholder implementation of Play function (replace with attack logic)
    void Play(GameState& gameState) override {
        // Implement attack logic here
    }

private:
    // Potentially useful member variables for attack cards (uncomment if needed)
    // int attackPower;
};

#endif  // CARD_ATTACK_H