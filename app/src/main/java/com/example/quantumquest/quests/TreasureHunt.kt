package com.example.quantumquest.quests

import com.example.quantumquest.model.QuestCard  // Import the correct base class

class TreasureHunt(
    id: Int,
    name: String,
    description: String,
    questObjective: String
) : QuestCard(id, name, description, questObjective) {
    override val reward: Int = 500  // Correctly overrides the reward property
}