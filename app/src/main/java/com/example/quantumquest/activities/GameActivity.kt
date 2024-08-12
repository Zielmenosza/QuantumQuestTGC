package com.example.quantumquest.activities

import android.media.MediaPlayer
import android.os.Bundle
import android.view.SurfaceHolder
import android.view.SurfaceView
import androidx.activity.ComponentActivity
import com.example.quantumquest.R

class GameActivity : ComponentActivity() {

    private var backgroundMusic: MediaPlayer? = null
    private lateinit var surfaceHolder: SurfaceHolder

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_game)

        // Initialize background music
        backgroundMusic = MediaPlayer.create(this, R.raw.background_music)
        if (backgroundMusic == null) {
            // Handle error, log it, or show a message to the user
            return
        }
        backgroundMusic?.isLooping = true
        backgroundMusic?.start()

        // Set up the SurfaceView and SurfaceHolder
        val surfaceView = findViewById<SurfaceView>(R.id.surface_view)
        surfaceHolder = surfaceView.holder
    }

    override fun onDestroy() {
        super.onDestroy()
        backgroundMusic?.let {
            if (it.isPlaying) {
                it.stop()
            }
            it.release()
        }
    }
}