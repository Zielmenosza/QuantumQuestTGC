#include "pvp_match.h"
#include "input_handler.h" // Include any input handling headers
#include <iostream>        // For debugging and logging

PvPMatch::PvPMatch(Player* player1, Player* player2, bool isOnline)
        : Match(player1, player2), isOnline_(isOnline) {}

void PvPMatch::start() {
    std::cout << "Starting PvP match: "
              << (isOnline_ ? "Online" : "Local") << std::endl;
    // Initialize game state, deal initial cards, set player turns, etc.
}

void PvPMatch::update() {
    if (isOnline_) {
        handleOnlineInput();
    } else {
        handleLocalInput();
    }

    // Update game logic, process player actions, check for win conditions, etc.
}

void PvPMatch::end() {
    std::cout << "Ending PvP match." << std::endl;
    // Determine winner, display results, cleanup, etc.
}

void PvPMatch::handleLocalInput() {
    std::cout << "Handling local input." << std::endl;
    // Code to handle input for both players using the same device.
    // You can use an input handler class or directly query inputs.
}

void PvPMatch::handleOnlineInput() {
    std::cout << "Handling online input." << std::endl;
    // Code to handle online input, such as network messages, latency, etc.
}