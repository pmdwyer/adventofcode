#include "file.h"

#include <fstream>

std::vector<std::string> aoc::get_lines(const std::string& fname) {
  std::vector<std::string> lines;

  std::ifstream in_file(fname);
  while(!in_file.eof()) {
    std::string line;
    getline(in_file, line);
    lines.push_back(line);
  }

  return lines;
}