#include "adventure_match.h"
#include <iostream>

// Constructor for AdventureMatch
AdventureMatch::AdventureMatch(Player& player, Enemy& enemy)
        : player(player), enemy(enemy) {
    initializeDeck();
}

// Start the match
void AdventureMatch::start() {
    std::cout << "Starting match between " << player.getName() << " and " << enemy.getType() << std::endl;

    // Example match logic
    for (auto& card : deck) {
        std::cout << "Activating card: " << card.getName() << std::endl;
        card.activateEffect();
        std::cout << "Card power: " << card.getPower() << std::endl;
    }
}

// Initialize the deck with some cards
void AdventureMatch::initializeDeck() {
    deck.emplace_back("Fireball", "Throws a ball of fire", 10, 5); // Added description
    deck.emplace_back("Ice Blast", "Unleashes a blast of ice", 8, 4); // Added description
}