#ifndef ADVENTOFCODE_BOULDERS_H
#define ADVENTOFCODE_BOULDERS_H

#include <array>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

#include "utils.h"

namespace aoc {
  struct Cube {
    int x, y, z;
    bool operator==(const struct Cube &rhs) const {
      return x == rhs.x && y == rhs.y && z == rhs.z;
    }
  };
  using cube = struct Cube;
  using cube_map = std::array<std::array<std::array<bool, 22>, 22>, 22>;

  std::vector<cube> make_cubes(const std::vector<std::string>& lines);
  cube_map gen_cube_map(const std::vector<cube>& cubes);
  int calc_total_surface_area(const cube_map& map);
  int calc_actual_surface_area(const cube_map& map);
  int neighbors(const cube& c, const cube_map& map);
  int exposed_sides(cube cube, const cube_map &map);
  std::vector<cube> gen_neighbors(const cube &c);
}

namespace std {
  template<>
  struct hash<aoc::cube> {
    std::size_t operator()(const aoc::cube &c) const{
      std::hash<int> hasher{};
      return hasher(c.x) & (hasher(c.y) << 1) & (hasher(c.z) << 2);
    }
  };
}

#endif //ADVENTOFCODE_BOULDERS_H
