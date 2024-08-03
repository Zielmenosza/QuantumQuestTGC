// game_board.h
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include "room.h"
#include "Position.h"
#include "direction.h"
#include "player.h"

class GameBoard {
public:
    // Constructor to initialize the game board with specified dimensions
    GameBoard(int width, int height);

    // Move a player in the given direction, return true if successful
    bool movePlayer(PlayerID player, Direction direction);

    // Get the room at a specified position
    const Room& getRoomAt(const Position& pos) const;

    // Check if there's an obstacle at a specified position
    bool isObstacleAt(const Position& pos) const;

private:
    int width; // Width of the game board
    int height; // Height of the game board
    std::vector<std::vector<Room>> rooms; // 2D grid of rooms

    // Check if a position is valid within the game board
    bool isValidPosition(const Position& pos) const;

    // Get the current position of a player
    Position getPlayerPosition(PlayerID player) const;

    // Set the new position for a player
    void setPlayerPosition(PlayerID player, const Position& pos);
};

#endif // GAME_BOARD_H