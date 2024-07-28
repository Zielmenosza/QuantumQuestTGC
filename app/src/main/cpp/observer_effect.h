#ifndef QUANTUM_QUEST_OBSERVER_EFFECT_H
#define QUANTUM_QUEST_OBSERVER_EFFECT_H

#include "quantum_state.h"

class ObserverEffect {
public:
    static void observeQubit(QuantumState& state, int qubitIndex);
};

#endif //QUANTUM_QUEST_OBSERVER_EFFECT_H