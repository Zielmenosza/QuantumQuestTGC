package com.example.quantumquest.rooms

abstract class RoomBase(
    val roomName: String,
    val roomDescription: String
) {
    // Abstract method to be overridden in subclasses
    abstract fun activateRoomEffect()

    // Common property for all rooms
    var isActive: Boolean = false

    // Common method to describe the room
    fun describeRoom() {
        println("Room Name: $roomName, Description: $roomDescription")
    }

    // Common method to activate the room
    fun enterRoom() {
        isActive = true
        describeRoom()
        activateRoomEffect()
    }

    // Common method to deactivate the room
    fun exitRoom() {
        isActive = false
        println("Leaving room: $roomName")
    }
}