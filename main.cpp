
#include <bits/stdc++.h>
using namespace std;
#include "src/Pathfinder.h"

int main() {
    Point start = {0, 0};
    Point end = {20, 18};

    vector<Polygon> obstacles;

    obstacles.push_back({{ {2,2}, {5,1}, {4,5} }});            // A
    obstacles.push_back({{ {7,8}, {10,6}, {13,8}, {10,10} }}); // B
    obstacles.push_back({{ {2,12}, {4,11}, {6,12}, {6,14}, {4,15}, {2,14} }}); // C
    obstacles.push_back({{ {15,5}, {17,5}, {17,15}, {15,15} }}); // D
    obstacles.push_back({{ {12,16}, {14,13}, {13,18} }});      // E
    obstacles.push_back({{ {12,2}, {14,1}, {16,2}, {14,3} }}); // F

    vector<Point> path = Pathfinder::solve(start, end, obstacles);

    if (path.empty()) {
        cout << "Path Blocked!" << endl;
    } else {
        cout << "Correct Shortest Path Found:" << endl;
        for (const auto& p : path) cout << "(" << p.x << ", " << p.y << ") ";
        cout << endl;
    }

    return 0;
}