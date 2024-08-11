#pragma once

#include <vector>
#include <memory>
#include <random>  // Include for random number generation
#include "card.h"

class CardPool {
public:
    CardPool();  // Constructor declaration
    std::shared_ptr<Card> drawRandomCard();  // Function to draw a random card

    // Function to add a card to the pool
    void addCard(const std::shared_ptr<Card>& card);

    // Function to remove a card from the pool
    void removeCard(const std::shared_ptr<Card>& card);

    // Function to check if the pool is empty
    bool isEmpty() const;

    // Function to get the number of cards in the pool
    size_t size() const;

private:
    std::vector<std::shared_ptr<Card>> cards;  // Vector to store cards
    std::mt19937 generator;  // Random number generator
};