#ifndef CARD_H
#define CARD_H

#include <string>

// Forward declare GameState if it's defined in another file
class GameState;

class Card {
public:
    // Constructor to initialize card with name and cost
    Card(const std::string &name, int cost);

    // Virtual destructor to ensure derived classes are destructed properly
    virtual ~Card(); // Declaration only

    // Pure virtual method to play the card, modifying the game state
    virtual void Play(GameState& gameState) = 0;

    // Pure virtual method to get the name of the card
    virtual std::string getName() const = 0;

    // Pure virtual method to get the cost of the card
    virtual int getCost() const = 0;

protected:
    // Member variables for card properties
    std::string name; // Name of the card
    int cost;         // Cost of the card
};

#endif // CARD_H