#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "character.h" // Assuming Character is a base class for game entities

class Enemy : public Character {  // Inherit from Character if applicable
public:
    // Constructor with default parameter values for attributes
    Enemy(const std::string& name, int health = 100, int attackPower = 10, int defense = 5);

    // Destructor
    virtual ~Enemy();

    // Methods
    void attack(Character& target);  // Attack a target character
    void takeDamage(int damage);     // Take damage from an attack
    void displayStatus() const;      // Display current status

private:
    int attackPower;  // Attack power of the enemy
    int defense;      // Defense value
};

#endif // ENEMY_H