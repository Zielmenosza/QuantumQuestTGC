#ifndef CARD_TYPE_SPECIFIC_H
#define CARD_TYPE_SPECIFIC_H

#include <string>

enum class CardType {
    Attack,
    Defense,
    // ... other card types
};

class card_type_specific {
public:
    card_type_specific(const std::string& name, const std::string& description,int cost, CardType type);

    // Add getters for name, description, cost, and type
    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }
    int getCost() const { return cost; }
    CardType getType() const { return type; }

    virtual void Play(class GameState& gameState) = 0; // Pure virtual function

private:
    std::string name;
    std::string description;
    int cost;
    CardType type;
};

#endif // CARD_TYPE_SPECIFIC_H