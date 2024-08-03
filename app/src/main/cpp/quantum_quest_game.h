#ifndef QUANTUM_QUEST_GAME_H
#define QUANTUM_QUEST_GAME_H

#include "Player.h"
#include <map>
#include <vector>
#include <memory> // For shared_ptr

using PlayerID = int; // Define PlayerID as an alias for int, or use a more specific type if needed

class QuantumQuestGame {
public:
    // Constructor to initialize the game
    QuantumQuestGame();

    // Starts a new game by setting up players and the game board
    void startNewGame();

    // Gets the current player based on currentPlayerID
    Player& getCurrentPlayer();

    // Ends the current player's turn and moves to the next player
    void endPlayerTurn();

private:
    std::map<PlayerID, Player> players; // Map to hold players associated with PlayerID
    PlayerID currentPlayerID; // ID of the current player
    std::vector<PlayerID> playerOrder; // Order of player IDs for turn rotation

    void initializePlayers(); // Initialize players with PlayerID and add to the game
};

#endif // QUANTUM_QUEST_GAME_H