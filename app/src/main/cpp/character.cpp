#include "character.h"

// Constructor implementation for Character
Character::Character(int health, int defense) : health(health), defense(defense) {}

// Returns the current defense value
int Character::getDefense() const {
    return defense;
}

// Reduces health by a specified amount, ensuring it does not go below zero
void Character::reduceHealth(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0; // Ensure health doesn't go negative
    }
}