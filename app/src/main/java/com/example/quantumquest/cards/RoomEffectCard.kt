package com.example.quantumquest.cards

import com.example.quantumquest.cards.Card  // Ensure this is the correct import

class RoomEffectCard(
    id: Int,
    name: String,
    description: String,
    cost: Int,
    val effect: String
) : Card(id, name, description, cost) {

    fun applyEffect() {
        println("Applying effect: $effect")
    }
}