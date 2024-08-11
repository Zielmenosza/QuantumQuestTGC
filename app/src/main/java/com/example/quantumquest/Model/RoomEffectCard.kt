package com.example.quantumquest.model

open class RoomEffectCard(
    id: Int,
    name: String,
    description: String,
    val effect: String
) : Card(id, name, description) {

    fun applyEffect() {
        // Implementation of the room effect
    }
}