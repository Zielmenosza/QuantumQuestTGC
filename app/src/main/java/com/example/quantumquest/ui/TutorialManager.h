#ifndef TUTORIAL_MANAGER_H
#define TUTORIAL_MANAGER_H

#include "GameManager.h"

class TutorialManager {
public:
    TutorialManager(GameManager* gameManager);
    void startTutorial();
    // Add more methods as needed

private:
    GameManager* gameManager;
};

#endif // TUTORIAL_MANAGER_H
