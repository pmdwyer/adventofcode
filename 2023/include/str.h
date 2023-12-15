#ifndef ADVENTOFCODE_STR_H
#define ADVENTOFCODE_STR_H

#include <string>
#include <vector>

namespace aoc
{
  std::vector<std::string> split(const std::string& token, const std::string& str);
  std::string trim(const std::string& str);
  std::string remove(const std::string& s, const std::string& cs);
  std::vector<int> get_nums(const std::string &line);
  std::vector<std::string> transpose(const std::vector<std::string>& vs);
}

#endif //ADVENTOFCODE_STR_H
