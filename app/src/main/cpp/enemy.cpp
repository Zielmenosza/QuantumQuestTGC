#include <iostream>
#include "enemy.h"

// Constructor
Enemy::Enemy(const std::string& name, int health, int attackPower, int defense)
        : Character(name, attackPower, health), attackPower(attackPower), defense(defense) {}

// Destructor
Enemy::~Enemy() {
    // Cleanup code if necessary
}

// Method for attacking another character
void Enemy::attack(Character& target) {
    int damageDealt = attackPower - target.getDefense();
    if (damageDealt < 0) {
        damageDealt = 0;  // Ensure damage doesn't go negative
    }

    target.takeDamage(damageDealt);

    std::cout << getName() << " attacks " << target.getName()
              << " for " << damageDealt << " damage." << std::endl;
}

// Method for taking damage
void Enemy::takeDamage(int damage) {
    int reducedDamage = damage - defense;
    if (reducedDamage < 0) {
        reducedDamage = 0;  // Ensure damage doesn't go negative
    }

    health -= reducedDamage;

    if (health < 0) {
        health = 0;  // Prevent health from going negative
    }

    std::cout << getName() << " takes " << reducedDamage
              << " damage and now has " << health << " health." << std::endl;
}

// Method to display current status of the enemy
void Enemy::displayStatus() const {
    std::cout << "Enemy: " << getName() << "\n"
              << "Health: " << getHealth() << "\n"
              << "Attack Power: " << attackPower << "\n"
              << "Defense: " << defense << "\n"
              << std::endl;
}