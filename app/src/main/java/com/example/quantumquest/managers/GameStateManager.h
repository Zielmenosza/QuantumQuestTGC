
#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

enum class GameState {
    MainMenu,
    Playing,
    GameOver
};

class GameStateManager {
public:
    GameState getCurrentState() const;
    void setCurrentState(GameState state);
    
private:
    GameState m_currentState;
};

#endif // GAMESTATEMANAGER_H

