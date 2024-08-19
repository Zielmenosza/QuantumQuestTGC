package com.example.quantumquest.managers

import com.example.quantumquest.cards.Card
import com.example.quantumquest.cards.RoomEffectCard

class RoomManager {
    private val roomEffects: MutableList<RoomEffectCard> = mutableListOf()

    fun addRoomEffect(effect: RoomEffectCard) {
        roomEffects.add(effect)
    }

    fun removeRoomEffect(effect: RoomEffectCard) {
        roomEffects.remove(effect)
    }

    fun getAllRoomEffects(): List<RoomEffectCard> {
        return roomEffects
    }
}