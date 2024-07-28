#ifndef CARD_DEFENSE_H
#define CARD_DEFENSE_H

#include "card.h"

class Card_Defense : public Card {
public:
    Card_Defense(const std::string& name, const std::string& description, int cost, int defenseValue)
            : Card(name, cost), defenseValue(defenseValue) {}

    void Play(GameState& gameState) override {
        // Implement defense logic here, e.g., reduce incoming damage
        gameState.activePlayer.reduceIncomingDamage(defenseValue);
    }

private:
    int defenseValue;
};

#endif // CARD_DEFENSE_H

#ifndef CARD_EFFECT_H
#define CARD_EFFECT_H

#include <string>

class Card_Effect {
public:
    Card_Effect(const std::string& name, const std::string& description, int cost)
            : name(name), description(description), cost(cost) {}

    virtual ~Card_Effect() = default; // Virtual destructor

    void playEffect(Player& targetPlayer) {
        // Implement the specific effect of the card here (e.g., modify targetPlayer's attributes)
    }

protected:
    std::string name;
    std::string description;
    int cost;
};

#endif // CARD_EFFECT_H

#include "card_effect.h"

Card_Effect::Card_Effect(const std::string& name, const std::string& description, int cost)
        : name(name), description(description), cost(cost) {}