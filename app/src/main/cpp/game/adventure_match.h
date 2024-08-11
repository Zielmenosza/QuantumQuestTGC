#ifndef ADVENTURE_MATCH_H
#define ADVENTURE_MATCH_H

#include "player.h"
#include "enemy.h"
#include <memory>
#include "card_type_specific.h"
#include <vector>

// Class to manage an adventure match
class AdventureMatch {
public:
    // Constructor for AdventureMatch
    AdventureMatch(Player& player, Enemy& enemy);

    // Start the match
    void start();

private:
    Player& player;
    Enemy& enemy;
    std::vector<CardTypeSpecific> deck;

    // Initialize the deck with some cards
    void initializeDeck();
};

#endif // ADVENTURE_MATCH_H