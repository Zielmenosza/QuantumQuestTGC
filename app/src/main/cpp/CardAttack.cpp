#include "card_type.h"
#include "card_type_specific.h"

// Constructor implementation for AttackCard
AttackCard::AttackCard(
        const std::string& name,
        const std::string& description,
        int cost,
        int attackValue
) : card_type_specific(name, description, cost), attackValue(attackValue) {
    // Additional initialization if needed
}