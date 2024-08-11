#ifndef AR_MATCH_H
#define AR_MATCH_H

#include "match.h"
#include "ar_manager.h"

class ARMatch : public Match {
public:
    ARMatch(Player* player, ARManager& arManager); // Declaration only

    void start() override;
    void update() override;
    void end() override;

private:
    ARManager& arManager_;void handleARInput();
    void updateRealWorldMap();
};

#endif // AR_MATCH_H