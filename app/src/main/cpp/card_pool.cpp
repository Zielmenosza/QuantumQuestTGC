#include "card_pool.h"
#include <random>  // For std::mt19937 and std::uniform_int_distribution

CardPool::CardPool() {
    // Initialize the random number generator with a random seed
    std::random_device rd;
    generator = std::mt19937(rd());
}

// Draw a random card from the pool
std::shared_ptr<Card> CardPool::drawRandomCard() {
    if (cards.empty()) {
        return nullptr;  // Handle the empty pool case
    }

    // Use uniform_int_distribution for better random distribution
    std::uniform_int_distribution<size_t> distribution(0, cards.size() - 1);
    size_t randomIndex = distribution(generator);
    return cards[randomIndex];
}

// Add a card to the pool
void CardPool::addCard(const std::shared_ptr<Card>& card) {
    cards.push_back(card);
}

// Remove a card from the pool
void CardPool::removeCard(const std::shared_ptr<Card>& card) {
    auto it = std::remove(cards.begin(), cards.end(), card);
    if (it != cards.end()) {
        cards.erase(it, cards.end());
    }
}

// Check if the card pool is empty
bool CardPool::isEmpty() const {
    return cards.empty();
}

// Get the number of cards in the pool
size_t CardPool::size() const {
    return cards.size();
}