#ifndef ADVENTOFCODE_HILL_H
#define ADVENTOFCODE_HILL_H

#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>

#include "point.h"

namespace aoc {
  std::vector<std::vector<int>> make_map(const std::vector<std::string>& lines);
  std::tuple<std::vector<point>, point> get_start_and_end(const std::vector<std::string>& map);
  std::vector<point> pathfind(const std::tuple<std::vector<point>, point>& start_end, const std::vector<std::vector<int>>& heightmap);
  std::vector<point> get_neighbors(const point &point, const std::vector<std::vector<int>>& heightmap);
}

#endif //ADVENTOFCODE_HILL_H
