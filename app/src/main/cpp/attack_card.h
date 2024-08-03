#ifndef ATTACK_CARD_H
#define ATTACK_CARD_H

#include "base_card.h"
#include <string>

class AttackCard : public BaseCard {
public:
    AttackCard(const std::string& name, const std::string& description, int cost, int attackValue);

    int getCost() const override;
    std::string getName() const override;
    std::string getDescription() const override;
    int getAttackValue() const;

private:
    std::string name_;
    std::string description_;
    int cost_;
    int attackValue_;
};

#endif // ATTACK_CARD_H