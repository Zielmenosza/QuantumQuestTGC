package com.example.quantumquest.characters

import com.example.quantumquest.cards.CharacterCard // Corrected import

class QuantumKnight(
    id: Int,
    name: String,
    description: String,
    val quantumPower: String // Specific property for QuantumKnight
) : CharacterCard(id, name, description) {

    fun useQuantumStrike() {
        // Implementation of the QuantumKnight's ability
    }
}