#ifndef ADVENTOFCODE_KNOTS_H
#define ADVENTOFCODE_KNOTS_H

#include <string>
#include <unordered_set>
#include <vector>

#include "utils.h"
#include "point.h"

namespace aoc {
  struct Move {
    char dir;
    int amount;
  };
  using move = struct Move;

  std::vector<move> make_moves(const std::vector<std::string>& lines);
  int count_unique_moves(const std::vector<move>& moves, int num_knots);
}

#endif //ADVENTOFCODE_KNOTS_H
