#ifndef CARD_EFFECT_H
#define CARD_EFFECT_H

#include <string>
#include "card.h"  // Assuming card.h defines the Card base class
#include "player.h"  // Assuming player.h defines the Player class

class CardEffect : public Card {
public:
    // Constructor for CardEffect, inheriting from Card
    CardEffect(const std::string& name, const std::string& description, int cost);

    // Getter methods
    [[nodiscard]] std::string getName() const override;
    [[nodiscard]] int getCost() const override;
    [[nodiscard]] std::string getDescription() const;

    // Method to play the card, affecting the game state
    void Play(GameState& gameState) override;

    // Method to apply the card effect to a player
    void applyEffect(Player& player);

private:
    std::string description;
};

#endif // CARD_EFFECT_H