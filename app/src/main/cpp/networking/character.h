#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

// Base class for all characters in the game
class Character {
public:
    // Pure virtual functions for character behavior
    virtual int getHealth() const = 0;
    virtual void heal(int amount) = 0;

protected:
    // Member variables for character attributes
    int health;
    int defense;

    // Helper function for reducing health
    void reduceHealth(int amount);

    // Constructor to initialize health and defense
    Character(int health, int defense);
};

#endif // CHARACTER_H