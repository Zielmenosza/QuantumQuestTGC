#ifndef CARD_H
#define CARD_H

#include "card_type_specific.h"

class Card : public card_type_specific {
public:
    Card(const std::string& name, const std::string& description, int cost, CardType type);
    // ... other methods ...
};

#endif // CARD_H