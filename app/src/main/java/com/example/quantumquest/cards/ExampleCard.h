
#ifndef EXAMPLECARD_H
#define EXAMPLECARD_H

#include "CardTypeSpecific.h"

class ExampleCard : public CardTypeSpecific {
public:
    ExampleCard(const std::string& name, int power);
    void activateEffect() override;
};

#endif // EXAMPLECARD_H

