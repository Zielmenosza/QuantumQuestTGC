#ifndef QUANTUM_STATE_H
#define QUANTUM_STATE_H

#include <vector>

class QuantumState {
public:
    QuantumState(int numQubits);

    // Method to measure a specific qubit and return its state (0 or 1)
    int measureQubit(int qubitIndex);

    // Additional methods and members for handling quantum state can be added here

private:
    std::vector<int> qubits; // Example representation of qubit states
};

#endif // QUANTUM_STATE_H