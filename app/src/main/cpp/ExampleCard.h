#pragma once

#include "card.h"
#include <string>

class ExampleCard : public Card {
private:
    std::string name;
    int cost;

public:
    ExampleCard(const std::string& name, int cost);

    std::string getName() const override;
    int getCost() const override;
};