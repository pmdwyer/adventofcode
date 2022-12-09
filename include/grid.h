#ifndef ADVENTOFCODE_GRID_H
#define ADVENTOFCODE_GRID_H

#include <algorithm>
#include <array>
#include <bitset>
#include <numeric>
#include <string>
#include <vector>

namespace aoc {
  class grid {
  public:
    grid(const std::vector<std::string>& text);

    int calc_visible_trees();
    int calc_scenic_score();

  private:
    std::vector<std::vector<int>> _matrix;
  };
}

#endif //ADVENTOFCODE_GRID_H
