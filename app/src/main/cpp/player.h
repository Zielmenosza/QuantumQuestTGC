#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include "card.h"

class Player {
public:
    // ... other members ...

    const std::vector<std::shared_ptr<Card>>& getHand() const {
        return hand_;
    }

    void addToHand(const std::shared_ptr<Card>& card); // Add card to hand (example)

    void reduceIncomingDamage(int damage);

private:
    std::vector<std::shared_ptr<Card>> hand_;
    // ... other members ...
};

#endif // PLAYER_H