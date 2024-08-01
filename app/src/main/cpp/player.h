#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "card.h" // Include Card class header

class Player {
public:
    Player(const std::string& name, int maxHealth, int shield);

    // Add a card to the player's hand
    void addToHand(const std::shared_ptr<Card>& card);

    // Reduce incoming damage
    void reduceIncomingDamage(int damage);

    // Get the player's current health
    int getHealth() const;

    // Get the player's hand
    const std::vector<std::shared_ptr<Card>>& getHand() const;

private:
    std::string name_; // Player's name
    int max_health_;   // Maximum health
    int current_health_; // Current health
    int shield_;       // Shield value to reduce damage

    std::vector<std::shared_ptr<Card>> hand_; // Player's hand of cards
};

#endif // PLAYER_H