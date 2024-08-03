#include "room.h"
#include <algorithm>  // For std::find and std::remove

bool Room::hasPlayer(const Player& player) const {
    // Check if the player is in the room
    return std::find(players_.begin(), players_.end(), player) != players_.end();
}

void Room::removePlayer(const Player& player) {
    // Remove the player from the room if they exist
    auto it = std::remove(players_.begin(), players_.end(), player);
    if (it != players_.end()) {
        players_.erase(it, players_.end());
    }
}

void Room::addPlayer(const Player& player) {
    // Add the player to the room if not already present
    if (!hasPlayer(player)) {
        players_.push_back(player);
    }
}