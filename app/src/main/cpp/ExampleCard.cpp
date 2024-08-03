#include "ExampleCard.h" // Include the header file for ExampleCard

// Constructor definition that calls the base class constructor
ExampleCard::ExampleCard(const std::string& name, int cost)
        : Card(name, cost) // Call the base class constructor with arguments
{
    // Additional initialization if needed
}

// Implement getName method using the base class method
std::string ExampleCard::getName() const {
    return Card::getName();
}

// Implement getCost method using the base class method
int ExampleCard::getCost() const {
    return Card::getCost();
}