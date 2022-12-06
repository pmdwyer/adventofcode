#include <numeric>
#include <iostream>

#include "utils.h"
#include "advent.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc6-1.txt");
  auto line = lines[0];
  std::cout << aoc::find_small_soh(line) << std::endl;
  std::cout << aoc::find_large_soh(line) << std::endl;
  return 0;
}
