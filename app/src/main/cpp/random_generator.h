#ifndef QUANTUM_QUEST_RANDOM_GENERATOR_H
#define QUANTUM_QUEST_RANDOM_GENERATOR_H

#include <random>

class RandomGenerator {
public:
    RandomGenerator();

    // Generate a random integer within a range (min <= value <= max)
    int generateInt(int min, int max);

    // Generate a random double within a range (min <= value <= max)
    double generateDouble(double min, double max);

private:
    std::mt19937 generator; // Mersenne Twister engine
};

#endif // QUANTUM_QUEST_RANDOM_GENERATOR_H