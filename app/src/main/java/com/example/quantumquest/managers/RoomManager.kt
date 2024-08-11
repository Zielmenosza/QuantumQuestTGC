package com.example.quantumquest.managers

import com.example.quantumquest.model.RoomEffectCard  // Correct import

class RoomManager {
    private val roomeffectcardList = mutableListOf<RoomEffectCard>()

    fun addRoomEffectCard(roomeffectcard: RoomEffectCard) {
        roomeffectcardList.add(roomeffectcard)
    }

    fun getRoomEffectCard(index: Int): RoomEffectCard? {
        return if (index in 0 until roomeffectcardList.size) roomeffectcardList[index] else null
    }

    fun getAllRoomEffectCards(): List<RoomEffectCard> {
        return roomeffectcardList.toList()
    }
}