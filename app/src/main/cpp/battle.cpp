#include "battle.h"

// Constructor: Initializes the battle state
BattleManager::BattleManager() : state(BattleState::START) {
    // Initialization logic here, if needed
}

// Start the battle by setting the state to IN_PROGRESS
void BattleManager::startBattle() {
    state = BattleState::IN_PROGRESS;
}

// Pause the battle by setting the state to PAUSED
void BattleManager::pauseBattle() {
    if (state == BattleState::IN_PROGRESS) {
        state = BattleState::PAUSED;
    }
}

// Resume the battle by setting the state back to IN_PROGRESS
void BattleManager::resumeBattle() {
    if (state == BattleState::PAUSED) {
        state = BattleState::IN_PROGRESS;
    }
}

// End the battle by setting the state to ENDED
void BattleManager::endBattle() {
    state = BattleState::ENDED;
}

// Return the current state of the battle
BattleState BattleManager::getState() const {
    return state;
}