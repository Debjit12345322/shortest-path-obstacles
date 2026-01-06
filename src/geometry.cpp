#include "geometry.hpp"
#include <cmath>

double dist(const Point &a, const Point &b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

// 0 -> collinear, 1 -> clockwise, 2 -> counterclockwise
int orientation(const Point &a, const Point &b, const Point &c) {
    double val = (b.y - a.y) * (c.x - b.x) -
                 (b.x - a.x) * (c.y - b.y);
    if (std::abs(val) < 1e-9) return 0;
    return (val > 0) ? 1 : 2;
}

bool onSegment(const Point &a, const Point &b, const Point &c) {
    return c.x <= std::max(a.x, b.x) && c.x >= std::min(a.x, b.x) &&
           c.y <= std::max(a.y, b.y) && c.y >= std::min(a.y, b.y);
}

bool segmentsIntersect(const Point &p1, const Point &p2,
                       const Point &q1, const Point &q2) {
    int o1 = orientation(p1, p2, q1);
    int o2 = orientation(p1, p2, q2);
    int o3 = orientation(q1, q2, p1);
    int o4 = orientation(q1, q2, p2);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, p2, q2)) return true;
    if (o3 == 0 && onSegment(q1, q2, p1)) return true;
    if (o4 == 0 && onSegment(q1, q2, p2)) return true;

    return false;
}
