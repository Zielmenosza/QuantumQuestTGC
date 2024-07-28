#include "card_type.h"

// Implementations for specific card types derived from CardTypeSpecific can be added here.
// For example:

class AttackCard : public CardTypeSpecific {
public:
    AttackCard(const std::string& name, const std::string& description, int cost, int attackValue)
            : CardTypeSpecific(name, description, cost, CardType::Attack), attackValue(attackValue) {}

    int getAttackValue() const { return attackValue; }

private:
    int attackValue;
};