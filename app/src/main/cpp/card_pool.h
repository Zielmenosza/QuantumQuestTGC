#ifndef CARD_POOL_H
#define CARD_POOL_H

#include <vector>
#include "card.h" // Include card.h

class CardPool {
public:
    CardPool(const std::vector<Card>& initialCards);

    void addCard(Card card);

    Card getRandomCard();

private:
    std::vector<Card> cards;
};

#endif // CARD_POOL_H