
#include "Card.h"

Card::Card(const std::string& name)
    : m_name(name) {}

std::string Card::getName() const {
    return m_name;
}

