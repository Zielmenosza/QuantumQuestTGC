// SpecificCard.h
#pragma once
#include "card.h"  // Ensure correct case sensitivity

class SpecificCard : public Card {
public:
    explicit SpecificCard(const std::string &name) : Card(name) {}
    // Additional methods and members specific to SpecificCard
};