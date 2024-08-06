package com.example.quantumquest

import androidx.compose.foundation.layout.*
import androidx.compose.material.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp

@Composable
fun GameInterface() {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp)
    ) {
        Text(text = "Welcome to QuantumQuest", color = Color.Black)
        Spacer(modifier = Modifier.height(8.dp))
        Button(onClick = { /* Handle click */ }) {
            Text("Start Game")
        }
    }
}

@Preview(showBackground = true)
@Composable
fun GameInterfacePreview() {
    GameInterface()
}