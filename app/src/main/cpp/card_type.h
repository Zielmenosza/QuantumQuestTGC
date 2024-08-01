#ifndef CARD_TYPE_H
#define CARD_TYPE_H

#include <string>
#include "card_type_specific.h" // Include base class header

// Class for specific attack cards
class AttackCard : public card_type_specific {
public:
    // Constructor initializing the attack card with necessary attributes
    AttackCard(const std::string& name, const std::string& description, int cost, int attackValue)
            : card_type_specific(name, description, cost, CardType::Attack), attackValue(attackValue) {}

    // Getter for attack value
    int getAttackValue() const { return attackValue; }

    // Implementation of the Play method
    void Play(GameState& gameState) override {
        // Implement attack logic here, e.g., deal damage based on attackValue
    }

private:
    int attackValue;  // Attack value of the card
};

#endif // CARD_TYPE_H