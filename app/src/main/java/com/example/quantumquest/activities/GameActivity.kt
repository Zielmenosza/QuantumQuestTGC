
package com.example.quantumquest.activities

import android.media.MediaPlayer
import android.os.Bundle
import android.view.SurfaceHolder
import android.view.SurfaceView
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.runtime.Composable
import androidx.compose.ui.tooling.preview.Preview
import com.example.quantumquest.R

class GameActivity : ComponentActivity() {

    private lateinit var backgroundMusic: MediaPlayer
    private lateinit var surfaceHolder: SurfaceHolder

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_game)

        // Initialize background music
        backgroundMusic = MediaPlayer.create(this, R.raw.background_music)
        backgroundMusic.isLooping = true
        backgroundMusic.start()

        // Set up the SurfaceView and SurfaceHolder
        val surfaceView = findViewById<SurfaceView>(R.id.surface_view)
        surfaceHolder = surfaceView.holder

        // Set content for the game using Jetpack Compose
        setContent {
            QuantumQuestGameApp()
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
    QuantumQuestGameApp()
}
