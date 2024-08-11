package com.example.quantumquest.characters

import com.example.quantumquest.model.CharacterCard

open class ChronoBard(
    id: Int,            // Ensure this is an Int, not a String
    name: String,
    description: String,
    health: Int,        // Ensure this matches the expected type
    attack: Int         // Ensure this matches the expected type
) : CharacterCard(id, name, description, health) {

    var timeManipulationPower: Int = 0

    fun manipulateTime() {
        // Implementation of time manipulation
    }
}