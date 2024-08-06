#include "player.h"

#include <utility>

Player::Player() : name_{"Player"}, maxHealth_{100}, currentHealth_{100}, shield_{0} {}

std::string Player::getName() const {
    return name_;
}

void Player::reduceIncomingDamage(int damage) {
    if (shield_ > 0) {
        int damageToShield = std::min(damage, shield_);
        shield_ -= damageToShield;
        damage -= damageToShield;
    }
    currentHealth_ -= damage;
}

Player::Player(std::string  name) : name_(std::move(name)), maxHealth_{100}, currentHealth_{100}, shield_{0} {}

void Player::addToHand(const std::shared_ptr<Card>& card) {
    hand_.push_back(card);
}const std::vector<std::shared_ptr<Card>>& Player::getHand() const {
    return hand_;
}

int Player::getHealth() const {
    return currentHealth_;
}

void Player::setHealth(int newHealth) {
    currentHealth_ = newHealth;
}

void Player::heal(int amount) {
    currentHealth_ = std::min(currentHealth_ + amount, maxHealth_);
}

void Player::increaseMovementPoints(int points) {
    // Implement logic to increase movement points, e.g.,
    // movementPoints_ += points; (if you have a movementPoints_ member)
}

void Player::takeTurn() {
    // Implement logic to take a turn, e.g.,
    // std::cout << "Player " << name_ << " takes a turn" << std::endl;
}