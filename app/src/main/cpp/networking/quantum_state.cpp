#include "quantum_state.h"
#include <random>
#include <stdexcept> // Include for std::out_of_range

// Constructor definition
QuantumState::QuantumState(int numQubits) : qubits_(numQubits, 0) {}

int QuantumState::measureQubit(int qubitIndex) {
    if (qubitIndex < 0 || qubitIndex >= qubits_.size()) {
        return -1; // Invalid qubit index
    }

    int outcome = std::rand() % 2; // Generate a random outcome (0 or 1)
    qubits_[qubitIndex] = outcome; // Update qubit state
    return outcome;
}