#include <bits/stdc++.h>
#include "geometry.hpp"
#include "visibility.hpp"
#include "dijkstra.hpp"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point start, end;
    cin >> start.x >> start.y;
    cin >> end.x >> end.y;

    int M;
    cin >> M;
    vector<vector<Point>> obstacles(M);

    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        obstacles[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> obstacles[i][j].x >> obstacles[i][j].y;
    }

    vector<Point> nodes;
    nodes.push_back(start);
    nodes.push_back(end);

    for (auto &poly : obstacles)
        for (auto &p : poly)
            nodes.push_back(p);

    int N = nodes.size();
    vector<vector<pair<int,double>>> graph(N);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (visible(nodes[i], nodes[j], obstacles)) {
                double w = dist(nodes[i], nodes[j]);
                graph[i].push_back({j, w});
                graph[j].push_back({i, w});
            }
        }
    }

    vector<int> path = dijkstra(N, graph, 0, 1);

    cout << path.size() << "\n";
    for (int idx : path)
        cout << nodes[idx].x << " " << nodes[idx].y << "\n";

    return 0;
}
