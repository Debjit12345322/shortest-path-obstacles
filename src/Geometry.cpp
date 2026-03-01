#include "Geometry.h"
#include <bits/stdc++.h>
using namespace std;

bool Point::operator<(const Point& o) const {
    return x < o.x || (x == o.x && y < o.y);
}

bool Point::operator==(const Point& o) const {
    return abs(x - o.x) < 1e-7 && abs(y - o.y) < 1e-7;
}

vector<Edge> Polygon::getEdges() const {
    vector<Edge> edges;
    for (size_t i = 0; i < vertices.size(); ++i) {
        edges.push_back({vertices[i], vertices[(i + 1) % vertices.size()]});
    }
    return edges;
}

// Check if a point is inside a polygon using Ray Casting
bool Polygon::contains(Point p) const {
    bool inside = false;
    int n = vertices.size();
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((vertices[i].y > p.y) != (vertices[j].y > p.y)) &&
            (p.x < (vertices[j].x - vertices[i].x) * (p.y - vertices[i].y) /
            (vertices[j].y - vertices[i].y) + vertices[i].x)) {
            inside = !inside;
            }
    }
    return inside;
}

double GeoUtils::dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int GeoUtils::orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (abs(val) < 1e-7) return 0;
    return (val > 0) ? 1 : 2;
}

bool GeoUtils::doIntersect(Point p1, Point q1, Point p2, Point q2) {
    if (p1 == p2 || p1 == q2 || q1 == p2 || q1 == q2) return false;
    int o1 = orientation(p1, q1, p2), o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1), o4 = orientation(p2, q2, q1);
    return (o1 != o2 && o3 != o4);
}