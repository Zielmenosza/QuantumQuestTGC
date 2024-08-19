package com.example.quantumquest.cards

// Define the QuestCard class with basic attributes
open class QuestCard(
        val id: Int,
        val name: String,
        val description: String,
        val questObjective: String,  // This attribute seems more relevant than `difficulty`
        open val reward: Int = 0  // Add the reward property here and make it open for overriding
)