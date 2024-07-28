#ifndef QUANTUM_QUEST_QUANTUM_STATE_H
#define QUANTUM_QUEST_QUANTUM_STATE_H

#include <vector>
#include <complex>
#include <random>

class QuantumState {
public:
    QuantumState(int numQubits);

    void applyGate(const std::vector<std::vector<std::complex<double>>>& gate, int qubitIndex);
    std::vector<std::complex<double>> getStateVector() const;
    int measureQubit(int qubitIndex);

private:
    std::vector<std::complex<double>> stateVector;
    std::mt19937 generator; // Correct way to declare the random number generator
};

#endif // QUANTUM_QUEST_QUANTUM_STATE_H