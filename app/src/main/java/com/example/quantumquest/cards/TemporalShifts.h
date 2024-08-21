#ifndef TEMPORALSHIFTS_H
#define TEMPORALSHIFTS_H

#include "Card.h"

class TemporalShifts : public Card {
public:
    TemporalShifts(const std::string& name, int cost, const std::string& effect);
    void activateEffect() override;

private:
    std::string m_effect;
};

#endif // TEMPORALSHIFTS_H
