package com.example.quantumquest

import GameInterface
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.runtime.Composable
import android.util.Log
import androidx.compose.material3.MaterialTheme

class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            QuantumQuestTheme {
                GameInterface()
            }
        }
    }

    /**
     * A native method that is implemented by the 'quantumquest' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    @Composable
    fun QuantumQuestTheme(content: @Composable () -> Unit) {
        MaterialTheme { // Use MaterialTheme or define your custom theme
            content()
        }
    }

    companion object {
        // Used to load the 'quantumquest' library on application startup.
        init {
            try {
                System.loadLibrary("quantumquest")
                Log.d("LibraryLoad", "Library loaded successfully")
            } catch (e: UnsatisfiedLinkError) {
                Log.e("LibraryLoad", "Failed to load library", e)
                // Handle the error gracefully, e.g., display an error message
            }
        }
    }
}