#ifndef ADVENTOFCODE_UTILS_H
#define ADVENTOFCODE_UTILS_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

namespace aoc {
  std::vector<std::string> get_lines(const std::string& fname);
  std::vector<std::string> split(const std::string& str);
  std::vector<std::vector<std::string>> split_lines(const std::vector<std::string>& lines);
}

#endif //ADVENTOFCODE_UTILS_H
