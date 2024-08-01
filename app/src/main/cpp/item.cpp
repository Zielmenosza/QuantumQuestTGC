#include "item.h"
#include <iostream>

// Constructor
Item::Item(const std::string& name, int value)
        : name_(name), value_(value) {}

// Destructor
Item::~Item() {}

// Accessor methods
const std::string& Item::getName() const {
    return name_;
}

int Item::getValue() const {
    return value_;
}

// Implement the use function with basic output
void Item::use() {
    std::cout << "Using item: " << name_ << std::endl;
}