#ifndef CARDREPOSITORY_H
#define CARDREPOSITORY_H

#include <vector>
#include "Card.h"

class CardRepository {
public:
    CardRepository();
    void addCard(Card* card);
    Card* getCard(const std::string& name);
    std::vector<Card*> getAllCards();

private:
    std::vector<Card*> m_cards;
};

#endif // CARDREPOSITORY_H
