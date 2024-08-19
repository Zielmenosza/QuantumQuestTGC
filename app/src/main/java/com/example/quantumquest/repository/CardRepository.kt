package com.example.quantumquest.repository

import com.example.quantumquest.cards.Card

object CardRepository {
    val cards = listOf(
        // Existing cards
        Card(1, "Elemental Fury", "Unleashes a wave of elemental chaos.", 10),
        Card(2, "Quantum Blade of Eternity", "A blade forged from quantum anomalies, slicing through dimensions.", 20),
        Card(3, "Chrono Elixir", "A potion that can heal wounds and briefly alter time.", 5),
        Card(4, "Frost Nova Surge", "A burst of ice energy that freezes foes in their tracks.", 8),
        Card(5, "Stormcaller’s Wrath", "Calls down a thunderstorm with devastating lightning strikes.", 12),

        // New cards
        Card(6, "Inferno Vortex", "Creates a swirling vortex of fire, engulfing enemies.", 15),
        Card(7, "Temporal Rift", "Opens a rift in time, allowing for an extra turn.", 25),
        Card(8, "Lightning Strike", "A concentrated bolt of lightning that deals massive damage.", 18),
        Card(9, "Healing Aura", "Generates a soothing aura that heals allies over time.", 7),
        Card(10, "Gravity Well", "Summons a gravity well that pulls enemies towards the center.", 14),
        Card(11, "Shadow Step", "Allows the user to instantly move to a different location.", 10),
        Card(12, "Mystic Barrier", "Creates a magical shield that absorbs incoming damage.", 20),
        Card(13, "Arcane Explosion", "Unleashes a burst of arcane energy, damaging all enemies.", 22),
        Card(14, "Celestial Beacon", "Summons a beacon of light that boosts the power of nearby allies.", 16),
        Card(15, "Void Pulse", "A pulse of void energy that disrupts enemy abilities.", 19),
        Card(16, "Ice Shard Storm", "Fires a storm of sharp ice shards at enemies.", 11),
        Card(17, "Spectral Warden", "Summons a spectral guardian to protect the user.", 13),
        Card(18, "Mystic Fog", "Envelops the battlefield in a thick fog, obscuring vision.", 9),
        Card(19, "Solar Flare", "Calls down a powerful flare of solar energy to burn enemies.", 17),
        Card(20, "Echo of the Past", "Replays the last turn's actions, allowing for a strategic redo.", 24),

        // Add more cards as needed to reach the total of 72
    )
}