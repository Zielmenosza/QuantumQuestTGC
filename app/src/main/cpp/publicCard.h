// publicCard.h
#ifndef PUBLIC_CARD_H
#define PUBLIC_CARD_H

#include "card.h"

class publicCard : public Card {
public:
    publicCard(const std::string& name, const std::string& description, int cost, int value)
            : Card(name, description, cost), value_(value) {}

    int getValue() const { return value_; }

private:
    int value_;
};

#endif // PUBLIC_CARD_H