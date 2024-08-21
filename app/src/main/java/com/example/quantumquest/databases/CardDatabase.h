
#ifndef CARDDATABASE_H
#define CARDDATABASE_H

#include <map>
#include "Card.h"

class CardDatabase {
public:
    void loadCardsFromFile(const std::string& filename);
    Card* getCard(const std::string& name) const;
    
private:
    std::map<std::string, Card*> m_cardMap;
};

#endif // CARDDATABASE_H

