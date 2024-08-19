package com.example.quantumquest.quests

import com.example.quantumquest.cards.QuestCard

class TreasureHunt(
    id: Int,
    name: String,
    description: String,
    questObjective: String
) : QuestCard(id, name, description, questObjective) {
    override val reward: Int = 500  // Correctly overrides the reward property

    fun startQuest() {
        println("Quest $name has started. Objective: $questObjective")
    }

    fun completeQuest() {
        println("Quest $name completed! Reward: $reward")
    }
}