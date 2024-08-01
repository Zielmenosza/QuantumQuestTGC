#ifndef OBSERVER_EFFECT_H
#define OBSERVER_EFFECT_H

#include "quantum_state.h"

class ObserverEffect {
public:
    // Function to observe a specific qubit in a quantum state.
    void observeQubit(QuantumState& state, int qubitIndex);
};

#endif // OBSERVER_EFFECT_H