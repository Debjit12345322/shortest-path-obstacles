#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Geometry.h"
#include <map>
#include <vector>

class Pathfinder {
public:
    /**
     * Finds the shortest Euclidean path using a Visibility Graph and A*.
     * Returns an empty vector if no path is possible.
     */
    static vector<Point> solve(Point start, Point end, const vector<Polygon>& obstacles);

private:
    // Enhanced check: now validates against both edge intersections and interior cutting
    static bool isPathClear(Point a, Point b, const vector<Polygon>& obstacles);

    static vector<Point> reconstructPath(map<Point, Point>& parent, Point start, Point end);
};

#endif