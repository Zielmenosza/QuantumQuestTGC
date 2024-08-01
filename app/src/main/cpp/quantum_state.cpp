#include "quantum_state.h"
#include <random>

QuantumState::QuantumState(int numQubits) : qubits(numQubits, 0) {
    // Initialize qubits if necessary, default to state 0
}

int QuantumState::measureQubit(int qubitIndex) {
    // Simulate the measurement of a qubit
    if (qubitIndex >= 0 && qubitIndex < qubits.size()) {
        std::random_device rd;                           // Random device for seeding
        std::mt19937 gen(rd());                          // Mersenne Twister PRNG
        std::uniform_int_distribution<> distrib(0, 1);   // Uniform distribution between 0 and 1

        int outcome = distrib(gen);                      // Randomly return 0 or 1
        qubits[qubitIndex] = outcome;                    // Update qubit state to measured value
        return outcome;
    } else {
        // Handle invalid qubit index by logging an error or returning a sentinel value
        return -1; // Indicate an error in measurement
    }
}