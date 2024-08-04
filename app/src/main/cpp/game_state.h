#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <unordered_map>
#include "player.h"
#include "player_id.h"

class GameState {
public:
    // Constructor
    GameState(Player player);

    Player & getPlayer(PlayerID id) const;

    // Methods to get and set player health
    int getPlayerHealth(PlayerID playerID) const;
    void setPlayerHealth(PlayerID playerID, int newHealth);

    // Methods to get and set the current player
    Player& getCurrentPlayer();
    void setCurrentPlayer(PlayerID playerID);

private:
    Player player1_; // Player object for Player One
    std::unordered_map<PlayerID, Player> players;
    int player1Health_; // Health of Player One
    int player2Health_; // Health of Player Two
    PlayerID currentPlayer_;
    // Additional state variables as needed
};

#endif // GAME_STATE_H