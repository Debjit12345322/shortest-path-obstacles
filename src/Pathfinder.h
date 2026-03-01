//
// Created by Lenovo on 01-03-2026.
//

#ifndef SHORTEST_PATH_OBSTACLES_PATHFINDER_H
#define SHORTEST_PATH_OBSTACLES_PATHFINDER_H

#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Geometry.h"
#include <map>

class Pathfinder {
public:
    static std::vector<Point> solve(Point start, Point end, const std::vector<Polygon>& obstacles);

private:
    static bool isPathClear(Point a, Point b, const std::vector<Polygon>& obstacles);
    static std::vector<Point> reconstructPath(std::map<Point, Point>& parent, Point start, Point end);
};

#endif

#endif //SHORTEST_PATH_OBSTACLES_PATHFINDER_H