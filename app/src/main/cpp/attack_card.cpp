#include "attack_card.h"

// Constructor implementation
AttackCard::AttackCard(const std::string& name, const std::string& description, int cost, int attackValue)
        : name_(name), description_(description), cost_(cost), attackValue_(attackValue) {}

// Get the cost of the card
int AttackCard::getCost() const {
    return cost_;
}

// Get the name of the card
std::string AttackCard::getName() const {
    return name_;
}

// Get the description of the card
std::string AttackCard::getDescription() const {
    return description_;
}

// Get the attack value of the card
int AttackCard::getAttackValue() const {
    return attackValue_;
}