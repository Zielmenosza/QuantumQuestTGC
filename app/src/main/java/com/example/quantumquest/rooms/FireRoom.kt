package com.example.quantumquest.rooms
import com.example.quantumquest.FireRoom


import com.example.quantumquest.model.GameRoom  // Updated import to match the renamed class

// Now, FireRoom can extend GameRoom
class FireRoom 
    id: String,
    name: String,
    description: String
) : GameRoom(id, name, description) {

    // Override the roomType property
    override val roomType: String = "Fire"

    val fireDamage: Int = 10

    fun applyFireDamage() {
        // Logic to apply fire damage to characters or cards in the room
    }
}