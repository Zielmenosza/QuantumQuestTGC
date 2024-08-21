#include "TutorialManager.h"

TutorialManager::TutorialManager(GameManager* gameManager) : gameManager(gameManager) {}

void TutorialManager::startTutorial() {
    gameManager->startTutorial();
    // Implement tutorial steps
}
