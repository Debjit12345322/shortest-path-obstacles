#include "visibility.hpp"

bool visible(const Point &a, const Point &b,
             const std::vector<std::vector<Point>> &obstacles) {
    for (const auto &poly : obstacles) {
        int k = poly.size();
        for (int i = 0; i < k; i++) {
            Point p = poly[i];
            Point q = poly[(i + 1) % k];
            // Ignore touching at endpoints
            if ((p.x == a.x && p.y == a.y) || (p.x == b.x && p.y == b.y)) continue;
            if ((q.x == a.x && q.y == a.y) || (q.x == b.x && q.y == b.y)) continue;
            if (segmentsIntersect(a, b, p, q))
                return false;
        }
    }
    return true;
}
