#ifndef ADVENTOFCODE_STR_H
#define ADVENTOFCODE_STR_H

#include <string>
#include <vector>

namespace aoc
{
  std::vector<std::string> split(const std::string& token, const std::string& str);
  std::string trim(const std::string& str);
}

#endif //ADVENTOFCODE_STR_H
