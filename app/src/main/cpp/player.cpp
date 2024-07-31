#include "player.h"

// ...

void Player::reduceIncomingDamage(int amount) {
    incomingDamageReduction_ += amount;
}

void Player::takeDamage(int amount) {
    health -= std::max(0, amount - incomingDamageReduction_);
    incomingDamageReduction_ = 0; // Reset the reduction after applying it
}