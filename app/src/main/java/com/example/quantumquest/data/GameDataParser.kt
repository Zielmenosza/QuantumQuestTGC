package com.example.quantumquest.data

import org.json.JSONArray
import org.json.JSONObject

/** Parses QuantumQuest JSON data files from app assets or tests. */
object GameDataParser {
    fun parseCards(json: String): List<CardDefinition> {
        val array = JSONArray(json)
        return List(array.length()) { index ->
            val item = array.getJSONObject(index)
            CardDefinition(
                id = item.getInt("id"),
                slug = item.getRequiredString("slug"),
                name = item.getRequiredString("name"),
                description = item.getRequiredString("description"),
                cost = item.getInt("cost"),
                type = item.getRequiredString("type"),
                element = item.getRequiredString("element"),
                rarity = item.getRequiredString("rarity"),
                artAsset = item.getRequiredString("artAsset"),
                modelAsset = item.getRequiredString("modelAsset"),
            )
        }
    }

    fun parseCharacters(json: String): List<CharacterDefinition> {
        val array = JSONArray(json)
        return List(array.length()) { index ->
            val item = array.getJSONObject(index)
            CharacterDefinition(
                id = item.getInt("id"),
                slug = item.getRequiredString("slug"),
                name = item.getRequiredString("name"),
                role = item.getRequiredString("role"),
                element = item.getRequiredString("element"),
                description = item.getRequiredString("description"),
                portraitAsset = item.getRequiredString("portraitAsset"),
                modelAsset = item.getRequiredString("modelAsset"),
            )
        }
    }

    private fun JSONObject.getRequiredString(name: String): String {
        val value = getString(name).trim()
        require(value.isNotEmpty()) { "Field '$name' must not be blank" }
        return value
    }
}
