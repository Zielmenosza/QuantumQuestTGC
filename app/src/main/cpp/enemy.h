#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int health, int attack); // Constructor declaration
    std::string getType() const; // Method declaration

private:
    std::string enemyName;
    int enemyHealth;
    int enemyAttack;
    std::string type; // Add a type member variable if needed
};

#endif // ENEMY_H