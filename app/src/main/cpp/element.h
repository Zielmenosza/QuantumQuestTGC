//
// Created by Ziel on 2024/08/01.
//

#ifndef QUANTUMQUEST_ELEMENT_H
#define QUANTUMQUEST_ELEMENT_H

#endif //QUANTUMQUEST_ELEMENT_H
a//
// Created by Ziel on 2024/07/12.
//

#ifndef QUANTUM_QUEST_ELEMENT_H
#define QUANTUM_QUEST_ELEMENT_H

#include <string>
#include <iostream>

enum class ElementType {
    Fire,
    Water,
    Earth,
    Air,
    // Add more element types as needed
};

class Element {
public:
    // Constructor
    Element(const std::string& name, ElementType type);

    // Accessor methods
    const std::string& getName() const;
    ElementType getType() const;

    // Methods to interact with other elements
    void interactWith(const Element& other) const;

private:
    std::string name;
    ElementType type;
};

#endif // QUANTUM_QUEST_ELEMENT_H