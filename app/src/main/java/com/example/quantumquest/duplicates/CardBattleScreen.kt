package com.example.quantumquest.duplicates

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import com.example.quantumquest.Model.CardModel
import com.example.quantumquest.managers.GameManager

@Composable
fun CardBattleScreen(gameManager: GameManager) {
    Surface(modifier = Modifier.fillMaxSize()) {
        BattleContent(gameManager)
    }
}

@Composable
fun BattleContent(gameManager: GameManager) {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
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
    val playerHand: List<CardModel> = gameManager.getPlayerHand() // Ensure this returns List<CardModel>
    LazyColumn {
        items(playerHand) { card -> // Iterate over the playerHand list
            CardItem(card = card)
        }
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

@Composable
fun CardItem(card: CardModel) {
    Card(
        modifier = Modifier
            .fillMaxWidth()
            .padding(vertical = 4.dp),
        elevation = CardDefaults.cardElevation(defaultElevation = 8.dp)
    ) {
        Column(modifier = Modifier.padding(16.dp)) {
            Text(text = card.name, style = MaterialTheme.typography.titleMedium)
            Text(text = "Cost: ${card.cost}", style = MaterialTheme.typography.bodyMedium)
            Text(text = card.description, style = MaterialTheme.typography.bodySmall)
        }
    }
}