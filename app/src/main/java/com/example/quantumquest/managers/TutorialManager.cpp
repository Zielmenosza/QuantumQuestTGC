#include "TutorialManager.h"
#include "GameManager.h"

TutorialManager::TutorialManager() : currentStep(0) {}

void TutorialManager::startTutorial() {
    player.initialize();
    currentStep = 1;
    performStep(currentStep);
}

void TutorialManager::updateTutorialStep() {
    currentStep++;
    performStep(currentStep);
}

void TutorialManager::handlePlayerAction() {
    player.performAction();
    updateTutorialStep();
}

void TutorialManager::performStep(int step) {
    switch (step) {
        case 1:
            // Show initial tutorial message
            break;
        case 2:
            // Guide player to perform an action
            break;
        // Add more steps as needed
        default:
            // End of tutorial
            break;
    }
}
