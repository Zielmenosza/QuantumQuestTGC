// game_state.h
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "player.h"
#include "player_id.h"

class GameState {
public:
    GameState();

    int getPlayerHealth(PlayerID playerID) const;
    void setPlayerHealth(PlayerID playerID, int newHealth);

    PlayerID getCurrentPlayer() const;
    void setCurrentPlayer(PlayerID playerID);

private:
    int player1Health_;
    int player2Health_;
    PlayerID currentPlayer_;
    // Additional state variables as needed
};

#endif // GAME_STATE_H