#ifndef CARD_EFFECT_H
#define CARD_EFFECT_H

#include <string>
#include "card.h" // Include the Card class header

class CardEffect : public Card {
public:
    CardEffect(const std::string& name, const std::string& description, int cost);

    void playEffect(Player& targetPlayer);

private:
    std::string description;
};

#endif // CARD_EFFECT_H