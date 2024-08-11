#include "specific_card.h"

// Constructor definition
SpecificCard::SpecificCard(const std::string &name, const std::string &description, int cost) : Card(name, description, cost) {}

std::string SpecificCard::getName() const {
    return name_;
}

int SpecificCard::getCost() const {
    return cost_;
}

std::string SpecificCard::getDescription() const {
    return description_;
}