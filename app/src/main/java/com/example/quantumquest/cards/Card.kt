package com.example.quantumquest.cards

open class Card(
    val id: Int,
    val name: String,
    val description: String,
    val cost: Int // Assuming cost is a common property
) {
    fun displayCardInfo() {
        println("Card Name: $name, Description: $description, Cost: $cost")
    }
}