#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include <memory>
#include "player.h" // Include the Player class header

class GameState {
public:
    GameState();

    // Methods to access and modify game state
    int getPlayerHealth(int playerNumber) const;
    void setPlayerHealth(int playerNumber, int newHealth);
    int getCurrentPlayer() const;
    void setCurrentPlayer(int newPlayer);

    Player* getActivePlayer() const;
    void nextTurn(); // Advance to the next player's turn

    void addPlayer(std::unique_ptr<Player> player);
    const std::vector<std::unique_ptr<Player>>& getPlayers() const;

private:
    int currentPlayerIndex;
    std::vector<std::unique_ptr<Player>> players;
};

#endif  // GAME_STATE_H