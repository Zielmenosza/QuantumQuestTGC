// game_state.cpp
#include "game_state.h"

GameState::GameState()
        : player1Health_(100), player2Health_(100), currentPlayer_(PlayerID::PLAYER_ONE) {
    // Initialize other game state variables as needed
}

int GameState::getPlayerHealth(PlayerID playerID) const {
    switch (playerID) {
        case PlayerID::PLAYER_ONE:
            return player1Health_;
        case PlayerID::PLAYER_TWO:
            return player2Health_;
            // Add more cases if needed
        default:
            return 0; // Default case for unknown players
    }
}

void GameState::setPlayerHealth(PlayerID playerID, int newHealth) {
    switch (playerID) {
        case PlayerID::PLAYER_ONE:
            player1Health_ = newHealth;
            break;
        case PlayerID::PLAYER_TWO:
            player2Health_ = newHealth;
            break;
            // Add more cases if needed
        default:
            break;
    }
}

PlayerID GameState::getCurrentPlayer() const {
    return currentPlayer_;
}

void GameState::setCurrentPlayer(PlayerID playerID) {
    currentPlayer_ = playerID;
}