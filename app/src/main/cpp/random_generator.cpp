#include "random_generator.h"
#include "random_generator.h"

RandomGenerator::RandomGenerator() : generator(std::random_device{}()) {}

__attribute__((unused)) int RandomGenerator::generateInt(int min, int max) {
    if (min > max) {
        // Handle error: min should be less than or equal to max
        throw std::invalid_argument("Minimum value cannot be greater than maximum value");
    }
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

__attribute__((unused)) __attribute__((unused)) double RandomGenerator::generateDouble(double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

__attribute__((unused)) int RandomGenerator::generateInt(int min, int max) {
    return 0;
}
