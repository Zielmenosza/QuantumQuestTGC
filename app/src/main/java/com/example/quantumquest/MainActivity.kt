package com.example.quantumquest

import android.content.Intent
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.runtime.Composable
import androidx.compose.ui.tooling.preview.Preview

class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Start the VideoActivity first
        val intent = Intent(this, VideoActivity::class.java)
        startActivity(intent)
        finish() // Close MainActivity to prevent it from appearing behind VideoActivity
    }
}

@Composable
fun QuantumQuestApp() {
    // Your composable functions here
}

@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    QuantumQuestApp()
}