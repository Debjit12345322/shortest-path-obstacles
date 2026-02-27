#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(
    int n,
    const vector<vector<pair<int,double>>> &graph,
    int src,
    int dst
);
