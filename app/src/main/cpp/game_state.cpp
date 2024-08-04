// game_state.cpp
#include "game_state.h"

// Constructor to initialize game state
GameState::GameState(Player player) : player1_(), currentPlayer_(PlayerID::PLAYER_ONE) {
    players[PlayerID::PLAYER_ONE] = Player();
    players[PlayerID::PLAYER_TWO] = Player();
    // Initialize other game state variables as needed
}

Player & GameState::getPlayer(PlayerID id) const {
    return const_cast<Player &>(players.at(id)); // Use at() for bounds checking
}

// Get the health of a player
int GameState::getPlayerHealth(PlayerID playerID) const {
    try {
        return players.at(playerID).getHealth();
    } catch (const std::out_of_range& e) {
        return 0; // Default case for unknown players
    }
}

// Set the health of a player
void GameState::setPlayerHealth(PlayerID playerID, int newHealth) {
    try {
        players.at(playerID).setHealth(newHealth);
    } catch (const std::out_of_range& e) {
        // Handle the case where the playerID is not found
    }
}

// Get the current player
Player& GameState::getCurrentPlayer() {
    return players.at(currentPlayer_);
}

// Set the current player
void GameState::setCurrentPlayer(PlayerID playerID) {
    currentPlayer_ = playerID;
}