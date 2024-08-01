#include "card.h"

// Constructor
Card::Card(const std::string& name) : name(name) {}

// Destructor
Card::~Card() {}

// Method to get the card's name
std::string Card::getName() const {
    return name;
}