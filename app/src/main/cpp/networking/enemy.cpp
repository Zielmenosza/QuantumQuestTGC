#include "enemy.h"

#include <utility>

Enemy::Enemy(std::string  name) : enemyName(std::move(name)), enemyHealth(100), enemyAttack(20), type("Goblin") {
    // You can add more initialization logic here if needed
}

Enemy::Enemy(std::string  name, int health, int attack) : enemyName(std::move(name)), enemyHealth(health), enemyAttack(attack), type("Goblin") {
    // You can add more initialization logic here if needed
}std::string Enemy::getType() const {
    return type;
}