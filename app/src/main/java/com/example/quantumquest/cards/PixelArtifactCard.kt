package com.example.quantumquest.cards

import com.example.quantumquest.model.Card

open class PixelArtifactCard(
    id: Int,
    name: String,
    description: String,
    val artifactPower: Int
) : Card(id, name, description) {

    fun activateArtifact() {
        // Implementation of the artifact's activation effect
    }
}