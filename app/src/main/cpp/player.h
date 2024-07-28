#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory> // Include for std::shared_ptr
#include "card.h"

class Player {
public:
    Player(const std::string& name, int health, int mana) : name(name), health(health), mana(mana) {}

    const std::vector<std::shared_ptr<Card>>& getHand() const { return hand; }
    int getHealth() const { return health; }
    int getMana() const { return mana; }

    void takeDamage(int amount) { health -= amount; }
    void addMana(int amount) { mana += amount; }
    void useCard(int index); // Example of a player action

private:
    std::string name;
    int health;
    int mana;
    std::vector<std::shared_ptr<Card>> hand;
};

#endif // PLAYER_H