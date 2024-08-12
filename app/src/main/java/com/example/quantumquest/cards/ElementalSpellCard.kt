package com.example.quantumquest.cards
import com.example.quantumquest.Card


import com.example.quantumquest.model.Card

open class ElementalSpellCard 
    id: Int,
    name: String,
    description: String,
    val element: String
) : Card(id, name, description) {

    fun castSpell() {
        // Implementation of the spell casting
    }
}