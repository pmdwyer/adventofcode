#ifndef ADVENTOFCODE_DAY13_H
#define ADVENTOFCODE_DAY13_H

#include <vector>
#include <string>

namespace aoc
{
  void day13();
  void mirror_math(const std::vector<std::string> &lines);
  std::vector<int> find_indexes(const std::string& line);
  bool is_palindrome(const std::string& line, int start, int mid);

  void mirror_math2(const std::vector<std::string>& lines);
  int count_mismatches(const std::string& line, int start, int mid);
}

#endif //ADVENTOFCODE_DAY13_H
