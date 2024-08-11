package com.example.quantumquest.model

// Renamed the original Room to GameRoom
open class GameRoom(
    val id: String,
    val name: String,
    val description: String
) {
    open val roomType: String = "Generic Room"
}

// Data class for simple room representations
data class Room(
    val id: String,
    val name: String,
    val description: String
)