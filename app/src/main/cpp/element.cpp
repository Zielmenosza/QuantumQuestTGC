#include "element.h"

// Constructor implementation
Element::Element(const std::string& name, ElementType type)
        : name(name), type(type) {}

// Getter for name
const std::string& Element::getName() const {
    return name;
}

// Getter for type
ElementType Element::getType() const {
    return type;
}

// Interaction function
void Element::interactWith(const Element& other) const {
    std::cout << name << " interacts with " << other.getName() << ". ";

    if (type == ElementType::Fire && other.getType() == ElementType::Water) {
        std::cout << "The fire is extinguished by water." << std::endl;
    } else if (type == ElementType::Water && other.getType() == ElementType::Fire) {
        std::cout << "The water extinguishes the fire." << std::endl;
    } else if (type == ElementType::Earth && other.getType() == ElementType::Air) {
        std::cout << "The earth resists the air." << std::endl;
    } else if (type == ElementType::Air && other.getType() == ElementType::Earth) {
        std::cout << "The air erodes the earth." << std::endl;
    } else if (type == ElementType::Fire && other.getType() == ElementType::Earth) {
        std::cout << "The fire scorches the earth." << std::endl;
    } else if (type == ElementType::Earth && other.getType() == ElementType::Fire) {
        std::cout << "The earth contains the fire." << std::endl;
    } else if (type == ElementType::Water && other.getType() == ElementType::Air) {
        std::cout << "The water forms clouds in the air." << std::endl;
    } else if (type == ElementType::Air && other.getType() == ElementType::Water) {
        std::cout << "The air evaporates the water." << std::endl;
    } else {
        std::cout << "There is no significant interaction." << std::endl;
    }
    // Add more interactions based on the types
}