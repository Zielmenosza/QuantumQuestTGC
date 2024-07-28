#ifndef CARD_H
#define CARD_H

#include <string>
#include "game_state.h"
#include "card_type.h"

class Card {
public:
    Card(const std::string& name, const std::string& description, int cost, CardType type)
            : name(name), description(description), cost(cost), type(type) {}

    virtual ~Card() = default;
    virtual void Play(GameState& gameState) = 0;

    [[nodiscard]] std::string getName() const { return name; }
    [[nodiscard]] std::string getDescription() const { return description; }
    [[nodiscard]] int getCost() const { return cost; }
    [[nodiscard]] CardType getType() const { return type; }

private:
    std::string name;
    std::string description;
    int cost;
    CardType type; // Example of an additional attribute
};

enum class CardType {
    Spell,
    Unit,
    Item
};

#endif  // CARD_H