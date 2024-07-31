#include "card_pool.h"
#include "card.h" // Include card.h
#include <random>

CardPool::CardPool(const std::vector<Card>& initialCards) : cards(initialCards) {}

void CardPool::addCard(Card card) {
    cards.push_back(card);
}

Card CardPool::getRandomCard() {
    if (cards.empty()) {
        return Card(); // Or throw an exception
    }
    std::random_device rd;
    std::mt19937 gen(rd()); // Added semicolon
    std::uniform_int_distribution<> distrib(0, cards.size() - 1);
    int randomIndex = distrib(gen);
    return cards[randomIndex];
}