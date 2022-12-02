#include <iostream>

#include "utils.h"
#include "advent.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc2-1.txt");
  auto rps = aoc::get_rps_rounds(lines);
  std::cout << "basic score = " << aoc::calc_rps_score(rps, aoc::calc_basic_round) << std::endl;
  std::cout << "alt score = " << aoc::calc_rps_score(rps, aoc::calc_alt_round) << std::endl;
  return 0;
}
