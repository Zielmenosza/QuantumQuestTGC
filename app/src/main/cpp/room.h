#pragma once

#include <vector>
#include <memory>
#include "card.h"
#include "Obstacle.h"
#include "player.h"

class Room {
public:
    Room();  // Constructor

    // Add a card to the room
    void addCard(const std::shared_ptr<Card>& card);

    // Add an obstacle to the room
    void addObstacle(const Obstacle& obstacle);

    // Check if the room has an obstacle
    bool hasObstacle() const;

    // Check if a player is in the room
    bool isPlayerPresent() const;

    // Set and get the player in the room
    void setPlayer(const std::shared_ptr<Player>& player);
    std::shared_ptr<Player> getPlayer() const;

    // Retrieve cards in the room
    const std::vector<std::shared_ptr<Card>>& getCards() const;

    // Other member functions as needed

private:
    std::vector<std::shared_ptr<Card>> cards_;   // Cards present in the room
    std::vector<Obstacle> obstacles_;            // Obstacles present in the room
    std::shared_ptr<Player> player_;             // Player currently in the room
};

#endif // ROOM_H