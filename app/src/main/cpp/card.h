#ifndef CARD_H
#define CARD_H

#include <string>

// Base class for all cards in the game
class Card {
public:
    // Constructor for Card
    Card(const std::string& name, const std::string& description, int cost); // Added description
    virtual ~Card() = default; // Virtual destructor

    virtual std::string getName() const { return name_; }
    virtual std::string getDescription() const { return description_; } // Added for consistency
    virtual int getCost() const { return cost_; }

protected:
    std::string name_;
    std::string description_; // Added description
    int cost_;
};

#endif // CARD_H