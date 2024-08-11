package com.example.quantumquest.managers
import com.example.quantumquest.cards.Card

class CardManager {
    private val cards: MutableList<Card> = mutableListOf()

    fun addCard(card: Card) {
        cards.add(card)
    }

    fun removeCard(card: Card) {
        cards.remove(card)
    }

    fun getCard(id: Int): Card? {
        return cards.find { it.id == id }
    }

    fun getAllCards(): List<Card> {
        return cards.toList()
    }
}