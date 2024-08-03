// game_state.h
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "player.h"
#include "player_id.h"

class GameState {
public:
    // Constructor
    GameState();

    // Methods to get and set player health
    int getPlayerHealth(PlayerID playerID) const;
    void setPlayerHealth(PlayerID playerID, int newHealth);

    // Methods to get and set the current player
    PlayerID getCurrentPlayer() const;
    void setCurrentPlayer(PlayerID playerID);

private:
    int player1Health_;   // Health of Player One
    int player2Health_;   // Health of Player Two
    PlayerID currentPlayer_; // Current player's turn
    // Additional state variables as needed
};

#endif // GAME_STATE_H