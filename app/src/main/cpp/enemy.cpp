#include "enemy.h"

Enemy::Enemy(const std::string& name, int health, int attack): enemyName(name), enemyHealth(health), enemyAttack(attack) {} // Correct initializer list

std::string Enemy::getType() const {
    return type;
}