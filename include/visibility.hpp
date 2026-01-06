#pragma once
#include "geometry.hpp"
#include <vector>

bool visible(const Point &a, const Point &b,
             const std::vector<std::vector<Point>> &obstacles);
