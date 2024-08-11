// game_board.cpp
#include "game_board.h"
#include "player_id.h"
#include "player.h"
#include <iostream>

// Constructor to initialize the game board with specified dimensions
GameBoard::GameBoard(int width, int height) : width(width), height(height),
                                              gameState(Player()) {
    rooms.resize(width, std::vector<Room>(height));
    // Initialize rooms and any obstacles here
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            // Initialize each room, potentially add obstacles, etc.
            rooms[x][y] = Room();  // Replace with appropriate room initialization if needed
        }
    }
}

// Move a player in the given direction
bool GameBoard::movePlayer(PlayerID player, Direction direction) {
    Position currentPos = getPlayerPosition(player);
    Position newPos = currentPos;
    Player& playerObj = gameState.getPlayer(player); // Access gameState member

    // Calculate new position based on the direction
    switch (direction) {
        case Direction::UP:
            newPos.y -= 1;
            break;
        case Direction::DOWN:
            newPos.y += 1;
            break;
        case Direction::LEFT:
            newPos.x -= 1;
            break;
        case Direction::RIGHT:
            newPos.x += 1;
            break;
        case Direction::UP_LEFT:
            newPos.x -= 1;
            newPos.y -= 1;
            break;
        case Direction::UP_RIGHT:
            newPos.x += 1;
            newPos.y -= 1;
            break;
        case Direction::DOWN_LEFT:
            newPos.x -= 1;
            newPos.y += 1;
            break;
        case Direction::DOWN_RIGHT:
            newPos.x += 1;
            newPos.y += 1;
            break;
    }

    // Check if the new position is valid and not blocked by an obstacle
    if (isValidPosition(newPos) && !isObstacleAt(newPos)) {
        rooms[currentPos.x][currentPos.y].removePlayer(playerObj); // Use currentPos here
        rooms[newPos.x][newPos.y].addPlayer(playerObj); // Use newPos here
        setPlayerPosition(player, newPos);
        return true;
    }

    std::cout << "Movement blocked at position: (" << newPos.x << ", " << newPos.y << ")" << std::endl;return false;
}

// Get the room at the given position
const Room& GameBoard::getRoomAt(const Position& pos) const {
    if (isValidPosition(pos)) {
        return rooms[pos.x][pos.y];
    }
    throw std::out_of_range("Invalid position accessed.");
}

// Check if there's an obstacle at the given position
bool GameBoard::isObstacleAt(const Position& pos) const {
    if (isValidPosition(pos)) {
        return rooms[pos.x][pos.y].hasObstacle();  // Assuming Room has hasObstacle() method
    }
    return false;
}

// Check if the position is within bounds
bool GameBoard::isValidPosition(const Position& pos) const {
    return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
}

// Get the player's current position
Position GameBoard::getPlayerPosition(PlayerID player) const {
    Position playerPos;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            Player& playerObj = gameState.getPlayer(player);
            if (rooms[x][y].hasPlayer(playerObj)) {
                playerPos = {x, y};
                break;
            }
        }
    }
    return playerPos;
}

// Set the player's position
void GameBoard::setPlayerPosition(PlayerID player, const Position& pos) {
    Position currentPos = getPlayerPosition(player);
    Player& playerObj = gameState.getPlayer(player);
    rooms[currentPos.x][currentPos.y].removePlayer(playerObj);
    rooms[pos.x][pos.y].addPlayer(playerObj);
}