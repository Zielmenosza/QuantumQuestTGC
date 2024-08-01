#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Position.h"  // Assuming you have a Position struct defined elsewhere

class Obstacle {
private:
    Position position;   // Position of the obstacle in the game world
    float width;         // Width of the obstacle
    float height;        // Height of the obstacle

public:
    // Constructor
    Obstacle(const Position& pos, float w, float h)
            : position(pos), width(w), height(h) {}

    // Getters
    Position getPosition() const { return position; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }

    // Setters
    void setPosition(const Position& pos) { position = pos; }
    void setDimensions(float w, float h) {
        width = w;
        height = h;
    }

    // Check collision with another obstacle
    bool checkCollision(const Obstacle& other) const {
        // Simple AABB (Axis-Aligned Bounding Box) collision detection
        bool xCollide = position.x < other.position.x + other.width &&
                        position.x + width > other.position.x;
        bool yCollide = position.y < other.position.y + other.height &&
                        position.y + height > other.position.y;
        return xCollide && yCollide;
    }
};

#endif // OBSTACLE_H