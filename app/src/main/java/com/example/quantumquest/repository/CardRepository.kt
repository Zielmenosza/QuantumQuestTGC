package com.example.quantumquest.repository

import com.example.quantumquest.cards.Card

object CardRepository {
    val cards = listOf(
        Card(1, "Fireball", "A powerful fire spell", 10, "Common", "Spell"),
        Card(2, "Sword of Destiny", "Legendary sword with immense power", 20, "Rare", "Artifact"),
        Card(3, "Healing Potion", "Restores health", 5, "Common", "Item"),
        Card(4, "Ice Lance", "A chilling ice attack", 8, "Uncommon", "Spell"),
        Card(5, "Thunder Strike", "A lightning strike", 12, "Rare", "Spell"),
        // Add the remaining 67 cards here
    )
}