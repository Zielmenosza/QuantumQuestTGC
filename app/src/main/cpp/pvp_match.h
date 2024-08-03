#ifndef PVP_MATCH_H
#define PVP_MATCH_H

#include "match.h"

class PvPMatch : public Match {
public:
    // Constructor to initialize a PvP match with two players and online status
    PvPMatch(Player* player1, Player* player2, bool isOnline);

    // Starts the PvP match, setting up initial conditions
    void start() override;

    // Updates the match state each frame or turn
    void update() override;

    // Ends the PvP match, handling any cleanup or results processing
    void end() override;

private:
    bool isOnline_; // Indicates if the match is an online match

    // Handles input for local PvP matches
    void handleLocalInput();

    // Handles input for online PvP matches
    void handleOnlineInput();
};

#endif // PVP_MATCH_H
