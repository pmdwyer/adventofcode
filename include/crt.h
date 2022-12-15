#ifndef ADVENTOFCODE_CRT_H
#define ADVENTOFCODE_CRT_H

#include <string>
#include <vector>

#include "utils.h"

namespace aoc {
  enum InstType {
    Noop,
    Add
  };

  struct Inst {
    InstType type;
    int x;
  };

  using inst = struct Inst;

  std::vector<inst> parse_instructions(const std::vector<std::string>& lines);
  std::vector<std::tuple<int, int>> execute(const std::vector<inst>& insts);
  std::vector<std::string> render(const std::vector<std::tuple<int, int>>& cpu_states);
}

#endif //ADVENTOFCODE_CRT_H
