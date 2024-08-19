package com.example.quantumquest.repository

import com.example.quantumquest.characters.Character

object CharacterRepository {
    val characters = listOf(
        Character(
            id = 1,
            name = "Evelyn the Chrono Bard",
            health = 120,
            attack = 15,
            description = "Master of time with magical melodies."
        ),
        Character(
            id = 2,
            name = "Kai the Elemental Nexus",
            health = 150,
            attack = 20,
            description = "Harnesses the power of elemental forces."
        ),
        Character(
            id = 3,
            name = "Maya the Pixel Mage",
            health = 110,
            attack = 12,
            description = "Wields the arcane energy of the digital realm."
        ),
        Character(
            id = 4,
            name = "Max the Quantum Coder",
            health = 130,
            attack = 18,
            description = "Uses quantum logic to disrupt enemies."
        ),
        Character(
            id = 5,
            name = "Aria the Temporal Warrior",
            health = 140,
            attack = 22,
            description = "Combines swordsmanship with temporal anomalies."
        )
        // Add the remaining characters here
    )
}