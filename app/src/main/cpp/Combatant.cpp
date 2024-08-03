#include "Combatant.h"

// Constructor definition
Combatant::Combatant(const std::string& name, int health, int attackPower, int defense)
        : name(name), health(health), attackPower(attackPower), defense(defense) {}

// Perform attack
void Combatant::performAttack(Combatant& target) {
    int damage = getAttackPower() - target.getDefense();
    if (damage > 0) {
        target.takeDamage(damage);
    }
}

// Take damage
void Combatant::takeDamage(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}

// Check if combatant is alive
bool Combatant::isAlive() const {
    return health > 0;
}

// Get name
std::string Combatant::getName() const {
    return name;
}

// Get health
int Combatant::getHealth() const {
    return health;
}

// Get attack power
int Combatant::getAttackPower() const {
    return attackPower;
}

// Get defense
int Combatant::getDefense() const {
    return defense;
}