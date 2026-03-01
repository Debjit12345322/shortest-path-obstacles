#include "Pathfinder.h"
#include <queue>
#include <algorithm>

std::vector<Point> Pathfinder::solve(Point start, Point end, const std::vector<Polygon>& obstacles) {
    std::vector<Point> nodes = {start, end};
    for (const auto& poly : obstacles) {
        for (const auto& v : poly.vertices) nodes.push_back(v);
    }

    // Map each point to its visible neighbors and the distance to them
    std::map<Point, std::vector<std::pair<Point, double>>> adj;
    for (size_t i = 0; i < nodes.size(); ++i) {
        for (size_t j = i + 1; j < nodes.size(); ++j) {
            if (isPathClear(nodes[i], nodes[j], obstacles)) {
                double d = GeoUtils::dist(nodes[i], nodes[j]);
                adj[nodes[i]].push_back({nodes[j], d});
                adj[nodes[j]].push_back({nodes[i], d});
            }
        }
    }

    std::priority_queue<std::pair<double, Point>, std::vector<std::pair<double, Point>>, std::greater<>> pq;
    std::map<Point, double> gScore;
    std::map<Point, Point> parent;

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

bool Pathfinder::isPathClear(Point a, Point b, const std::vector<Polygon>& obstacles) {
    for (const auto& poly : obstacles) {
        for (const auto& edge : poly.getEdges()) {
            if (GeoUtils::doIntersect(a, b, edge.a, edge.b)) return false;
        }
    }
    return true;
}

std::vector<Point> Pathfinder::reconstructPath(std::map<Point, Point>& parent, Point start, Point end) {
    std::vector<Point> path;
    for (Point p = end; !(p == start); p = parent[p]) path.push_back(p);
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}