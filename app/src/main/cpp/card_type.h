#ifndef CARD_TYPE_H
#define CARD_TYPE_H

#include <string>

enum CardType {Attack,
    Defense,
    // ... other card types
};

class card_type_specific; // Forward declaration

#include "card_type_specific.h" // Include the full definition of card_type_specific

class AttackCard : public card_type_specific {
public:
    AttackCard(const std::string& name, const std::string& description, int cost, int attackValue);

    int getAttackValue() const { return attackValue; }

private:
    int attackValue;
};

#endif // CARD_TYPE_H