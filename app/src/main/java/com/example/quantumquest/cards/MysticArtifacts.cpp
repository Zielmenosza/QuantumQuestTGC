#include "MysticArtifacts.h"
#include <iostream>

MysticArtifacts::MysticArtifacts(const std::string& name, int cost, const std::string& effect)
    : Card(name, cost), m_effect(effect) {}

void MysticArtifacts::activateEffect() {
    // Implement the effect logic here
    std::cout << "Activating Mystic Artifact: " << m_effect << std::endl;
}
