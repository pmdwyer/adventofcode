#ifndef ADVENTOFCODE_UTILS_H
#define ADVENTOFCODE_UTILS_H

#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

namespace aoc {
  std::vector<std::string> get_lines(const std::string& fname);
  std::vector<std::string> split(const std::string& str);
  std::vector<std::string> split_on(const std::string& str, char delimiter);
  std::vector<std::vector<std::string>> split_lines(const std::vector<std::string>& lines);
  std::vector<std::vector<std::string>> split_lines_on(const std::vector<std::string>& lines, char delimiter);
}

#endif //ADVENTOFCODE_UTILS_H
