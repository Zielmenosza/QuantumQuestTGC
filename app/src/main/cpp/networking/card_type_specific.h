#ifndef CARD_TYPE_SPECIFIC_H
#define CARD_TYPE_SPECIFIC_H

#include "ExampleCard.h"
#include <memory>

// Derived class for specific card types
class CardTypeSpecific : public Card {
public:
    CardTypeSpecific(const std::string& name, const std::string& description, int cost, int power); // Description already present

    int getPower() const;
    void activateEffect(); // Implement effect logic

private:
    int power_;
};

#endif // CARD_TYPE_SPECIFIC_H