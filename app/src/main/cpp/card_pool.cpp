#include "card_pool.h"

CardPool::CardPool(const std::vector<Card>& initialCards) : cards(initialCards) {}

// Example of adding a card to the pool
void CardPool::addCard(const Card& card) {
    cards.push_back(card);
}

// Example of getting a random card from the pool
Card CardPool::getRandomCard() {
    if (cards.empty()) {
        // Handle empty card pool
        return Card(); // Or throw an exception
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, cards.size() - 1);
    int randomIndex = distrib(gen);
    return cards[randomIndex];
}