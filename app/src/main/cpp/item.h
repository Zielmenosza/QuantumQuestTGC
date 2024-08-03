// item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    // Constructor to initialize the item's name and value
    Item(const std::string& name, int value);

    // Virtual destructor to allow for proper cleanup of derived classes
    virtual ~Item();

    // Accessor methods for item properties
    const std::string& getName() const;
    int getValue() const;

    // Define any virtual functions for item behavior
    virtual void use();

private:
    std::string name_; // Name of the item
    int value_;        // Value of the item (could be cost, power, etc.)
};

#endif // ITEM_H