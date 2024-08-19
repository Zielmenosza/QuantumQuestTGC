package com.example.quantumquest.cards

class ElementalSpellCard(
    id: Int,
    name: String,
    description: String,
    val element: String, // Specific property for ElementalSpellCard
    cost: Int // Include the cost parameter
) : Card(id, name, description, cost) {

    fun castSpell() {
        // Implementation for casting the elemental spell
    }
}