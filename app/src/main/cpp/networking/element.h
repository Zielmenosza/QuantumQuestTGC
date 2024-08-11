#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>  // Include string for std::string
#include <iostream> // Include iostream for std::cout

// Define an enumeration for ElementType
enum class ElementType {
    Fire,
    Water,
    Earth,
    Air
};

class Element {
public:
    // Constructor
    Element(const std::string& name, ElementType type);

    // Getter functions
    const std::string& getName() const;
    ElementType getType() const;

    // Function for interaction
    void interactWith(const Element& other) const;

private:
    // Member variables
    std::string name;
    ElementType type;
};

#endif // ELEMENT_H