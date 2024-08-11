package com.example.quantumquest

import android.util.Log


class GameManager {
    private var gamePtr: Long = 0

    private external fun createGame(): Long
    private external fun initializeGame(gamePtr: Long)
    private external fun playTurn(gamePtr: Long)
    private external fun isGameOver(gamePtr: Long): Boolean
    private external fun getCurrentPlayerHand(gamePtr: Long): Array<CardModel>

    fun startNewGame() {
        gamePtr = createGame()
        initializeGame(gamePtr)
    }

    fun playNextTurn(): Boolean {
        playTurn(gamePtr)
        return isGameOver(gamePtr)
    }

    fun getPlayerHand(): List<CardModel> {
        val playerHand = getCurrentPlayerHand(gamePtr).toList()
        Log.d("CardBattleScreen", "Player hand: $playerHand")
        return playerHand
            .filter { it.cost <= 0 }
            .sortedByDescending { it.cost }
    }
}