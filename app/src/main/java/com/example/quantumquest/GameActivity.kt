package com.example.quantumquest

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView

class GameActivity : AppCompatActivity() {
    private lateinit var gameManager: GameManager
    private lateinit var handTextView: TextView
    private lateinit var nextTurnButton: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_game)

        gameManager = GameManager()
        handTextView = findViewById(R.id.handTextView)
        nextTurnButton = findViewById(R.id.nextTurnButton)

        gameManager.startNewGame()
        updateUI()

        nextTurnButton.setOnClickListener {
            val gameOver = gameManager.playNextTurn()
            updateUI()
            if (gameOver) {
                nextTurnButton.isEnabled = false
                // TODO: Show game over message
            }
        }
    }

    private fun updateUI() {
        val hand = gameManager.getPlayerHand()
        handTextView.text = hand.joinToString("\n") { "${it.name} (Cost: ${it.cost})" }
    }
}