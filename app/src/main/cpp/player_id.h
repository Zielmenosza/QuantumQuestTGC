#ifndef PLAYER_ID_H
#define PLAYER_ID_H

#include <string>

// Enum class to define unique identifiers for each player
enum class PlayerID {
    PLAYER_ONE,
    PLAYER_TWO,
    // Add more player IDs as needed, for example:
    // PLAYER_THREE,
    // PLAYER_FOUR
};

// Function to convert PlayerID to a human-readable string
inline std::string playerIDToString(PlayerID id) {
    switch (id) {
        case PlayerID::PLAYER_ONE:
            return "Player One";
        case PlayerID::PLAYER_TWO:
            return "Player Two";
            // Add more cases for additional players
            // case PlayerID::PLAYER_THREE:
            //     return "Player Three";
            // case PlayerID::PLAYER_FOUR:
            //     return "Player Four";
        default:
            return "Unknown Player";
    }
}

#endif // PLAYER_ID_H