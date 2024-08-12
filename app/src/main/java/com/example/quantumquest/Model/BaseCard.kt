package com.example.quantumquest.model

open class BaseCard(
    val id: Int,
    val name: String,
    val description: String
) {
    // This class can be extended by other specific card types
}