// game_board.cpp
#include "game_board.h"
#include "player_id.h"
#include "player.h"
#include <iostream>

// Constructor to initialize the game board with specified dimensions
GameBoard::GameBoard(int width, int height) : width(width), height(height) {
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
        setPlayerPosition(player, newPos);
        return true;
    }

    std::cout << "Movement blocked at position: (" << newPos.x << ", " << newPos.y << ")" << std::endl;
    return false;
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
    // Implement logic to find the player's position
    // This could involve iterating through rooms to find where the player is
    Position playerPos; // Initialize to the player's actual position
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (rooms[x][y].hasPlayer(player)) {  // Assuming Room has hasPlayer method
                playerPos = {x, y};
                break;
            }
        }
    }
    return playerPos;
}

// Set the player's position
void GameBoard::setPlayerPosition(PlayerID player, const Position& pos) {
    // Implement logic to update the player's position
    // Ensure the player is removed from the old room and placed in the new one
    Position currentPos = getPlayerPosition(player);
    rooms[currentPos.x][currentPos.y].removePlayer(player); // Assuming Room has removePlayer method
    rooms[pos.x][pos.y].addPlayer(player); // Assuming Room has addPlayer method
}