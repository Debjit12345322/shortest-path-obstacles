//
// Created by Lenovo on 01-03-2026.
//

#ifndef SHORTEST_PATH_OBSTACLES_GEOMETRY_H
#define SHORTEST_PATH_OBSTACLES_GEOMETRY_H

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    bool operator<(const Point& o) const;
    bool operator==(const Point& o) const;
};

struct Edge { Point a, b; };

class Polygon {
public:
    vector<Point> vertices;

    // Returns the individual line segments of the polygon
    vector<Edge> getEdges() const;

    // NEW: Checks if a coordinate is strictly inside the polygon
    bool contains(Point p) const;
};

namespace GeoUtils {
    double dist(Point a, Point b);
    int orientation(Point p, Point q, Point r);
    bool doIntersect(Point p1, Point q1, Point p2, Point q2);
}

#endif //SHORTEST_PATH_OBSTACLES_GEOMETRY_H