#include "game_board.h"

GameBoard::GameBoard(int width, int height) : width(width), height(height) {
    rooms.resize(width, std::vector<Room>(height));
    // Initialize rooms here
}

bool GameBoard::movePlayer(PlayerID player, Direction direction) {
    // Implement player movement logic
    // ...
    return true; // Or return false if movement failed
}

const Room& GameBoard::getRoomAt(const Position& pos) const {
    // Check for valid position
    if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= height) {
        // Handle invalid position
    }
    return rooms[pos.x][pos.y];
}

bool GameBoard::isObstacleAt(const Position& pos) const {
    // Check if there's an obstacle at the given position
    // ...
    return false;
}