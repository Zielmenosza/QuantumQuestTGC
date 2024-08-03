// spell.h
#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "player.h"  // Assuming spells can affect players

class Spell {
public:
    // Constructor with spell name, description, and mana cost
    Spell(const std::string& name, const std::string& description, int manaCost);

    // Virtual destructor for cleanup
    virtual ~Spell() {}

    // Getters for spell properties
    std::string getName() const;
    std::string getDescription() const;
    int getManaCost() const;

    // Apply the spell's effect, to be overridden by derived spell types
    virtual void applyEffect(Player& player) = 0;  // Pure virtual method

private:
    std::string name_;
    std::string description_;
    int manaCost_;
};

#endif // SPELL_H