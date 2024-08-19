package com.example.quantumquest.managers

import com.example.quantumquest.cards.QuestCard

class QuestManager {
    private val questDeck: MutableList<QuestCard> = mutableListOf()

    fun addQuestCard(questCard: QuestCard) {
        questDeck.add(questCard)
    }

    fun removeQuestCard(questCard: QuestCard) {
        questDeck.remove(questCard)
    }

    fun getAllQuestCards(): List<QuestCard> {
        return questDeck
    }
}