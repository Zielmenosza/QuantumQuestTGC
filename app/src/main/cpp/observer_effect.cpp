#include "observer_effect.h"
#include <iostream>

void ObserverEffect::observeQubit(QuantumState& state, int qubitIndex) {
    // Check if the qubit index is valid
    if (qubitIndex < 0 || qubitIndex >= state.getNumQubits()) {
        std::cerr << "Error: Qubit index " << qubitIndex << " is out of range." << std::endl;
        return;
    }

    // Measure the qubit and get the outcome
    int outcome = state.measureQubit(qubitIndex);
    if (outcome == -1) {
        std::cerr << "Error: Failed to measure qubit " << qubitIndex << "." << std::endl;
        return;
    }

    // Output the result of the observation
    std::cout << "Qubit " << qubitIndex << " observed! Outcome: " << outcome << std::endl;

    // Additional logic based on measurement outcome can be added here.
    if (outcome == 0) {
        std::cout << "Outcome is 0: Performing action for outcome 0." << std::endl;
        // Example action for outcome 0
    } else {
        std::cout << "Outcome is 1: Performing action for outcome 1." << std::endl;
        // Example action for outcome 1
    }
}