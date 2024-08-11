package com.example.quantumquest.characters

import com.example.quantumquest.model.CharacterCard

class PixelSorceress(
    id: Int,
    name: String,
    description: String,
    health: Int,
    attack: Int
) : CharacterCard(id, name, description, health) {
    var pixelMagicPower: Int = 0

    fun castPixelMagic() {
        // Implementation of pixel magic
    }
}