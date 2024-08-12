package com.example.quantumquest.managers
import com.example.quantumquest.Card
import com.example.quantumquest.CharacterCard
import com.example.quantumquest.CharacterManager


import com.example.quantumquest.model.CharacterCard

class CharacterManager {
    private val characterCardList = mutableListOf<CharacterCard>()

    fun addCharacterCard(characterCard: CharacterCard) {
        characterCardList.add(characterCard)
    }

    fun getCharacterCard(index: Int): CharacterCard? {
        return if (index in 0 until characterCardList.size) characterCardList[index] else null
    }

    fun getAllCharacterCards(): List<CharacterCard> {
        return characterCardList.toList()
    }
}