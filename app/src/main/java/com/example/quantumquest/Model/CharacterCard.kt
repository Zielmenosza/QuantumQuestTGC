package com.example.quantumquest.model

import com.example.quantumquest.model.Card

open class CharacterCard(
    id: Int,
    name: String,
    description: String,
    val power: Int
) : Card(id, name, description) {

    // Example method specific to CharacterCard
    fun attack() {
        // Implement attack logic
    }
}