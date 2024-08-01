#pragma once
#include <string>

class Card {
public:
    virtual ~Card() {}  // Virtual destructor to ensure proper cleanup of derived classes

    // Assuming you want each card to have a name and a cost
    virtual std::string getName() const = 0;  // Pure virtual function to get the card's name
    virtual int getCost() const = 0;          // Pure virtual function to get the card's cost

    // Other members and virtual functions as needed
};