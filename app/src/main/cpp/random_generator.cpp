#include "random_generator.h"
#include <stdexcept> // Include for std::invalid_argument
#include <random>    // Include for random_device, uniform_int_distribution, uniform_real_distribution

RandomGenerator::RandomGenerator() : generator(std::random_device{}()) {}

int RandomGenerator::generateInt(int min, int max) {
    if (min > max) {
        // Handle error: min should be less than or equal to max
        throw std::invalid_argument("Minimum value cannot be greater than maximum value");
    }
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

double RandomGenerator::generateDouble(double min, double max) {
    if (min > max) {
        // Handle error: min should be less than or equal to max
        throw std::invalid_argument("Minimum value cannot be greater than maximum value");
    }
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}