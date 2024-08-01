#ifndef CARD_POOL_H
#define CARD_POOL_H

#include <vector>
#include <stdexcept> // Include for std::runtime_error
#include "card.h"    // Include card.h for Card class definition

class CardPool {
public:
    // Constructor that initializes the pool with a set of cards
    explicit CardPool(const std::vector<Card>& initialCards);

    // Adds a card to the pool
    void addCard(const Card& card);

    // Retrieves a random card from the pool
    Card getRandomCard();

private:
    std::vector<Card> cards;
};

#endif // CARD_POOL_H