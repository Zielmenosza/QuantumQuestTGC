package com.example.quantumquest.managers

import com.example.quantumquest.cards.CharacterCard

class CharacterManager {

    private val characterList = mutableListOf<CharacterCard>()

    fun addCharacter(character: CharacterCard) {
        characterList.add(character)
    }

    fun getCharacter(index: Int): CharacterCard? {
        return characterList.getOrNull(index)
    }
}