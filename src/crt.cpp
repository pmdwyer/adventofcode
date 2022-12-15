#include "crt.h"

std::vector<aoc::inst> aoc::parse_instructions(const std::vector<std::string>& lines) {
  std::vector<inst> insts;
  for (const auto& line : lines) {
    switch (line[0]) {
      case 'n':
        insts.emplace_back(InstType::Noop, 0);
        break;
      case 'a':
        int x = std::stoi(split(line)[1]);
        insts.emplace_back(InstType::Add, x);
    }
  }
  return insts;
}

std::vector<std::tuple<int, int>> aoc::execute(const std::vector<inst>& insts) {
  int reg_x = 1;
  int cycle = 1;
  std::vector<std::tuple<int, int>> output;
  output.emplace_back(0, 1);
  for (const auto& i : insts) {
    switch (i.type) {
      case Noop:
        output.emplace_back(cycle++, reg_x);
        break;
      case Add:
        output.emplace_back(cycle++, reg_x);
        reg_x += i.x;
        output.emplace_back(cycle++, reg_x);
        break;
    }
  }
  return output;
}

std::vector<std::string> aoc::render(const std::vector<std::tuple<int, int>>& cpu_states) {
  std::vector<std::string> crt{6, std::string(40, '.')};
  for (int i = 0; i < crt.size(); i++) {
    for (int j = 0; j < crt[i].size(); j++) {
      auto idx = i * crt[0].size() + j;
      auto pix = std::get<1>(cpu_states[idx]);
      if (j >= pix - 1 && j <= pix + 1) {
        crt[i][j] = '#';
      }
    }
  }
  return crt;
}