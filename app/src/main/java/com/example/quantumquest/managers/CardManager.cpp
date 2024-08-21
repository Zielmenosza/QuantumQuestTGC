#include "CardManager.h"
#include <iostream>

CardManager::CardManager(CardRepository* repository)
    : m_repository(repository) {}

void CardManager::drawCard() {
    // Implement logic to draw a card
    std::cout << "Drawing a card from the repository." << std::endl;
}

void CardManager::useCard(const std::string& name) {
    Card* card = m_repository->getCard(name);
    if (card) {
        card->activateEffect();
    } else {
        std::cout << "Card not found: " << name << std::endl;
    }
}
