#include "../include/utils.h"

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
  return split_on(str, ' ');
}

std::vector<std::string> aoc::split_on(const std::string& str, char delimiter) {
  std::stringstream ss(str);
  std::vector<std::string> tokens;
  std::string token;
  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

std::vector<std::vector<std::string>> aoc::split_lines(const std::vector<std::string>& lines) {
  return split_lines_on(lines, ' ');
}

std::vector<std::vector<std::string>> aoc::split_lines_on(const std::vector<std::string>& lines, char delimiter) {
  std::vector<std::vector<std::string>> line_splits;
  for (const auto& line : lines) {
    line_splits.push_back(split_on(line, delimiter));
  }
  return line_splits;
}
