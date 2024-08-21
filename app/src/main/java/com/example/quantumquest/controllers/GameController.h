
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "CardManager.h"
#include "Player.h"

class GameController {
public:
    GameController();
    void startGame();
    void endGame();
    void playerTurn(Player& player);
    
private:
    CardManager m_cardManager;
    Player m_player1;
    Player m_player2;
    void handleCardEffects();
};

#endif // GAMECONTROLLER_H

