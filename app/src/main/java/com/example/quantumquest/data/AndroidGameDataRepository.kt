package com.example.quantumquest.data

import android.content.Context

/** Loads canonical QuantumQuest data from Android app assets. */
class AndroidGameDataRepository(private val context: Context) {
    fun loadCards(): List<CardDefinition> =
        GameDataParser.parseCards(readAsset("data/cards.json"))

    fun loadCharacters(): List<CharacterDefinition> =
        GameDataParser.parseCharacters(readAsset("data/characters.json"))

    private fun readAsset(path: String): String =
        context.assets.open(path).bufferedReader(Charsets.UTF_8).use { it.readText() }
}
