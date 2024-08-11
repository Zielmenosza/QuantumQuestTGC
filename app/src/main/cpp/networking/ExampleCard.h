#ifndef EXAMPLE_CARD_H
#define EXAMPLE_CARD_H

#include "card.h"
#include "publicCard.h"

class ExampleCard : public Card { // Ensure public inheritance
public:
    ExampleCard(const std::string& name, const std::string& description, int cost, int power);

    int getPower() const;

private:
    int power_;
};

#endif // EXAMPLE_CARD_H