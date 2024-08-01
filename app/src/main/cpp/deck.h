//
// Created by Ziel on 2024/07/16.
//

#ifndef QUANTUM_QUEST_DECK_H
#define QUANTUM_QUEST_DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "card.h" // Assuming you have a Card class

class Deck {
public:
    Deck(); // Constructor to initialize an empty deck

    // Method to add a card to the deck
    void addCard(const Card& card);

    // Method to draw a card from the deck
    Card drawCard();

    // Method to shuffle the deck
    void shuffle();

    // Method to check if the deck is empty
    bool isEmpty() const;

    // Method to get the current size of the deck
    int size() const;

private:
    std::vector<Card> cards; // Vector to hold the cards in the deck
};

#endif //QUANTUM_QUEST_DECK_H