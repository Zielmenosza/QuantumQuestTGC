#include "observer_effect.h"
#include <iostream>
#include "quantum_state.h"

void ObserverEffect::observeQubit(QuantumState& state, int qubitIndex) {
    int outcome = state.measureQubit(qubitIndex);
    std::cout << "Qubit " << qubitIndex << " observed! Outcome: " << outcome << std::endl;

    // Additional logic based on measurement outcome can be added here.
    // Example: Triggering game events or modifying the game state.
    // if (outcome == 0) {
    //     // Trigger event for outcome 0
    // } else {
    //     // Trigger event for outcome 1
    // }
}