
#include "CardDatabase.h"
#include <fstream>
#include <sstream>
#include <iostream>

void CardDatabase::loadCardsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        // Assuming card data format: name,type,power
        if (!(iss >> name)) { continue; }
        Card* card = new Card(name);
        m_cardMap[name] = card;
    }

    file.close();
}

Card* CardDatabase::getCard(const std::string& name) const {
    auto it = m_cardMap.find(name);
    if (it != m_cardMap.end()) {
        return it->second;
    }
    return nullptr;
}

