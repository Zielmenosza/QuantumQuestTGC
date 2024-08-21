
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"

class GameManager {
public:
    GameManager(Player* player1, Player* player2);
    void startGame();
    
private:
    Player* m_player1;
    Player* m_player2;
};

#endif // GAMEMANAGER_H

