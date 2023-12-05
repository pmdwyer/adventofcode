#ifndef ADVENTOFCODE_DAY3_H
#define ADVENTOFCODE_DAY3_H

#include <vector>
#include <string>

namespace aoc
{
  bool symbol(const char& c);
  bool is_part(const std::vector<std::string>& parts, int x, int start, int end);
  int process(const std::vector<std::string>& parts, int i, int& j);
  void part1(const std::vector<std::string> &engine);
  int expand(const std::vector<std::string> &engine, int i, int& j);
  int calc_ratio(const std::vector<std::string> &engine, int x, int y);
  void part2(const std::vector<std::string> &engine);
}

#endif //ADVENTOFCODE_DAY3_H
