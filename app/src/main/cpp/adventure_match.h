// adventure_match.h
#ifndef ADVENTURE_MATCH_H
#define ADVENTURE_MATCH_H

#include "match.h"
#include "enemy.h"

class AdventureMatch : public Match {
public:
    AdventureMatch(Player* player, std::vector<Enemy> enemies);

    void start() override;
    void update() override;
    void end() override;

private:
    std::vector<Enemy> enemies_;
    void handleAI();
    void progressStory();
};

#endif // ADVENTURE_MATCH_H