// CardView.kt
package com.example.quantumquest

import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp

@Composable
fun CardView(card: CardModel) {
    Card(
        modifier = Modifier
            .fillMaxWidth()
            .padding(8.dp)
    ) {
        Column(modifier = Modifier.padding(16.dp)) {
            Text(text = card.name, style = MaterialTheme.typography.titleMedium)
            Text(text = "Cost: ${card.cost}", style = MaterialTheme.typography.bodyMedium)
            Text(text = card.description, style = MaterialTheme.typography.bodySmall)
        }
    }
}

data class CardModel(
    val name: String,
    val cost: Int,
    val description: String
)