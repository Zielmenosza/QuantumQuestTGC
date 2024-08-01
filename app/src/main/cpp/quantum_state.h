#ifndef QUANTUM_STATE_H
#define QUANTUM_STATE_H

#include <vector>

class QuantumState {
public:
    // Constructor to initialize the quantum state with a specified number of qubits
    QuantumState(int numQubits);

    // Measure a specific qubit and return its state (0 or 1)
    int measureQubit(int qubitIndex);

    // Additional methods and members for handling quantum state can be added here

private:
    // Vector to store the state of each qubit (0 or 1)
    std::vector<int> qubits;
};

#endif // QUANTUM_STATE_H