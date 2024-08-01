#ifndef CARD_H
#define CARD_H

#include <string>

// Forward declaration of GameState class
class GameState;

class Card {
public:
    virtual ~Card() {}  // Virtual destructor for proper cleanup of derived classes

    // Assuming you want each card to have a name and a cost
    virtual std::string getName() const = 0;  // Pure virtual function to get the card's name
    virtual int getCost() const = 0;          // Pure virtual function to get the card's cost

    // Add a virtual function that derived classes can override
    virtual void Play(GameState& gameState) = 0;  // Pure virtual function for playing a card
};

#endif  // CARD_H