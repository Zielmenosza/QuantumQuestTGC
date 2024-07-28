#include "quantum_quest_game.h"
#include "player.h"
#include "specific_card.h" // Include your derived card classes

int main() {
    Player player;
    // Example of adding cards to player's hand
    std::shared_ptr<Card> card1 = std::make_shared<SpecificCard>(); // Replace with actual derived class
    player.getHand().push_back(card1);

    return 0;
}


// QuantumQuestGame function implementations
Player QuantumQuestGame::getCurrentPlayer() const {
    if (currentPlayerIndex >= 0 && currentPlayerIndex < players.size()) {
        return players[currentPlayerIndex];
    } else
        // Handle the error case more explicitly
        // You could throw an exception, log an error, or return a placeholder Player
        // For now, let's return a default Player object
        return {};

}

void QuantumQuestGame::startNewGame() {
    // Initialize the game board
    gameBoard.initializeRooms();

    // Create players (replace with your actual player creation logic)
    players.emplace_back(/* player data */);
    players.emplace_back(/* player data */);
    // ... add more players as needed

    // Set the starting player
    currentPlayerIndex = 0;

    // ... (other initialization logic, like dealing cards, etc.)
}

void QuantumQuestGame::endPlayerTurn() {
    // Increment the current player index (with wrap-around)
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();

    // ... (other end-of-turn logic, like drawing cards, resolving effects, etc.)
}