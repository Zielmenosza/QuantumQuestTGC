#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
public:
    void attack(Character& target); // Attacks target character
    void takeDamage(int amount) override;
    std::string getName() const override;
};

#endif // ENEMY_H