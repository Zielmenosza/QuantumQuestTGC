// PlayerSetup.kt
package com.example.quantumquest

import androidx.compose.foundation.layout.*
import androidx.compose.material3.Text
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Button
import androidx.compose.material3.DropdownMenu
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp

@Composable
fun PlayerSetup(onStartBattle: () -> Unit) {
    var playerName by remember { mutableStateOf("") }
    var selectedCharacter by remember { mutableStateOf("Warrior") }
    val characterOptions = listOf("Warrior", "Mage", "Rogue")

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("Player Setup", style = MaterialTheme.typography.headlineMedium, modifier = Modifier.padding(bottom = 16.dp))
        OutlinedTextField(
            value = playerName,
            onValueChange = {playerName = it },
            label = { Text("Enter your name") },
            modifier = Modifier.fillMaxWidth().padding(bottom = 16.dp)
        )
        DropdownMenuButton(
            options = characterOptions,
            selectedOption = selectedCharacter,
            onOptionSelected = { selectedCharacter = it }
        )
        Spacer(modifier = Modifier.height(16.dp))
        Button(onClick = onStartBattle, modifier = Modifier.fillMaxWidth()) {
            Text("Start Battle")
        }
    }
}

@Composable
fun DropdownMenuButton(options: List<String>, selectedOption: String, onOptionSelected: (String) -> Unit) {
    var expanded by remember { mutableStateOf(false) }
    Box {
        Button(onClick = { expanded = !expanded }) {
            Text(selectedOption)
        }
        DropdownMenu(
            expanded = expanded,
            onDismissRequest = { expanded = false }
        ) {
            options.forEach { option ->
                DropdownMenuItem(onClick = {
                    onOptionSelected(option)
                    expanded = false
                }) {
                    Text(text = option) // Added text parameter
                }
            }
        }
    }
}

fun DropdownMenuItem(onClick: () -> Unit, interactionSource: @Composable () -> Unit) {

}

@Preview(showBackground = true)
@Composable
fun PlayerSetupPreview() {
    PlayerSetup(onStartBattle = {})
}