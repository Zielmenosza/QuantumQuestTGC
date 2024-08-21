
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(const std::string& name);
    virtual void activateEffect() = 0;
    std::string getName() const;
    
protected:
    std::string m_name;
};

#endif // CARD_H

