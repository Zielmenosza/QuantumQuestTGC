package com.example.quantumquest.quests

import com.example.quantumquest.cards.QuestCard

class DragonQuest(
    id: Int,
    name: String,
    description: String,
    questObjective: String
) : QuestCard(id, name, description, questObjective) {

    override val reward: Int = 1000

    fun startQuest() {
        println("Quest $name has started. Objective: $questObjective")
    }

    fun completeQuest() {
        println("Quest $name completed! Reward: $reward")
    }
}