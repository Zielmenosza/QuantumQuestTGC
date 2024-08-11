#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "card.h"

class Player {
public:
    std::string getName() const;

    Player();

    void addToHand(const std::shared_ptr<Card> &card);

    Player(std::string  name); // Add this constructor

    const std::vector<std::shared_ptr<Card>> &getHand() const;

    void increaseMovementPoints(int points);
    void setHealth(int newHealth);
    void reduceIncomingDamage(int damage);
    int getHealth() const;
    void heal(int amount);
    void takeTurn();

    // Add these getter methods
    int getMaxHealth() const { return maxHealth_; }
    int getShield() const { return shield_; }

    // Declare the operator== as a friend function
    friend bool operator==(const Player& lhs, const Player& rhs);

private:
    std::string name_;
    int maxHealth_;
    int currentHealth_;
    int shield_;
    std::vector<std::shared_ptr<Card>> hand_;
};

// Define the operator== outside the class
inline bool operator==(const Player& lhs, const Player& rhs) {
    return lhs.name_ == rhs.name_ &&
           lhs.maxHealth_ == rhs.maxHealth_ &&
           lhs.shield_ == rhs.shield_;
}

#endif //PLAYER_H