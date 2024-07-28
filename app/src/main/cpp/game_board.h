#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include "Direction.h"
#include "Room.h" // Assuming Room is defined
#include "player.h" // Assuming Player is defined

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