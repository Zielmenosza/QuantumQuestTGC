#ifndef QUANTUM_STATE_H
#define QUANTUM_STATE_H

#include "vector"
#include <cstdlib>

class QuantumState {public:
    // Constructor declaration
    QuantumState(int numQubits);

    int getNumQubits() const {
        return qubits_.size();
    }

    int measureQubit(int qubitIndex);

private:
    std::vector<int> qubits_; // Declare qubits_ as a member
};

#endif // QUANTUM_STATE_H