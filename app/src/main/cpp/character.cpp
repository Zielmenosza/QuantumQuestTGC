#include <iostream>
#include "character.h"

// Constructor for the Character class, initializing member variables
Character::Character(const std::string& name, int strength, int health, int experience, int level)
        : name(name), strength(strength), health(health), experience(experience), level(level) {}

// Method for taking damage, reduces the character's health
void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0; // Ensure health doesn't go below zero
    }
    std::cout << name << " takes " << damage << " damage and now has " << health << " health." << std::endl;
}

// Method for attacking another character, inflicts damage based on the attacker's strength
void Character::attack(Character& target) {
    int damage = strength; // Calculate damage based on character's strength
    target.takeDamage(damage);
    std::cout << name << " attacks " << target.getName() << " dealing " << damage << " damage." << std::endl;

    // Gain experience from attacking
    gainExperience(10); // Example: gain 10 experience points for each attack
}

// Method to gain experience
void Character::gainExperience(int exp) {
    experience += exp;
    std::cout << name << " gains " << exp << " experience points." << std::endl;

    // Check if the character should level up
    if (experience >= 100) { // Example: level up when reaching 100 experience points
        levelUp();
    }
}

// Method to handle leveling up
void Character::levelUp() {
    level++;
    experience -= 100; // Subtract the experience needed for leveling up
    strength += 5; // Increase strength when leveling up
    health += 10; // Increase health when leveling up

    std::cout << name << " levels up! Now at level " << level << " with " << strength << " strength and " << health << " health." << std::endl;
}