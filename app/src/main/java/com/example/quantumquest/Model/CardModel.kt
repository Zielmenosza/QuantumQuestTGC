package com.example.quantumquest.Model

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import com.example.quantumquest.data.AndroidGameDataRepository
import com.example.quantumquest.data.CardDefinition
import com.example.quantumquest.managers.GameManager

data class CardModel(
    val id: Int,
    val name: String,
    val description: String,
    val cost: Int,
) {
    companion object {
        fun fromDefinition(card: CardDefinition): CardModel =
            CardModel(
                id = card.id,
                name = card.name,
                description = card.description,
                cost = card.cost,
            )
    }
}

@Composable
fun QuantumQuestCardHand(cards: List<CardModel>, onEndTurn: () -> Unit = {}) {
    Surface(modifier = Modifier.fillMaxSize()) {
        Column(
            modifier = Modifier
                .fillMaxSize()
                .padding(16.dp),
            verticalArrangement = Arrangement.Top,
            horizontalAlignment = androidx.compose.ui.Alignment.CenterHorizontally,
        ) {
            Text(text = "Your Hand", style = MaterialTheme.typography.headlineMedium)
            Spacer(modifier = Modifier.height(16.dp))
            LazyColumn {
                items(cards) { card ->
                    CardItem(card = card)
                }
            }
            Spacer(modifier = Modifier.height(16.dp))
            Button(onClick = onEndTurn) {
                Text("End Turn")
            }
        }
    }
}

@Composable
fun AssetBackedCardHand() {
    val context = LocalContext.current
    val cards = remember(context) {
        AndroidGameDataRepository(context).loadCards().map(CardModel::fromDefinition)
    }
    QuantumQuestCardHand(cards = cards)
}

@Composable
fun AnotherFunctionName(gameManager: GameManager) {
    val playerHand: List<CardModel> = gameManager.getPlayerHand()
    QuantumQuestCardHand(
        cards = playerHand,
        onEndTurn = {
            if (!gameManager.playNextTurn()) {
                gameManager.startNewGame()
            }
        },
    )
}

@Composable
fun CardItem(card: CardModel) {
    Card(
        modifier = Modifier
            .fillMaxWidth()
            .padding(vertical = 4.dp),
        elevation = CardDefaults.cardElevation(defaultElevation = 8.dp),
    ) {
        Column(modifier = Modifier.padding(16.dp)) {
            Text(text = card.name, style = MaterialTheme.typography.titleMedium)
            Text(text = "Cost: ${card.cost}", style = MaterialTheme.typography.bodyMedium)
            Text(text = card.description, style = MaterialTheme.typography.bodySmall)
        }
    }
}
