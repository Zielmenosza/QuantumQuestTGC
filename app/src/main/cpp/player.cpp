#include "player.h"

// Constructor to initialize a Player with a name and initial health
Player::Player(const std::string& name, int health) : name(name), health(health) {}

// Implementation of takeDamage function, reducing player's health
void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0; // Health should not be negative
    }
}

// Implementation of getName function, returning player's name
std::string Player::getName() const {
    return name;
}

// Implementation of getHealth function, returning current health
int Player::getHealth() const {
    return health;
}

// Implementation of heal function, increasing player's health
void Player::heal(int amount) {
    health += amount;
    // Optional: Cap health at maximum value if needed
}