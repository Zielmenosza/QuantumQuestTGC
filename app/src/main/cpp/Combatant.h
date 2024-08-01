#ifndef QUANTUMQUEST_COMBATANT_H
#define QUANTUMQUEST_COMBATANT_H

#include <string>

class Combatant {
public:
    Combatant(const std::string& name, int health, int attack, int defense);
    virtual ~Combatant() = default;

    // Combat functions
    virtual void attack(Combatant& target);
    void takeDamage(int amount);
    bool isAlive() const;

    // Getters for combatant stats
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;

protected:
    std::string name;
    int health;
    int attack;
    int defense;
};

#endif //QUANTUMQUEST_COMBATANT_H