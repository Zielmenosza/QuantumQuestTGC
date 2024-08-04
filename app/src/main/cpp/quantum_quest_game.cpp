#include "quantum_quest_game.h"
#include "player.h"
#include "specific_card.h" // Include yourderived card classes
#include <iostream> // For outputting debug information
#include <stdexcept> // For exception handling
#include <random>

// Main function to run a test game
int main() {
    try {
        // Create an instance of the game
        QuantumQuestGame game;

        // Start a new game
        game.startNewGame();

        // Example of adding cards to player's hand
        std::shared_ptr<Card> card1 = std::make_shared<SpecificCard>("Sword of Power", "A powerful sword", 3);game.getCurrentPlayer().addToHand(card1);

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

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// QuantumQuestGame function implementations

// Get the current player
Player& QuantumQuestGame::getCurrentPlayer() {if (players.find(currentPlayerID) != players.end()) {
        return players[currentPlayerID];
    } else {
        throw std::out_of_range("Invalid current player ID");
    }
}

void QuantumQuestGame::initializePlayers() {
    // Example: Create two players
    players[0] = Player();
    players[1] = Player();

    // Initialize player order
    playerOrder = {0, 1}; // Example: Two players

    // Set the starting player
    currentPlayerID = playerOrder[0];
}

// Start a new game
void QuantumQuestGame::startNewGame() {
    initializePlayers(); // Call initializePlayers to set up players

    currentPlayerID = 0; // Set the starting player

    // ... (other initialization logic, like dealing cards, etc.)

    // Example: Create a deck of cards and shuffle it
    std::vector<std::shared_ptr<Card>> deck;
    deck.push_back(std::make_shared<SpecificCard>("Card 1", "Description 1", 1));
    deck.push_back(std::make_shared<SpecificCard>("Card 2", "Description 2", 2));
    // ... add more cards to the deck

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);

    // Deal cards to players (example: 5 cards each)
    for (int i = 0; i < 5; ++i) {
        for(PlayerID id : playerOrder) {
            players[id].addToHand(deck.back());
            deck.pop_back();
        }
    }
}

// End the current player's turn
void QuantumQuestGame::endPlayerTurn() {
    // Increment the current player ID (with wrap-around)
    currentPlayerID = (currentPlayerID + 1) % players.size();

    // ... (other end-of-turn logic, like drawing cards, resolving effects, etc.)
}