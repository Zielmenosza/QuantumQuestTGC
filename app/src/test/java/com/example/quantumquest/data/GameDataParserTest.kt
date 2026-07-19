package com.example.quantumquest.data

import org.junit.Assert.assertEquals
import org.junit.Assert.assertTrue
import org.junit.Test
import java.io.File

class GameDataParserTest {
    @Test
    fun parsesCardsFromCanonicalAssetFile() {
        val cardsJson = File("src/main/assets/data/cards.json").readText()

        val cards = GameDataParser.parseCards(cardsJson)

        assertTrue(cards.size >= 6)
        val infernoCrystal = cards.single { it.slug == "inferno_crystal" }
        assertEquals("Inferno Crystal", infernoCrystal.name)
        assertEquals(5, infernoCrystal.cost)
        assertEquals("fire", infernoCrystal.element)
        assertEquals("inferno_crystal", infernoCrystal.modelAsset)
    }

    @Test
    fun parsesCharactersFromCanonicalAssetFile() {
        val charactersJson = File("src/main/assets/data/characters.json").readText()

        val characters = GameDataParser.parseCharacters(charactersJson)

        assertTrue(characters.size >= 4)
        val thorne = characters.single { it.slug == "thorne_quantum_knight" }
        assertEquals("Thorne Quantum Knight", thorne.name)
        assertEquals("guardian", thorne.role)
        assertEquals("thorne_quantum_knight", thorne.modelAsset)
    }
}
