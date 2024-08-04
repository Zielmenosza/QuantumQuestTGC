#ifndef MATCH_H
#define MATCH_H

#include <string>
#include "player.h"
#include "game_state.h"

class Match {
public:
    Match(Player* player1, Player* player2);
    virtual ~Match() {}

    virtual void start() = 0;
    virtual void update() = 0;
    virtual void end() = 0;

protected:
    Player* player1_;
    Player* player2_;
    GameState gameState_;
};

#endif // MATCH_H