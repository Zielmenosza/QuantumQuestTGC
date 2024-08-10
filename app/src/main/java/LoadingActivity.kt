package com.example.quantumquest

import android.content.Intent
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import androidx.appcompat.app.AppCompatActivity

class LoadingActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_loading)

        // Simulate loading assets with a delay
        loadGameAssets {
            val intent = Intent(this@LoadingActivity, MainActivity::class.java)
            startActivity(intent)
            finish()
        }
    }

    private fun loadGameAssets(onComplete: () -> Unit) {
        // Simulating loading with a delay, replace with actual asset loading logic
        Handler(Looper.getMainLooper()).postDelayed({
            // Invoke the onComplete callback once loading is done
            onComplete()
        }, 3000) // 3 seconds delay
    }
}