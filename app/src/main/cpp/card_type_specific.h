#ifndef CARD_TYPE_SPECIFIC_H
#define CARD_TYPE_SPECIFIC_H

#include <string>

// Enum to define different types of cards
enum class CardType {
    Attack,
    Defense,
    // Add more card types as needed
};

// Base class for specific card types
class card_type_specific {
public:
    // Constructor to initialize card properties
    card_type_specific(std::string name, std::string description, int cost, CardType type)
            : name(std::move(name)), description(std::move(description)), cost(cost), type(type) {}

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~card_type_specific() = default;

    virtual // Getters for card properties
    [[nodiscard]] const std::string& getName() const { return name; }

    virtual [[nodiscard]] const std::string& getDescription() const { return description; }

    virtual [[nodiscard]] int getCost() const { return cost; }
    [[nodiscard]] CardType getType() const { return type; }

    // Pure virtual method for card action
    virtual void Play(class GameState& gameState) = 0;

protected:
    std::string name;
    std::string description;
    int cost;
    CardType type;
};

#endif // CARD_TYPE_SPECIFIC_H