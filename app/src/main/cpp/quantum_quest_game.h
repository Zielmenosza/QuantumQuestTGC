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
    // Initialize the game board with rooms
    void initializeRooms();

    // Move a player in the specified direction
    bool movePlayer(PlayerID player, Direction direction);

    // Get the room at a specific position
    Room getRoomAt(const Position& pos) const;

    // Check if there is an obstacle at a specific position
    bool isObstacleAt(const Position& pos) const;

private:
    std::vector<std::vector<Room>> rooms;   // 2D grid of rooms
    std::vector<Obstacle> obstacles;        // List of obstacles
    std::map<PlayerID, Position> playerPositions; // Mapping of player IDs to positions
};

class QuantumQuestGame {
public:
    // Get the current player
    Player& getCurrentPlayer();

    // Start a new game
    void startNewGame();

    // End the current player's turn
    void endPlayerTurn();

    // Additional functions can be declared here

private:
    GameBoard gameBoard;             // The game board
    std::vector<Player> players;     // Vector of players in the game
    int currentPlayerIndex = 0;      // Index of the current player

    // Private helper functions and variables
};

#endif // QUANTUM_QUEST_GAME_H