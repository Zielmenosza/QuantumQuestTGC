#ifndef CARD_ATTACK_H
#define CARD_ATTACK_H

#include "ExampleCard.h"  // Ensure correct include of base class
#include <string>

class GameState;  // Forward declaration if GameState is used

// Derived class for attack cards
class CardAttack : public Card {
public:
    CardAttack(const std::string& name, const std::string& description, int cost, int attackValue);

    void Play(GameState& gameState); // Implemented method to affect game state

    std::string getName() const override;        // Correctly override
    std::string getDescription() const override; // Correctly override
    int getCost() const override;                // Correctly override
    int getAttackValue() const;                  // Additional method

private:
    int attackValue_;
};

#endif // CARD_ATTACK_H