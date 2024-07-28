#ifndef QUANTUM_QUEST_GAME_H
#define QUANTUM_QUEST_GAME_H

#include <vector>
#include <map>
#include "room.h"
#include "Obstacle.h"
#include "player.h"
#include "card.h"
#include "PlayerID.h"
#include "Direction.h"
#include "Position.h"

class GameBoard {
public:
    void initializeRooms();
    bool movePlayer(PlayerID player, Direction direction);
    Room getRoomAt(Position pos) const;
    bool isObstacleAt(Position pos) const;

private:
    std::vector<std::vector<Room>> rooms;
    std::vector<Obstacle> obstacles;
    std::map<PlayerID, Position> playerPositions;
};

class QuantumQuestGame {
public:
    Player getCurrentPlayer() const;
    void startNewGame();
    void endPlayerTurn();
    // ... (other member functions you might need for your game)

private:
    GameBoard gameBoard;
    std::vector<Player> players; // Vector of players in the game
    int currentPlayerIndex;      // Index of the current player
    // ... (other member variables)
};

#endif // QUANTUM_QUEST_GAME_H