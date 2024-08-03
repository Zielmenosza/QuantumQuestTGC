#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

// Base class for all characters in the game
class Character {
public:
    Character(int health, int defense); // Declare the constructor

    virtual int getHealth() const = 0;  // Pure virtual function
    virtual void heal(int amount) = 0;  // Pure virtual function

    int getDefense() const; // Declare getDefense

protected:
    // Member variables for character attributes
    int health;
    int defense;

    // Helper function for reducing health
    void reduceHealth(int amount);
};

#endif // CHARACTER_H