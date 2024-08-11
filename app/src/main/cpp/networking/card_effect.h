#ifndef CARDEFFECT_H
#define CARDEFFECT_H

#include <string>
#include "card.h"  // Assuming card.h defines the Card base class
#include "player.h"  // Assuming player.h defines the Player class
#include "game_state.h"

class CardEffect : public Card {
private:
    std::string description;

public:
    CardEffect(const std::string& name, const std::string& description, int cost);

    void activateEffect(Player& player); // Add Player& argument to declaration

    void Play(GameState& gameState);

    std::string getName() const;

    int getCost() const;

    std::string getDescription() const;
};

#endif //CARDEFFECT_H