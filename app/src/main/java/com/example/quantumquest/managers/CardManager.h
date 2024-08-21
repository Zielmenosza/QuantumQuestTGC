#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include "CardRepository.h"

class CardManager {
public:
    CardManager(CardRepository* repository);
    void drawCard();
    void useCard(const std::string& name);
    
private:
    CardRepository* m_repository;
};

#endif // CARDMANAGER_H
