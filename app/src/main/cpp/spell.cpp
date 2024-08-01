#include "spell.h"

// Constructor implementation
Spell::Spell(const std::string& name, const std::string& description, int manaCost)
        : name_(name), description_(description), manaCost_(manaCost) {}

// Getter for the name
std::string Spell::getName() const {
    return name_;
}

// Getter for the description
std::string Spell::getDescription() const {
    return description_;
}

// Getter for the mana cost
int Spell::getManaCost() const {
    return manaCost_;
}

// Example implementation for a derived spell class
// This should be in another file, like fire_spell.cpp
/*
class FireSpell : public Spell {
public:
    FireSpell() : Spell("Fireball", "Deals fire damage to the target", 5) {}

    void applyEffect(Player& player) override {
        // Implement effect logic
        player.takeDamage(10);  // Hypothetical method to damage player
    }
};
*/