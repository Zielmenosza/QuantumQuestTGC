#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"  // Ensure you include the base class header

class Player : public Character {
public:
    Player(const std::string& name, int health, int defense);

    int getHealth() const override;  // Correctly marked as override
    void heal(int amount) override;  // Correctly marked as override

private:
    std::string name; // Player's name
    // Remove the redundant health member variable here
};

#endif // PLAYER_H