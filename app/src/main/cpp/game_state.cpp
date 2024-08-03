// game_state.cpp
#include "game_state.h"

// Constructor to initialize game state
GameState::GameState()
        : player1Health_(100), player2Health_(100), currentPlayer_(PlayerID::PLAYER_ONE) {
    // Initialize other game state variables as needed
}

// Get the health of a player
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

// Set the health of a player
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

// Get the current player
PlayerID GameState::getCurrentPlayer() const {
    return currentPlayer_;
}

// Set the current player
void GameState::setCurrentPlayer(PlayerID playerID) {
    currentPlayer_ = playerID;
}