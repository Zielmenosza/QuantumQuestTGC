// item.cpp
#include "item.h"
#include <iostream>

// Constructor to initialize the item's name and value
Item::Item(const std::string& name, int value)
        : name_(name), value_(value) {}

// Destructor
Item::~Item() {}

// Accessor method to get the item's name
const std::string& Item::getName() const {
    return name_;
}

// Accessor method to get the item's value
int Item::getValue() const {
    return value_;
}

// Implement the use function with basic output
void Item::use() {
    std::cout << "Using item: " << name_ << std::endl;
}