#pragma once

#include "card.h" // Include the base Card class
#include <string> // Include string for std::string

class ExampleCard : public Card {
public:
    // Constructor that initializes the base class with name and cost
    ExampleCard(const std::string& name, int cost);

    // Implement the getName method
    std::string getName() const override;

    // Implement the getCost method
    int getCost() const override;
};