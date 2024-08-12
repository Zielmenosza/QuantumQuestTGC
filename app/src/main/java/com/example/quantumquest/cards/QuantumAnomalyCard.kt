package com.example.quantumquest.cards
import com.example.quantumquest.QuantumAnomalyCard
import com.example.quantumquest.Card


import com.example.quantumquest.model.Card

open class QuantumAnomalyCard 
    id: Int,
    name: String,
    description: String,
    val anomalyEffect: String
) : Card(id, name, description) {

    fun triggerAnomaly() {
        // Define the behavior of triggering an anomaly
    }
}