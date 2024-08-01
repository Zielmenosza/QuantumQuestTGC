//
// Created by Ziel on 2024/07/12.
//

#include "element.h"

// Constructor
Element::Element(const std::string& name, ElementType type)
        : name(name), type(type) {}

// Accessor methods
const std::string& Element::getName() const {
    return name;
}

ElementType Element::getType() const {
    return type;
}

// Method to define interaction logic between elements
void Element::interactWith(const Element& other) const {
    std::cout << name << " interacts with " << other.getName() << ". ";

    // Example interaction logic based on element type
    if (type == ElementType::Fire && other.getType() == ElementType::Water) {
        std::cout << "The fire is extinguished by water." << std::endl;
    } else if (type == ElementType::Water && other.getType() == ElementType::Fire) {
        std::cout << "The water extinguishes the fire." << std::endl;
    } else if (type == ElementType::Earth && other.getType() == ElementType::Air) {
        std::cout << "The earth remains unaffected by air." << std::endl;
    } else {
        std::cout << "The elements interact with no special effect." << std::endl;
    }
}