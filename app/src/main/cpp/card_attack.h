#ifndef CARD_ATTACK_H
#define CARD_ATTACK_H

#include "card.h"        // Include base class header
#include "game_state.h"  // Include GameState class header

class Card_Attack : public Card {
public:
    // Constructor declaration
    Card_Attack(const std::string& name, const std::string& description, int cost);

    // Override the Play function from the Card class
    void Play(GameState& gameState) override;

    std::string getName() const override;
    int getCost() const override;

private:
    std::string name_;
    std::string description_;
    int cost_;
};

#endif  // CARD_ATTACK_H