#ifndef CARD_ATTACK_H
#define CARD_ATTACK_H

#include "card_type_specific.h" // Assuming there's a base class for specific card types
#include "game_state.h"  // Assuming GameState is defined here
#include <string>

// Inherit from the appropriate base card class if there's a hierarchy
class CardAttack : public CardTypeSpecific {
public:
    // Constructor
    CardAttack(const std::string& name, const std::string& description, int cost, int attackValue);

    // Method to play the card
    void Play(GameState& gameState) override;

    // Getter for card name
    [[nodiscard]] const std::string& getName() const override;

    // Getter for card cost
    [[nodiscard]] int getCost() const override;

    // Getter for attack value
    [[nodiscard]] int getAttackValue() const;

    // Getter for description
    [[nodiscard]] std::string getDescription() const;

private:
    int attackValue_;  // Attack value specific to this card
};

#endif // CARD_ATTACK_H