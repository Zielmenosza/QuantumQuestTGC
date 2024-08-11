#include "deck.h"
#include <stdexcept> // Include for std::runtime_error

Deck::Deck() {
    // Empty constructor; initialize an empty deck
}

void Deck::addCard(const Card& card) {
    cards.push_back(card);
}

Card Deck::drawCard() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot draw a card from an empty deck.");
    }
    Card drawnCard = cards.back(); // Get the last card
    cards.pop_back(); // Remove it from the deck
    return drawnCard;
}

void Deck::shuffle() {
    // Create a random number generator with a seed
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::shuffle(cards.begin(), cards.end(), rng);
}

bool Deck::isEmpty() const {
    return cards.empty();
}

int Deck::size() const {
    return static_cast<int>(cards.size());
}