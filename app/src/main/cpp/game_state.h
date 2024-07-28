#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState {
public:
    // Member variables for player health, turn order, etc. (replace with your specific needs)
    int player1Health;
    int player2Health;
    int currentPlayer;
    // ... other game state variables

    // Methods to access and modify game state (replace with your specific needs)
    int getPlayerHealth(int playerNumber);
    void setPlayerHealth(int playerNumber, int newHealth);
    int getCurrentPlayer();
    void setCurrentPlayer(int newPlayer);
    // ... other game state methods

private:
    // Private members if needed
};

#endif  // GAME_STATE_H