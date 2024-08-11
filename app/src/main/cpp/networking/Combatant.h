#ifndef QUANTUMQUEST_COMBATANT_H
#define QUANTUMQUEST_COMBATANT_H

#include <string>

class Combatant {
public:
    Combatant(const std::string& name, int health, int attackPower, int defense);
    virtual ~Combatant() = default;

    // Combat functions
    virtual void performAttack(Combatant& target); // Rename function to avoid conflict
    void takeDamage(int amount);
    bool isAlive() const;

    // Getters for combatant stats
    [[nodiscard]] std::string getName() const; // Remove static
    [[nodiscard]] int getHealth() const; // Remove static
    int getAttackPower() const; // Remove static
    int getDefense() const; // Remove static

protected:
    std::string name;
    int health;
    int attackPower;  // Rename the variable to avoid conflict with method
    int defense;
};

#endif // QUANTUMQUEST_COMBATANT_H