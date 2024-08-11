#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    explicit Enemy(std::string  name);
    Enemy(std::string  name, int health, int attack);
    [[nodiscard]] std::string getType() const;

private:
    std::string enemyName;
    int enemyHealth;
    int enemyAttack;
    std::string type;
};

#endif // ENEMY_H