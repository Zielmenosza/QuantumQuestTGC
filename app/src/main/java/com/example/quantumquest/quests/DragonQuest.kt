package com.example.quantumquest.quests
import com.example.quantumquest.Card
import com.example.quantumquest.QuestCard
import com.example.quantumquest.DragonQuest


import com.example.quantumquest.model.QuestCard

class DragonQuest 
    id: Int,
    name: String,
    description: String,
    questObjective: String
) : QuestCard(id, name, description, questObjective) {
    override val reward: Int = 1000
}