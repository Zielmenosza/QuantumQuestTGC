#include "quantum_state.h"
#include <random>
#include <stdexcept> // Include for std::out_of_range

QuantumState::QuantumState(int numQubits) : qubits(numQubits, 0) {
    // Initialize qubits if necessary, default to state 0
    // You can add initialization logic here if needed
}

int QuantumState::measureQubit(int qubitIndex) {
    // Validate qubit index
    if (qubitIndex < 0 || qubitIndex >= qubits.size()) {
        throw std::out_of_range("Qubit index out of range");
    }

    // Simulate the measurement of a qubit
    std::random_device rd;                           // Random device for seeding
    std::mt19937 gen(rd());                          // Mersenne Twister PRNG
    std::uniform_int_distribution<> distrib(0, 1);   // Uniform distribution between 0 and 1

    int outcome = distrib(gen);                      // Randomly return 0 or 1
    qubits[qubitIndex] = outcome;                    // Update qubit state to measured value
    return outcome;
}