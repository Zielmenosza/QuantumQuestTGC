
#include "ExampleCard.h"

ExampleCard::ExampleCard(const std::string& name, int power)
    : CardTypeSpecific(name, power) {}

void ExampleCard::activateEffect() {
    // Implement the specific effect for ExampleCard
}

