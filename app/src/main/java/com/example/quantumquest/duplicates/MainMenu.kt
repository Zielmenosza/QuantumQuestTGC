// MainMenu.kt
package com.example.quantumquest

import androidx.compose.foundation.layout.*
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp

@Composable
fun MainMenu(onStartGame: () -> Unit, onViewDeck: () -> Unit, onSettings: () -> Unit) {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = "Quantum Quest",
            style = MaterialTheme.typography.headlineLarge,
            modifier = Modifier.padding(bottom = 32.dp)
        )
        Button(onClick = onStartGame, modifier = Modifier.fillMaxWidth().padding(vertical = 8.dp)) {
            Text("Start Game")
        }
        Button(onClick = onViewDeck, modifier = Modifier.fillMaxWidth().padding(vertical = 8.dp)) {
            Text("View Deck")
        }
        Button(onClick = onSettings, modifier = Modifier.fillMaxWidth().padding(vertical = 8.dp)) {
            Text("Settings")
        }
    }
}

@Preview(showBackground = true)
@Composable
fun MainMenuPreview() {
    MainMenu(onStartGame = {}, onViewDeck = {}, onSettings = {})
}