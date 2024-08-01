// SpecificCard.h
#pragma once
#include "card.h"  // Ensure correct case sensitivity
#include <string>

class SpecificCard : public Card {
public:
    // Constructor with name, description, and cost
    SpecificCard(const std::string &name, const std::string &description, int cost)
            : name_(name), description_(description), cost_(cost) {}

    // Implementing pure virtual functions from Card
    std::string getName() const override {
        return name_;
    }

    int getCost() const override {
        return cost_;
    }

    std::string getDescription() const {
        return description_;
    }

    // Additional methods and members specific to SpecificCard
    // You can add more functions related to the specific behavior of this card

private:
    std::string name_;
    std::string description_;
    int cost_;
};

#endif // SPECIFIC_CARD_H