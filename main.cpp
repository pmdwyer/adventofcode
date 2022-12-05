#include <numeric>
#include <iostream>

#include "utils.h"
#include "advent.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc4-1.txt");
  auto splits = aoc::split_lines_on(lines, ',');
  auto ranges = aoc::create_ranges(splits);
  std::cout << aoc::calc_overlapping_ranges(ranges) << std::endl;
  return 0;
}
