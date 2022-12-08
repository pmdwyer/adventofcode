#ifndef ADVENTOFCODE_GRID_H
#define ADVENTOFCODE_GRID_H

#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

namespace aoc {
  class grid {
  public:
    grid(const std::vector<std::string>& text);

    int calc_visible_trees();

  private:
    std::vector<std::vector<int>> _matrix;
  };
}

#endif //ADVENTOFCODE_GRID_H
