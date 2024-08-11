package com.example.quantumquest.characters

import com.example.quantumquest.model.CharacterCard

class QuantumKnight(
    id: Int,
    name: String,
    description: String,
    health: Int,
    attack: Int
) : CharacterCard(id, name, description, health) {
    var quantumShield: Int = 0

    fun activateQuantumShield() {
        // Implementation of quantum shield activation
    }
}