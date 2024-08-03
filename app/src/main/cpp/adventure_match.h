#ifndef ADVENTURE_MATCH_H
#define ADVENTURE_MATCH_H

#include "match.h"
#include "enemy.h"
#include <vector>

class AdventureMatch : public Match {
public:
    AdventureMatch(Player *player1, Player *player2, const std::vector<Enemy>& enemies);

    void start() override;
    void update() override;
    void end() override;

private:
    std::vector<Enemy> enemies_;
    void handleAI();
    void progressStory();
};

#endif // ADVENTURE_MATCH_H