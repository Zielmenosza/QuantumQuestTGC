#include "room.h"

Room::Room(const std::string& initialName) : name(initialName) {}

std::string Room::getName() const {
    return name;
}

void Room::setName(const std::string& newName) {
    name = newName;
}

std::vector<Item>& Room::getItems() {
    return items;
}

std::vector<Enemy>& Room::getEnemies() {
    return enemies;
}