package com.example.quantumquest.activities

import android.media.MediaPlayer
import android.os.Bundle
import androidx.activity.compose.setContent
import androidx.appcompat.app.AppCompatActivity
import androidx.compose.material3.MaterialTheme
import com.example.quantumquest.Model.AssetBackedCardHand
import com.example.quantumquest.R

class GameActivity : AppCompatActivity() {

    private var backgroundMusic: MediaPlayer? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        backgroundMusic = MediaPlayer.create(this, R.raw.background_music)
        backgroundMusic?.isLooping = true
        backgroundMusic?.start()

        setContent {
            MaterialTheme {
                AssetBackedCardHand()
            }
        }
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
