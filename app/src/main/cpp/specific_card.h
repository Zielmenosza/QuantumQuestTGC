#pragma once

#include "card.h"  // Ensure correct case sensitivity
#include <string>

// The SpecificCard class is a concrete implementation of the Card class
class SpecificCard : public Card {
public:
    // Constructor with name, description, and cost
    SpecificCard(const std::string &name, const std::string &description, int cost);

    // Implementing pure virtual functions from Card
    std::string getName() const override;
    int getCost() const override;
    std::string getDescription() const;

    // Additional methods and members specific to SpecificCard
    // You can add more functions related to the specific behavior of this card

private:
    std::string name_;
    std::string description_;
    int cost_;
};

#endif // SPECIFIC_CARD_H