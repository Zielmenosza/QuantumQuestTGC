package com.example.quantumquest.cards

class PixelArtifactCard(
    id: Int,
    name: String,
    description: String,
    cost: Int // Include the cost parameter
) : Card(id, name, description, cost) {

    fun activateArtifact() {
        // Implementation for activating the pixel artifact
    }
}