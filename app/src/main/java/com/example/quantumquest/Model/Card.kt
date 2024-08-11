package com.example.quantumquest.model

open class Card(
    val id: Int,
    val name: String,
    val description: String
) {
    open fun play() {
        // Define play action
    }
}