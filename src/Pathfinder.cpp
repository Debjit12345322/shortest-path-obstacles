#include "Pathfinder.h"
#include <queue>
#include <algorithm>

bool Pathfinder::isPathClear(Point a, Point b, const std::vector<Polygon>& obstacles) {
    // 1. Check for edge intersections
    for (const auto& poly : obstacles) {
        for (const auto& edge : poly.getEdges()) {
            if (GeoUtils::doIntersect(a, b, edge.a, edge.b)) return false;
        }
    }

    // 2. Check if the midpoint of the segment is inside any obstacle
    Point midpoint = {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
    for (const auto& poly : obstacles) {
        if (poly.contains(midpoint)) return false;
    }

    return true;
}

vector<Point> Pathfinder::solve(Point start, Point end, const vector<Polygon>& obstacles) {
    vector<Point> nodes = {start, end};
    for (const auto& poly : obstacles) {
        for (const auto& v : poly.vertices) nodes.push_back(v);
    }

    map<Point, vector<pair<Point, double>>> adj;
    for (size_t i = 0; i < nodes.size(); ++i) {
        for (size_t j = i + 1; j < nodes.size(); ++j) {
            if (isPathClear(nodes[i], nodes[j], obstacles)) {
                double d = GeoUtils::dist(nodes[i], nodes[j]);
                adj[nodes[i]].push_back({nodes[j], d});
                adj[nodes[j]].push_back({nodes[i], d});
            }
        }
    }

    priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<>> pq;
    map<Point, double> gScore;
    map<Point, Point> parent;

    for (const auto& n : nodes) gScore[n] = 1e18;
    gScore[start] = 0;
    pq.push({GeoUtils::dist(start, end), start});

    while (!pq.empty()) {
        Point curr = pq.top().second;
        pq.pop();

        if (curr == end) return reconstructPath(parent, start, end);

        for (auto& edge : adj[curr]) {
            double tentG = gScore[curr] + edge.second;
            if (tentG < gScore[edge.first]) {
                parent[edge.first] = curr;
                gScore[edge.first] = tentG;
                pq.push({tentG + GeoUtils::dist(edge.first, end), edge.first});
            }
        }
    }
    return {};
}

vector<Point> Pathfinder::reconstructPath(map<Point, Point>& parent, Point start, Point end) {
    vector<Point> path;
    Point curr = end;
    while (!(curr == start)) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}