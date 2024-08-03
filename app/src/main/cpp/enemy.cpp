#include "enemy.h"

void Enemy::attack(Character& target) {
    // Example attack implementation
    target.takeDamage(10);
}

void Enemy::takeDamage(int amount) {
    // Implement how enemy takes damage
}

std::string Enemy::getName() const {
    return "Enemy";
}