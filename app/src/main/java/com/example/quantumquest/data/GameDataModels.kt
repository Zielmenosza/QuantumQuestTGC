package com.example.quantumquest.data

/** Canonical data-driven definition for a playable card. */
data class CardDefinition(
    val id: Int,
    val slug: String,
    val name: String,
    val description: String,
    val cost: Int,
    val type: String,
    val element: String,
    val rarity: String,
    val artAsset: String,
    val modelAsset: String,
)

/** Canonical data-driven definition for a playable/collectable character. */
data class CharacterDefinition(
    val id: Int,
    val slug: String,
    val name: String,
    val role: String,
    val element: String,
    val description: String,
    val portraitAsset: String,
    val modelAsset: String,
)
