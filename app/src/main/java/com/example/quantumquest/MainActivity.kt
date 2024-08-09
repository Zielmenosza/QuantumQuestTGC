package com.example.quantumquest

import android.content.Intent
import android.media.MediaPlayer
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.runtime.Composable
import androidx.compose.ui.tooling.preview.Preview

class MainActivity : ComponentActivity() {

    private lateinit var backgroundMusic: MediaPlayer

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Initialize background music
        backgroundMusic = MediaPlayer.create(this, R.raw.background_music)
        backgroundMusic.isLooping = true
        backgroundMusic.start()

        // Start the VideoActivity
        val intent = Intent(this, VideoActivity::class.java)
        startActivity(intent)

        setContent {
            QuantumQuestMainApp() // Use a unique name
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
fun QuantumQuestMainApp() {
    // Your composable content here
}

@Preview(showBackground = true)
@Composable
fun MainPreview() {
    QuantumQuestMainApp() // Adjusted name
}