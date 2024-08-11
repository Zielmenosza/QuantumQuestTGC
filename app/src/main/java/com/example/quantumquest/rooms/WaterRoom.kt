package com.example.quantumquest.rooms

import com.example.quantumquest.model.GameRoom  // Import the correct class

// WaterRoom extending the GameRoom class
class WaterRoom(
    id: String,
    name: String,
    description: String
) : GameRoom(id, name, description) {

    // Override the roomType property
    override val roomType: String = "Water"

    val waterEffect: Int = 5

    fun applyWaterEffect() {
        // Logic to apply water effect to characters or cards in the room
    }
}