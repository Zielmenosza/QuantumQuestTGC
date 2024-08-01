#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include "card.h"

class Player {
public:
    Player(const std::string& name) : name(name), health(100) {}

    const std::vector<std::shared_ptr<Card>>& getHand() const {
        return hand_;
    }

    void addToHand(const std::shared_ptr<Card>& card);

    void reduceIncomingDamage(int damage);

private:
    std::string name;
    std::vector<std::shared_ptr<Card>> hand_;
    int health;
};

#endif // PLAYER_H