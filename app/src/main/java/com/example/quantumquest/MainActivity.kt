package com.example.quantumquest

import GameInterface
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.runtime.Composable

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            QuantumQuestTheme {
                GameInterface() // Make sure this is the correct name of your composable function
            }
        }
    }

    class QuantumQuestTheme(function: @Composable () -> Unit) {

    }

    /**
     * A native method that is implemented by the 'quantumquest' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'quantumquest' library on application startup.
        init {
            System.loadLibrary("quantumquest")
        }
    }
}