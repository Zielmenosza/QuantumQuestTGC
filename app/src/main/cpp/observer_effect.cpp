#include "observer_effect.h"
#include <iostream>

void ObserverEffect::observeQubit(QuantumState& state, int qubitIndex) {
    int outcome = state.measureQubit(qubitIndex);
    std::cout << "Qubit " << qubitIndex << " observed! Outcome:" << outcome << std::endl;
    // You can add additional logic here based on the measurement outcome,
    // such as triggering game events or modifying the game state.
}