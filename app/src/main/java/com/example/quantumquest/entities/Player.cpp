
#include "Player.h"

Player::Player(const std::string& name)
    : m_name(name) {}

void Player::drawCard(Card* card) {
    m_hand.push_back(card);
}

void Player::playCard(const std::string& cardName) {
    // Implement card play logic
}

std::string Player::getName() const {
    return m_name;
}

