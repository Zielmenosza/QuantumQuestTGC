#include "CardRepository.h"

CardRepository::CardRepository() {}

void CardRepository::addCard(Card* card) {
    m_cards.push_back(card);
}

Card* CardRepository::getCard(const std::string& name) {
    for (auto* card : m_cards) {
        if (card->getName() == name) {
            return card;
        }
    }
    return nullptr;
}

std::vector<Card*> CardRepository::getAllCards() {
    return m_cards;
}
