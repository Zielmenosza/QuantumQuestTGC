#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include "Direction.h"
#include "room.h" // Assuming Room is defined
#include "player.h" // Assuming Player is defined
#include "PlayerID.h" // Include PlayerID declaration
#include "Position.h" // Include Position declaration

class GameBoard {
public:
    GameBoard(int width, int height);

    bool movePlayer(PlayerID player, Direction direction);
    const Room& getRoomAt(const Position& pos) const;
    bool isObstacleAt(const Position& pos) const;

private:
    std::vector<std::vector<Room>> rooms;
    int width, height;
};

#endif // GAME_BOARD_H