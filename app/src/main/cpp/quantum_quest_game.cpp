#include "quantum_quest_game.h"
#include "player.h"
#include "specific_card.h" // Include your derived card classes
#include <iostream> // For outputting debug information

// Main function to run a test game
int main() {
    // Create an instance of the game
    QuantumQuestGame game;

    // Start a new game
    game.startNewGame();

    // Example of adding cards to player's hand
    std::shared_ptr<Card> card1 = std::make_shared<SpecificCard>("Sword of Power");
    game.getCurrentPlayer().addToHand(card1);

    // Print player's hand to verify the card addition
    const auto& hand = game.getCurrentPlayer().getHand();
    for (const auto& card : hand) {
        std::cout << "Player has card: " << card->getName() << std::endl;
    }

    // Simulate a game loop
    for (int turn = 0; turn < 5; ++turn) { // Example: run 5 turns
        std::cout << "Turn: " << turn + 1 << std::endl;

        // Perform actions for the current player
        game.getCurrentPlayer().takeTurn(); // Implement takeTurn in Player class

        // End the current player's turn
        game.endPlayerTurn();
    }

    return 0;
}

// QuantumQuestGame function implementations

// Get the current player
Player& QuantumQuestGame::getCurrentPlayer() {
    if (currentPlayerIndex >= 0 && currentPlayerIndex < players.size()) {
        return players[currentPlayerIndex];
    } else {
        throw std::out_of_range("Invalid current player index");
    }
}

// Start a new game
void QuantumQuestGame::startNewGame() {
    // Initialize the game board
    gameBoard.initializeRooms();

    // Create players (replace with your actual player creation logic)
    players.emplace_back("Player One", 100, 10, 0, 1); // Example player data
    players.emplace_back("Player Two", 100, 10, 0, 1); // Example player data

    // Set the starting player
    currentPlayerIndex = 0;

    // ... (other initialization logic, like dealing cards, etc.)
}

// End the current player's turn
void QuantumQuestGame::endPlayerTurn() {
    // Increment the current player index (with wrap-around)
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();

    // ... (other end-of-turn logic, like drawing cards, resolving effects, etc.)
}