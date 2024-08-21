#ifndef MYSTICARTIFACTS_H
#define MYSTICARTIFACTS_H

#include "Card.h"

class MysticArtifacts : public Card {
public:
    MysticArtifacts(const std::string& name, int cost, const std::string& effect);
    void activateEffect() override;

private:
    std::string m_effect;
};

#endif // MYSTICARTIFACTS_H
