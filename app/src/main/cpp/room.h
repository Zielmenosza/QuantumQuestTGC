#ifndef ROOM_H
#define ROOM_H

#include "player.h"  // Include player or necessary headers
#include <vector>    // For managing the list of players

class Room {
public:
    // Check if the room contains the specified player
    bool hasPlayer(const Player& player) const;

    // Remove the specified player from the room
    void removePlayer(const Player& player);

    // Add the specified player to the room
    void addPlayer(const Player& player);

private:
    // Vector to track players currently in the room
    std::vector<Player> players_;
};

#endif // ROOM_H