import os

def create_card_model():
    return """
package com.example.quantumquest.model

data class Card(
    val id: Int,
    val name: String,
    val description: String,
    val power: Int,
    val rarity: String,
    val cardType: String // e.g., "Spell", "Artifact", etc.
)
"""

def create_character_model():
    return """
package com.example.quantumquest.model

data class Character(
    val id: Int,
    val name: String,
    val health: Int,
    val attack: Int,
    val description: String
)
"""

def create_card_repository():
    return """
package com.example.quantumquest.repository

import com.example.quantumquest.model.Card

object CardRepository {
    val cards = listOf(
        Card(1, "Fireball", "A powerful fire spell", 10, "Common", "Spell"),
        Card(2, "Sword of Destiny", "Legendary sword with immense power", 20, "Rare", "Artifact"),
        // Add the remaining 70 cards here
    )
}
"""

def create_character_repository():
    return """
package com.example.quantumquest.repository

import com.example.quantumquest.model.Character

object CharacterRepository {
    val characters = listOf(
        Character(1, "Chrono Knight", 100, 20, "A warrior with control over time"),
        Character(2, "Pixel Sorceress", 80, 25, "A mage who can manipulate pixels"),
        // Add additional characters here
    )
}
"""

def create_game_activity():
    return """
package com.example.quantumquest.activities

import android.os.Bundle
import androidx.activity.ComponentActivity
import com.example.quantumquest.repository.CardRepository
import com.example.quantumquest.repository.CharacterRepository

class GameActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_game)

        // Access the cards and characters
        val cards = CardRepository.cards
        val characters = CharacterRepository.characters

        // Logic to start the game with the chosen cards and characters
        startNewGame(cards, characters)
    }

    private fun startNewGame(cards: List<Card>, characters: List<Character>) {
        // Initialize game with the cards and characters
    }
}
"""

def write_kotlin_files():
    project_path = '/mnt/data/QuantumQuest/app/src/main/java/com/example/quantumquest'

    files_content = {
        "model/Card.kt": create_card_model(),
        "model/Character.kt": create_character_model(),
        "repository/CardRepository.kt": create_card_repository(),
        "repository/CharacterRepository.kt": create_character_repository(),
        "activities/GameActivity.kt": create_game_activity(),
    }

    for file_name, content in files_content.items():
        file_path = os.path.join(project_path, file_name)
        os.makedirs(os.path.dirname(file_path), exist_ok=True)
        with open(file_path, 'w') as file:
            file.write(content.strip())
        print(f"Created {file_name}")

if __name__ == "__main__":
    write_kotlin_files()
    print("Added cards and characters successfully!")
