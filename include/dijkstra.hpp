#pragma once
#include <vector>

std::vector<int> dijkstra(
    int n,
    const std::vector<std::vector<std::pair<int,double>>> &graph,
    int src,
    int dst
);
