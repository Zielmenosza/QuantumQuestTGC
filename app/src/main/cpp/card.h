// Card.h
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(const std::string& name) : name(name) {}  // Add a constructor that takes a string
    virtual ~Card() {}

private:
    std::string name;
};

#endif // CARD_H