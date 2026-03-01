//
// Created by Lenovo on 01-03-2026.
//

#ifndef SHORTEST_PATH_OBSTACLES_GEOMETRY_H
#define SHORTEST_PATH_OBSTACLES_GEOMETRY_H

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <cmath>

struct Point {
    double x, y;
    bool operator<(const Point& o) const;
    bool operator==(const Point& o) const;
};

struct Edge { Point a, b; };

class Polygon {
public:
    std::vector<Point> vertices;
    std::vector<Edge> getEdges() const;
};

namespace GeoUtils {
    double dist(Point a, Point b);
    int orientation(Point p, Point q, Point r);
    bool doIntersect(Point p1, Point q1, Point p2, Point q2);
}

#endif

#endif //SHORTEST_PATH_OBSTACLES_GEOMETRY_H