#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name, int value);
    virtual ~Item();

    // Accessor methods
    const std::string& getName() const;
    int getValue() const;

    // Define any virtual functions for item behavior
    virtual void use();

private:
    std::string name_;
    int value_; // Could represent item cost, power, or another characteristic
};

#endif // ITEM_H