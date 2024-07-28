#pragma once

#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"

class Room {
public:
    // ... (your existing public methods)

    std::vector<Item>& getItems();
    std::vector<Enemy>& getEnemies();

private:
    std::string name;
    std::vector<Item> items;
    std::vector<Enemy> enemies;
    // ... (other private members)
};