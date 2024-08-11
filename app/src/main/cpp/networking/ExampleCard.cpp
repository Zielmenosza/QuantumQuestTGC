#include "ExampleCard.h"

ExampleCard::ExampleCard(const std::string& name, const std::string& description, int cost, int power)
        : Card(name, description, cost), power_(power) {}

int ExampleCard::getPower() const {
    return power_;
}