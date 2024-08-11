#ifndef BASE_CARD_H
#define BASE_CARD_H

#include <string>

class BaseCard {
public:
    // Destructor to allow cleanup for derived classes
    virtual ~BaseCard() = default;

    // Pure virtual functions to be implemented by derived classes
    virtual int getCost() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
};

#endif // BASE_CARD_H