package com.example.QuantumQuest

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    // Example function to demonstrate logging
    fun displayCardInfo() {
        // Simulate card handles and information retrieval without JNI
        val cardNames = arrayOf("Ace of Spades", "King of Hearts", "Queen of Diamonds")
        val cardCosts = intArrayOf(5, 10, 8)

        for (i in cardNames.indices) {
            Log.d("CardInfo", "Name: ${cardNames[i]}, Cost: ${cardCosts[i]}")
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example call to display card information
        displayCardInfo()
    }

    companion object {
        // No need to load any native library if not using JNI
        init {
            // This block is intentionally left empty if no library is needed
        }
    }
}