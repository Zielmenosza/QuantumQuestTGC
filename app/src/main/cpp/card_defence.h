#ifndef CARD_DEFENSE_H
#define CARD_DEFENSE_H

#include "card.h"
#include "game_state.h"
#include <string>

class CardDefense : public Card {
public:
    CardDefense(const std::string& name, const std::string& description, int cost);

    void Play(GameState& gameState);

    // Override the pure virtual method from the base class to play the cardvoid Play(GameState& gameState) override; // Added override

    // Getter methods
    [[nodiscard]] std::string getName() const override;
    [[nodiscard]] int getCost() const override; // Added override
    [[nodiscard]] std::string getDescription() const override; // Added override

private:
    std::string description;
};

#endif // CARD_DEFENSE_H