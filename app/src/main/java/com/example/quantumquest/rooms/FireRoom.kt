package com.example.quantumquest.rooms

class FireRoom : RoomBase(
    roomName = "Fire Chamber",
    roomDescription = "A room engulfed in blazing flames. Beware of the heat!"
) {
    override fun activateRoomEffect() {
        if (isVulnerableToFire()) {
            applyDamage(20) // Example damage value
        }
    }

    private fun isVulnerableToFire(): Boolean {
        // Logic to determine if the room is vulnerable to fire
        // This could be more complex depending on game mechanics
        return true // Example return value
    }

    private fun applyDamage(damage: Int) {
        // Logic to apply damage to the room or its occupants
        println("Applying $damage damage due to fire.")
    }
}