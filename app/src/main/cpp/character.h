#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
    Character(const std::string& name, int strength, int health, int experience = 0, int level = 1);

    void takeDamage(int damage);
    void attack(Character& target);
    void gainExperience(int exp);
    void levelUp();

    int getStrength() const { return strength; }
    int getHealth() const { return health; }
    int getExperience() const { return experience; }
    int getLevel() const { return level; }
    const std::string& getName() const { return name; }

private:
    std::string name;
    int strength;
    int health;
    int experience;
    int level;
};

#endif // CHARACTER_H