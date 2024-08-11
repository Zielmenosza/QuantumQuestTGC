#ifndef POSITION_H
#define POSITION_H

#include "direction.h"
#include <cmath>  // Include cmath for std::sqrt

struct Position {
    int x;
    int y;

    // Default constructor with member initializer list
    Position(int x = 0, int y = 0) : x(x), y(y) {}

    // Move the position in a specified direction
    void move(Direction dir, int steps = 1) {
        switch (dir) {
            case Direction::UP:
                y -= steps;
                break;
            case Direction::DOWN:
                y += steps;
                break;
            case Direction::LEFT:
                x -= steps;
                break;
            case Direction::RIGHT:
                x += steps;
                break;
            case Direction::UP_LEFT:
                x -= steps;
                y -= steps;
                break;
            case Direction::UP_RIGHT:
                x += steps;
                y -= steps;
                break;
            case Direction::DOWN_LEFT:
                x -= steps;
                y += steps;
                break;
            case Direction::DOWN_RIGHT:
                x += steps;
                y += steps;
                break;
        }
    }

    // Calculates the distance to another position using Euclidean distance
    double distanceTo(const Position& other) const {
        int dx = x - other.x;
        int dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    // Overload the equality operator
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    // Overload the inequality operator
    bool operator!=(const Position& other) const {
        return !(*this == other);
    }
};

#endif // POSITION_H