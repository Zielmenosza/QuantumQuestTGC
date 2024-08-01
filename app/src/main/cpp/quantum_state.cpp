#include "quantum_state.h"
#include <random>

QuantumState::QuantumState(int numQubits) : qubits(numQubits, 0) {
    // Initialize qubits if necessary
}

int QuantumState::measureQubit(int qubitIndex) {
    // Simulate the measurement of a qubit
    if (qubitIndex >= 0 && qubitIndex < qubits.size()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 1);
        int outcome = distrib(gen); // Randomly return 0 or 1

        qubits[qubitIndex] = outcome; // Update qubit state to measured value
        return outcome;
    }
    // Handle invalid qubit index
    return -1;
}