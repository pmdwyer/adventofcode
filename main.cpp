#include <numeric>
#include <iostream>

#include "utils.h"
#include "advent.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc5-1.txt");
  auto crates = aoc::make_crates(lines);
  for (const auto& crate : crates) {
    std::cout << crate << std::endl;
  }
  std::cout << std::endl;
  auto instructions = aoc::make_instructions(lines);
  aoc::do_instructions(crates, instructions);
  for (const auto& crate : crates) {
    std::cout << crate << std::endl;
  }
  return 0;
}
