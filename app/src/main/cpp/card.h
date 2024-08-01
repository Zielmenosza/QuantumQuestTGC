#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(const std::string& name);
    virtual ~Card();

    std::string getName() const; // New method for getting card name

private:
    std::string name;
};

#endif // CARD_H