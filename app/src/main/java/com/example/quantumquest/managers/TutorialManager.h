#ifndef TUTORIAL_MANAGER_H
#define TUTORIAL_MANAGER_H

#include "Player.h"

class TutorialManager {
public:
    TutorialManager();
    void startTutorial();
    void updateTutorialStep();
    void handlePlayerAction();

private:
    Player player;
    int currentStep;
    void performStep(int step);
};

#endif // TUTORIAL_MANAGER_H
