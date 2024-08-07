// GameInterface.kt
package com.example.quantumquest

import androidx.compose.runtime.Composable
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController

@Composable
fun GameInterface() {
    val navController = rememberNavController()
    NavHost(navController = navController, startDestination = "mainMenu") {
        composable("mainMenu") {
            MainMenu(
                onStartGame = { navController.navigate("playerSetup") },
                onViewDeck = { /* Navigate to deck view */ },
                onSettings = { /* Navigate to settings */ }
            )
        }
        composable("playerSetup") {
            PlayerSetup(onStartBattle = { /* Start battle logic */ })
        }
    }
}