package com.example.quantumquest

import android.content.Intent
import android.media.MediaPlayer
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.navigation.NavHostController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import androidx.compose.ui.tooling.preview.Preview

class MainActivity : ComponentActivity() {
    private lateinit var backgroundMusic: MediaPlayer

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Initialize and start the background music
        backgroundMusic = MediaPlayer.create(this, R.raw.background_music)
        backgroundMusic.isLooping = true // Loop the music
        backgroundMusic.start()

        // Launch VideoActivity to play the intro video first
        val intent = Intent(this, VideoActivity::class.java)
        startActivity(intent)

        // Set the content after the video activity finishes
        setContent {
            QuantumQuestApp()
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        // Release the MediaPlayer resources
        if (::backgroundMusic.isInitialized) {
            backgroundMusic.stop()
            backgroundMusic.release()
        }
    }
}

@Composable
fun QuantumQuestApp() {
    val navController = rememberNavController()
    val gameManager = remember { GameManager() }

    NavHost(
        navController = navController,
        startDestination = "mainMenu"
    ) {
        composable("mainMenu") { MainMenuScreen(navController) }
        composable("gameScreen") { CardBattleScreen(gameManager) }
    }
}

@Composable
fun MainMenuScreen(navController: NavHostController) {
    Surface(modifier = Modifier.fillMaxSize()) {
        Column(
            modifier = Modifier
                .fillMaxSize()
                .padding(16.dp),
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = androidx.compose.ui.Alignment.CenterHorizontally
        ) {
            Text(text = "Quantum Quest", style = MaterialTheme.typography.headlineMedium)
            Spacer(modifier = Modifier.height(32.dp))
            Button(onClick = { navController.navigate("gameScreen") }) {
                Text("Start Game")
            }
            Spacer(modifier = Modifier.height(16.dp))
            Button(onClick = { /* Navigate to Card Collection Screen */ }) {
                Text("View Card Collection")
            }
            Spacer(modifier = Modifier.height(16.dp))
            Button(onClick = { /* Navigate to Settings Screen */ }) {
                Text("Settings")
            }
        }
    }
}

@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    QuantumQuestApp()
}