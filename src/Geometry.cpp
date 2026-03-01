#include "Geometry.h"
#include <algorithm>

bool Point::operator<(const Point& o) const {
    return x < o.x || (x == o.x && y < o.y);
}

bool Point::operator==(const Point& o) const {
    return std::abs(x - o.x) < 1e-7 && std::abs(y - o.y) < 1e-7;
}

std::vector<Edge> Polygon::getEdges() const {
    std::vector<Edge> edges;
    for (size_t i = 0; i < vertices.size(); ++i) {
        edges.push_back({vertices[i], vertices[(i + 1) % vertices.size()]});
    }
    return edges;
}

double GeoUtils::dist(Point a, Point b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

int GeoUtils::orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (std::abs(val) < 1e-7) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counter-Clockwise
}

bool GeoUtils::doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Shared endpoints are not considered intersections for visibility graphs
    if (p1 == p2 || p1 == q2 || q1 == p2 || q1 == q2) return false;

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    return (o1 != o2 && o3 != o4);
}