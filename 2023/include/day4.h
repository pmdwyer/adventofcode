#ifndef ADVENTOFCODE_DAY4_H
#define ADVENTOFCODE_DAY4_H

#include <vector>

namespace aoc
{
  std::vector<std::vector<std::vector<int>>> parse_input();
  int count_matches(const std::vector<std::vector<int>>& card);
  void part1(const std::vector<std::vector<std::vector<int>>>& input);
  void part2(const std::vector<std::vector<std::vector<int>>>& input);
}

#endif //ADVENTOFCODE_DAY4_H
