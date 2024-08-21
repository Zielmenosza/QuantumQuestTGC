
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
public:
    Player(const std::string& name);
    void drawCard(Card* card);
    void playCard(const std::string& cardName);
    std::string getName() const;
    
private:
    std::string m_name;
    std::vector<Card*> m_hand;
};

#endif // PLAYER_H

