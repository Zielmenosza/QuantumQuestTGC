package com.example.quantumquest.repository
import com.example.quantumquest.model.Character
object CharacterRepository {
    val characters = listOf(
        Character(id = 1, name = "Chrono Knight", health = 100, attack = 20, description = "A warrior with control over time"),
        Character(id = 2, name = "Pixel Sorceress", health = 80, attack = 25, description = "A mage who can manipulate pixels"),
    )
}
