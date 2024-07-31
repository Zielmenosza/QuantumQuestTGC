#ifndef CARD_EFFECT_H
#define CARD_EFFECT_H

#include <vector>
#include <memory> // Include for std::shared_ptr
#include <string>
#include "card.h"

class Player {
public:
    // Default constructor with noexcept for Android compatibility
    Player() noexcept : health(100) {}

    // Constructor with name parameter (optional)
    Player(const std::string& name) : name_(name), health(100) {}

    // Function to get a constant reference to the player's hand
    const std::vector<std::shared_ptr<Card>>& getHand() const {
        return hand_;
    }

    // Add member functions for setMovementPoints and getMovementPoints
    void setMovementPoints(int points) {
        movementPoints_ = points;
    }

    int getMovementPoints() const {
        return movementPoints_;
    }

    // Additional member functions (optional, based on your needs)
    int getHealth() const; // Get player's health (example)
    void addToHand(const std::shared_ptr<Card>& card); // Add card to hand (example)

private:
    std::string name_; // Member for player name (optional)
    std::vector<std::shared_ptr<Card>> hand_; // Stores smart pointers to Card
    int health; // Member for player health
    int movementPoints_; // Member for player movement points

    // Add other private member variables and member functions (if any)
};

#endif // CARD_EFFECT_H