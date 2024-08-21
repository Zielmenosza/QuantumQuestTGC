#include "TemporalShifts.h"
#include <iostream>

TemporalShifts::TemporalShifts(const std::string& name, int cost, const std::string& effect)
    : Card(name, cost), m_effect(effect) {}

void TemporalShifts::activateEffect() {
    // Implement the effect logic here
    std::cout << "Activating Temporal Shift: " << m_effect << std::endl;
}
