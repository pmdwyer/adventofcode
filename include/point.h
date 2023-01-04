#ifndef ADVENTOFCODE_POINT_H
#define ADVENTOFCODE_POINT_H

#include <utility>

namespace aoc {
  struct Point {
    int x, y;

    bool operator==(const struct Point& rhs) const {
      return x == rhs.x && y == rhs.y;
    }
  };
  using point = struct Point;
}

namespace std {
  template<>
  struct hash<aoc::point> {
    std::size_t operator()(const aoc::point& p) const {
      return std::hash<int>{}(p.x) & (std::hash<int>{}(p.y) << 1);
    }
  };
}

#endif //ADVENTOFCODE_POINT_H
