#include "specific_card.h"

// Constructor definition
SpecificCard::SpecificCard(const std::string &name, const std::string &description, int cost)
        : name_(name), description_(description), cost_(cost) {}

// Implementing getName method
std::string SpecificCard::getName() const {
    return name_;
}

// Implementing getCost method
int SpecificCard::getCost() const {
    return cost_;
}

// Implementing getDescription method
std::string SpecificCard::getDescription() const {
    return description_;
}