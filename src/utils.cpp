#include "utils.h"

std::vector<std::string> aoc::get_lines(const std::string& fname) {
  std::vector<std::string> lines;
  std::ifstream file(fname);
  while (!file.fail()) {
    std::string line;
    std::getline(file, line);
    if (!file.fail()) {
      lines.push_back(line);
    }
  }
  return lines;
}

std::vector<std::string> aoc::split(const std::string& str) {
  std::stringstream ss(str);
  std::vector<std::string> splits;
  while (!ss.fail()) {
    std::string s;
    ss >> s;
    splits.push_back(s);
  }
  return splits;
}

std::vector<std::vector<std::string>> aoc::split_lines(const std::vector<std::string>& lines) {
  std::vector<std::vector<std::string>> line_splits;
  for (const auto& line : lines) {
    line_splits.push_back(split(line));
  }
  return line_splits;
}
