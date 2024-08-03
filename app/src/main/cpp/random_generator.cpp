#include "random_generator.h"
#include <stdexcept> // Include for std::invalid_argument
#include <random>    // Include for random_device, uniform_int_distribution, uniform_real_distribution

// Constructor initializes the random number generator with a random seed.
RandomGenerator::RandomGenerator() : generator(std::random_device{}()) {}

// Generates a random integer within a given range [min, max].
int RandomGenerator::generateInt(int min, int max) {
    if (min > max) {
        // Throw an exception if the min value is greater than the max value.
        throw std::invalid_argument("Minimum value cannot be greater than maximum value");
    }
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

// Generates a random double within a given range [min, max].
double RandomGenerator::generateDouble(double min, double max) {
    if (min > max) {
        // Throw an exception if the min value is greater than the max value.
        throw std::invalid_argument("Minimum value cannot be greater than maximum value");
    }
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}