#ifndef CARD_DEFENSE_H
#define CARD_DEFENSE_H

#include "card.h"
#include <string>

class CardDefense : public Card {
public:
    // Constructor for CardDefense, initializing with name, description, and cost
    CardDefense(const std::string& name, const std::string& description, int cost);

    // Override the pure virtual method from the base class to play the card
    void Play(GameState& gameState) override;

    // Getter methods
    [[nodiscard]] std::string getName() const override;
    [[nodiscard]] int getCost() const override;
    [[nodiscard]] std::string getDescription() const;

private:
    std::string description;
};

#endif // CARD_DEFENSE_H