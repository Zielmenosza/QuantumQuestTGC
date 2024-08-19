package com.example.quantumquest.cards

class QuantumAnomalyCard(
    id: Int,
    name: String,
    description: String,
    cost: Int // Include the cost parameter
) : Card(id, name, description, cost) {

    fun triggerAnomaly() {
        // Implementation for triggering the quantum anomaly effect
    }
}