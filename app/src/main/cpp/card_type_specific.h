#ifndef CARD_TYPE_SPECIFIC_H
#define CARD_TYPE_SPECIFIC_H

#include <string>

// Enumeration representing different card types
enum class CardType {
    Attack,
    Defense,
    // ... other card types
};

// Abstract base class for specific card types
class card_type_specific {
public:
    // Constructor initializing the common attributes for all card types
    card_type_specific(const std::string& name, const std::string& description, int cost, CardType type);

    // Getters for the card attributes
    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }
    int getCost() const { return cost; }
    CardType getType() const { return type; }

    // Pure virtual function to be implemented by derived classes
    virtual void Play(class GameState& gameState) = 0;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~card_type_specific() = default;

private:
    std::string name;
    std::string description;
    int cost;
    CardType type;
};

#endif // CARD_TYPE_SPECIFIC_H