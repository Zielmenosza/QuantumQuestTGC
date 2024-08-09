package com.example.quantumquest

import android.content.Intent
import android.media.MediaPlayer
import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.runtime.remember
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.navigation.NavHostController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import androidx.compose.ui.tooling.preview.Preview

class MainActivity : ComponentActivity() {

    private var backgroundMusic: MediaPlayer? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        try {
            backgroundMusic = MediaPlayer.create(this, R.raw.background_music)
            if (backgroundMusic == null) {
                Log.e("MainActivity", "Failed to create MediaPlayer for background music.")
            } else {
                initializeBackgroundMusic(backgroundMusic!!)
            }
        } catch (e: Exception) {
            Log.e("MainActivity", "Exception during MediaPlayer setup: ${e.message}", e)
        }

        // Set the content for the main activity
        setContent {
            QuantumQuestApp()
        }

        // Start the VideoActivity
        val intent = Intent(this, VideoActivity::class.java)
        startActivity(intent)
    }

    private fun initializeBackgroundMusic(player: MediaPlayer) {
        try {
            player.isLooping = true
            player.start()
        } catch (e: Exception) {
            Log.e("MainActivity", "Failed to start background music: ${e.message}", e)
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        backgroundMusic?.let { player ->
            try {
                if (player.isPlaying) {
                    player.stop()
                }
                player.release()
            } catch (e: Exception) {
                Log.e("MainActivity", "Failed to release MediaPlayer: ${e.message}", e)
            }
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