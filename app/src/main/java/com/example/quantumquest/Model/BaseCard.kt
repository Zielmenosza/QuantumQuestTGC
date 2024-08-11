package com.example.quantumquest.model

open class BaseCard(
    val card: Card // Composition: BaseCard holds a reference to a Card object
) {
    val id: Int
        get() = card.id

    val name: String
        get() = card.name

    val description: String
        get() = card.description

    // You can add additional functionality specific to BaseCard here
}