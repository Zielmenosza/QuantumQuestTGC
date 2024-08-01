#include "card_pool.h"
#include "card.h" // Include the Card class definition
#include <random>

// Constructor for CardPool, initializes with a given set of cards
CardPool::CardPool(const std::vector<Card>& initialCards) : cards(initialCards) {}

// Adds a card to the pool
void CardPool::addCard(const Card& card) {
    cards.push_back(card);
}

// Returns a random card from the pool
Card CardPool::getRandomCard() {
    if (cards.empty()) {
        throw std::runtime_error("Card pool is empty. Cannot get a random card.");
    }

    // Random number generator for selecting a random card
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distrib(0, cards.size() - 1); // Define the range

    int randomIndex = distrib(gen);
    return cards[randomIndex];
}