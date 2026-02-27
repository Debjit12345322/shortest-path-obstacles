#include "dijkstra.hpp"
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(
    int n,
    const vector<vector<pair<int,double>>> &graph,
    int src,
    int dst
) {
    vector<double> dist(n, numeric_limits<double>::infinity());
    vector<int> parent(n, -1);

    using P = pair<double,int>;
    priority_queue<P, vector<P>, greater<P>> pq;

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

    vector<int> path;
    for (int v = dst; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}