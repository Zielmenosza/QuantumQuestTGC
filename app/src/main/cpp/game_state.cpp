#include "game_state.h"

// Constructor
GameState::GameState() : currentPlayerIndex(0) {
    // Initialize the game state if needed
}

// Retrieve the health of a specified player
int GameState::getPlayerHealth(int playerNumber) const {
    if (playerNumber >= 0 && playerNumber < players.size()) {
        return players[playerNumber]->getHealth();
    }
    return -1; // or throw an exception
}

// Set the health for a specified player
void GameState::setPlayerHealth(int playerNumber, int newHealth) {
    if (playerNumber >= 0 && playerNumber < players.size()) {
        players[playerNumber]->setHealth(newHealth);
    }
}

// Get the current player's number (index)
int GameState::getCurrentPlayer() const {
    return currentPlayerIndex;
}

// Set the current player by index
void GameState::setCurrentPlayer(int newPlayerIndex) {
    if (newPlayerIndex >= 0 && newPlayerIndex < players.size()) {
        currentPlayerIndex = newPlayerIndex;
    }
}

// Get a pointer to the active player
Player* GameState::getActivePlayer() const {
    return players[currentPlayerIndex].get();
}

// Advance to the next player's turn
void GameState::nextTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

// Add a new player to the game
void GameState::addPlayer(std::unique_ptr<Player> player) {
    players.push_back(std::move(player));
}

// Get all players
const std::vector<std::unique_ptr<Player>>& GameState::getPlayers() const {
    return players;
}