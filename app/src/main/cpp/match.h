#ifndef MATCH_H
#define MATCH_H

#include <string>
#include "player.h"
#include "game_state.h"

// The Match class is a base class for different types of game matches.
// It handles the interaction between two players and manages the game state.
class Match {
public:
    // Constructor to initialize the match with two players
    Match(Player* player1, Player* player2);

    // Virtual destructor for cleanup
    virtual ~Match() {}

    // Pure virtual methods for starting, updating, and ending the match
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void end() = 0;

protected:
    Player* player1_;  // Pointer to the first player
    Player* player2_;  // Pointer to the second player
    GameState gameState_;  // The state of the game during the match
};

#endif // MATCH_H