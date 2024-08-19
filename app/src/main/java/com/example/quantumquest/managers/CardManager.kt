package com.example.quantumquest.managers

import com.example.quantumquest.cards.Card

class CardManager {
    private val cardList: MutableList<Card> = mutableListOf()

    fun addCard(card: Card) {
        cardList.add(card)
    }

    fun getCards(): List<Card> {
        return cardList
    }

    fun findCardById(id: Int): Card? {
        return cardList.find { it.id == id }
    }
}