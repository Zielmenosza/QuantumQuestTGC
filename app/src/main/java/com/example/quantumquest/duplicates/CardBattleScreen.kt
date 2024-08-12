// File might be incomplete, please check manually.
// File might be incomplete, please check manually.
// File might be incomplete, please check manually.
// File might be incomplete, please check manually.
// File might be incomplete, please check manually.
package com.example.quantumquest
import com.example.quantumquest.Card

import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import com.example.quantumquest.model.CardItem
// Ensure this file is located at src/main/java/com/example/quantumquest


@Composable
fun CardBattleScreen(gameManager: GameManager) {
    Surface(modifier = Modifier.fillMaxSize()) {
        BattleContent(gameManager)
    }
}

@Composable
fun BattleContent(gameManager: GameManager) {
    Column(
        modifier = Modifier.fillMaxSize().padding(16.dp),
        verticalArrangement = Arrangement.Top,
        horizontalAlignment = androidx.compose.ui.Alignment.CenterHorizontally
    ) {
        Text(text = "Your Hand", style = MaterialTheme.typography.headlineSmall)
        Spacer(modifier = Modifier.height(16.dp))
        PlayerHand(gameManager)
        Spacer(modifier = Modifier.height(16.dp))
        EndTurnButton(gameManager)
    }
}

@Composable
fun PlayerHand(gameManager: GameManager) {
    val playerHand = gameManager.getPlayerHand()
    playerHand.forEach { card ->
        CardItem(card = card)
    }
}

@Composable
fun EndTurnButton(gameManager: GameManager) {
    Button(onClick = {
        if (!gameManager.playNextTurn()) {
            gameManager.startNewGame()
        }
    }) {
        Text("End Turn")
    }
}