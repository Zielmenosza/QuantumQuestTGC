#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include "room.h"
#include "Position.h"
#include "Direction.h"
#include "player.h"

class GameBoard {
public:
    GameBoard(int width, int height);

    bool movePlayer(PlayerID player, Direction direction);
    const Room& getRoomAt(const Position& pos) const;
    bool isObstacleAt(const Position& pos) const;

private:
    int width;
    int height;
    std::vector<std::vector<Room>> rooms;

    bool isValidPosition(const Position& pos) const;
    Position getPlayerPosition(PlayerID player) const;
    void setPlayerPosition(PlayerID player, const Position& pos);
};

#endif // GAME_BOARD_H