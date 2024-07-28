#include <iostream>
#include "character.h"

Character::Character(const std::string& name, int strength, int health, int experience, int level)
        : name(name), strength(strength), health(health), experience(experience), level(level) {}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    std::cout << name << " takes " << damage << " damage and now has " << health << " health." << std::endl;
}

void Character::attack(Character& target) {
    int damage = strength; // Example damage calculation
    target.takeDamage(damage);
    std::cout << name << " attacks " << target.getName() << " dealing " << damage << " damage." << std::endl;
}