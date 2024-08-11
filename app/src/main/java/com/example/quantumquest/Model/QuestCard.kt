package com.example.quantumquest.model

import com.example.quantumquest.model.Card

open class QuestCard(
    val id: Int,
    val name: String,
    val description: String,
    val questObjective: String
) {
    open val reward: Int = 0  // Mark this property as open
}