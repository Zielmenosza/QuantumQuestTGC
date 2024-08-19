package com.example.quantumquest.characters

import com.example.quantumquest.cards.CharacterCard // Corrected import

class ChronoBard(
    id: Int,
    name: String,
    description: String,
    val timePower: String // Specific property for ChronoBard
) : CharacterCard(id, name, description) {

    fun playSongOfTime() {
        // Implementation of the ChronoBard's ability
    }
}