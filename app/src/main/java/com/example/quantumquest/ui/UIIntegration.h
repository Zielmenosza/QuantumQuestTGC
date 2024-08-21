
#ifndef UINTEGRATION_H
#define UINTEGRATION_H

#include "GameController.h"

class UIIntegration {
public:
    void initializeUI();
    void updateUI();
    void handleUserInput();
    
private:
    GameController* m_gameController;
};

#endif // UINTEGRATION_H

