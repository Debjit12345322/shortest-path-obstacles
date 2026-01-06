#pragma once
#include <vector>

struct Point {
    double x, y;
};

double dist(const Point &a, const Point &b);

int orientation(const Point &a, const Point &b, const Point &c);
bool onSegment(const Point &a, const Point &b, const Point &c);
bool segmentsIntersect(const Point &p1, const Point &p2,
                       const Point &q1, const Point &q2);
