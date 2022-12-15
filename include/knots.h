#ifndef ADVENTOFCODE_KNOTS_H
#define ADVENTOFCODE_KNOTS_H

#include <string>
#include <unordered_set>
#include <vector>

#include "utils.h"

namespace aoc {
  struct Move {
    char dir;
    int amount;
  };

  struct Point {
    int x, y;

    bool operator==(const struct Point& rhs) const {
      return x == rhs.x && y == rhs.y;
    }
  };

  using point = struct Point;
  using move = struct Move;

  std::vector<move> make_moves(const std::vector<std::string>& lines);
  int count_unique_moves(const std::vector<move>& moves, int num_knots);
}

namespace std {
  template<>
  struct hash<aoc::point> {
    std::size_t operator()(const aoc::point& p) const {
      return std::hash<int>{}(p.x) & (std::hash<int>{}(p.y) << 1);
    }
  };
}

#endif //ADVENTOFCODE_KNOTS_H
