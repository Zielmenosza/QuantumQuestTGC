package com.example.quantumquest.managers

import com.example.quantumquest.model.QuestCard  // Import the QuestCard class

class QuestManager {
    private val questcardList = mutableListOf<QuestCard>()

    fun addQuestCard(questcard: QuestCard) {
        questcardList.add(questcard)
    }

    fun getQuestCard(index: Int): QuestCard? {
        return if (index in 0 until questcardList.size) questcardList[index] else null
    }

    fun getAllQuestCards(): List<QuestCard> {
        return questcardList.toList()
    }
}