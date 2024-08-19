package com.example.quantumquest.rooms

// Define any imports required
import com.example.quantumquest.cards.Card

class WaterRoom(
    val id: Int,
    val name: String,
    val description: String,
    val effect: String // Specific property for the room
) {
    // Initialize room-specific properties here

    fun activateEffect() {
        // Logic for room effect activation
    }

    fun displayRoomInfo() {
        println("Room Name: $name, Description: $description, Effect: $effect")
    }
}