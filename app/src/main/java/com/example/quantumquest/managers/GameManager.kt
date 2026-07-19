package com.example.quantumquest.managers

import com.example.quantumquest.Model.CardModel
import com.example.quantumquest.data.CardDefinition

class GameManager(
    private val playerHandProvider: () -> List<CardDefinition> = { emptyList() },
) {

    fun getPlayerHand(): List<CardModel> {
        val dataDrivenCards = playerHandProvider()
        if (dataDrivenCards.isNotEmpty()) {
            return dataDrivenCards.map { CardModel.fromDefinition(it) }
        }

        // Fallback keeps older call sites usable until every screen is data-driven.
        return listOf(
            CardModel(1, "Inferno Crystal", "Empowers Fire creatures", 5),
            CardModel(2, "Tidal Amulet", "Boosts Water abilities", 3),
        )
    }

    fun playNextTurn(): Boolean {
        // Logic to play the next turn
        return false // Return true if the game is over
    }

    fun startNewGame() {
        // Logic to start a new game
    }
}
