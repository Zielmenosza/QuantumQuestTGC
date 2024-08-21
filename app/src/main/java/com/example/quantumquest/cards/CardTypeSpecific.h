
#ifndef CARDTYPESPECIFIC_H
#define CARDTYPESPECIFIC_H

#include "Card.h"

class CardTypeSpecific : public Card {
public:
    CardTypeSpecific(const std::string& name, int power);
    void activateEffect() override;
    int getPower() const;
    
private:
    int m_power;
};

#endif // CARDTYPESPECIFIC_H

