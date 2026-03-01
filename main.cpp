#include <iostream>
#include "src/Pathfinder.h"

int main() {
    Point start = {0, 0};
    Point end = {10, 5};

    // Example Obstacle: A Rhombus
    Polygon obstacle;
    obstacle.vertices = {{4, 2}, {6, 1}, {8, 2}, {6, 3}};

    std::vector<Polygon> obstacles = {obstacle};

    std::vector<Point> result = Pathfinder::solve(start, end, obstacles);

    if (result.empty()) {
        std::cout << "Path Blocked!" << std::endl;
    } else {
        for (const auto& p : result) {
            std::cout << "(" << p.x << ", " << p.y << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}