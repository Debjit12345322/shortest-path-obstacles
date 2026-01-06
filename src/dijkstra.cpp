#include "dijkstra.hpp"
#include <queue>
#include <limits>
#include <algorithm>

std::vector<int> dijkstra(
    int n,
    const std::vector<std::vector<std::pair<int,double>>> &graph,
    int src,
    int dst
) {
    std::vector<double> dist(n, std::numeric_limits<double>::infinity());
    std::vector<int> parent(n, -1);

    using P = std::pair<double,int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        double d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;
        if (u == dst) break;

        for (auto edge : graph[u]) {
            int v = edge.first;
            double w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    std::vector<int> path;
    for (int v = dst; v != -1; v = parent[v])
        path.push_back(v);

    std::reverse(path.begin(), path.end());
    return path;
}
