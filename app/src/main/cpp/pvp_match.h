// pvp_match.h
#ifndef PVP_MATCH_H
#define PVP_MATCH_H

#include "match.h"

class PvPMatch : public Match {
public:
    PvPMatch(Player* player1, Player* player2, bool isOnline);

    void start() override;
    void update() override;
    void end() override;

private:
    bool isOnline_;
    void handleLocalInput();
    void handleOnlineInput();
};

#endif // PVP_MATCH_H