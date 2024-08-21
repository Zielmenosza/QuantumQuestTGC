
#include "GameStateManager.h"

GameState GameStateManager::getCurrentState() const {
    return m_currentState;
}

void GameStateManager::setCurrentState(GameState state) {
    m_currentState = state;
}

