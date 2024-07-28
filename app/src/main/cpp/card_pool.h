#ifndef CARD_POOL_H
#define CARD_POOL_H

#include <vector>
#include "card.h"

class CardPool {
public:
    CardPool(const std::vector<Card>& initialCards) : cards(initialCards) {}

    // Add, remove, or get cards as needed

private:
    std::vector<Card> cards; // Store cards by value
};

#endif // CARD_POOL_H