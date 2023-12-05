#ifndef ADVENTOFCODE_DAY1_H
#define ADVENTOFCODE_DAY1_H

#include <string>

namespace aoc
{
  static constexpr const char* NUMBER_WORDS[9] = {
      "one",
      "two",
      "three",
      "four",
      "five",
      "six",
      "seven",
      "eight",
      "nine"
  };

  int convert(const std::string& s);
  int convert2(const std::string& s);
}

#endif //ADVENTOFCODE_DAY1_H
