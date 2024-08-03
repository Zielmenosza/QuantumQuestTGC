#ifndef BATTLE_H
#define BATTLE_H

#include "Combatant.h"
#include <vector>

enum class BattleState {
    START,
    IN_PROGRESS,
    PAUSED,
    ENDED
};

class BattleManager {
public:
    BattleManager();

    void startBattle();
    void pauseBattle();
    void resumeBattle();
    void endBattle();

    // Changed to non-static to access the current state of the instance
    BattleState getState() const;

private:
    std::vector<Combatant*> participants;
    BattleState state;
};

#endif // BATTLE_H