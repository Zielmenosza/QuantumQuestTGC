#ifndef CARD_TYPE_H
#define CARD_TYPE_H

#include <string>
#include "card_type_specific.h"

// AttackCard class inheriting from card_type_specific
class AttackCard : public card_type_specific {
public:
    // Constructor to initialize the AttackCard with specific properties
    AttackCard(const std::string& name, const std::string& description, int cost, int attackValue);

    // Override the Play method to define the attack behavior
    void Play(GameState& gameState) override;

    // Getter for the attack value
    [[nodiscard]] int getAttackValue() const;

private:
    int attackValue; // Attack value specific to the AttackCard
};

#endif // CARD_TYPE_H