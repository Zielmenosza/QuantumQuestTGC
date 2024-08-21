
#include "GameUtils.h"
#include <iostream>

void GameUtils::logError(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}

void GameUtils::logInfo(const std::string& message) {
    std::cout << "Info: " << message << std::endl;
}

