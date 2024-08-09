package com.example.quantumquest

import android.media.MediaPlayer
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.runtime.Composable
import androidx.compose.ui.tooling.preview.Preview

class GameActivity : ComponentActivity() {

    private lateinit var backgroundMusic: MediaPlayer

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Initialize background music
        backgroundMusic = MediaPlayer.create(this, R.raw.background_music)
        backgroundMusic.isLooping = true
        backgroundMusic.start()

        // Set content for the game
        setContent {
            QuantumQuestGameApp() // Use a different name to avoid conflict
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        if (::backgroundMusic.isInitialized) {
            backgroundMusic.stop()
            backgroundMusic.release()
        }
    }
}

@Composable
fun QuantumQuestGameApp() {
    // Your composable content here
}

@Preview(showBackground = true)
@Composable
fun GamePreview() {
    QuantumQuestGameApp() // Adjusted name
}