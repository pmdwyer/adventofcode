#include <numeric>
#include <iostream>

#include "utils.h"
#include "crt.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc10-1.txt");
  auto insts = aoc::parse_instructions(lines);
  auto output = aoc::execute(insts);
  auto display = aoc::render(output);
  for (const auto& line : display) {
    std::cout << line << std::endl;
  }
  return 0;
}
