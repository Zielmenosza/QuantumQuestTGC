#include "card.h"

// Implement the constructor to initialize card's name and cost
Card::Card(const std::string& name, int cost) : name(name), cost(cost) {}

// Virtual destructor
Card::~Card() = default;

// Method to get the card's name
std::string Card::getName() const {
    return name;
}

// Method to get the card's cost
int Card::getCost() const {
    return cost;
}