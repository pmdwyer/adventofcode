#include <numeric>
#include <iostream>

#include "utils.h"
#include "advent.h"
#include "grid.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc8-1.txt");
  aoc::grid g(lines);
  std::cout << g.calc_visible_trees() << std::endl;
  return 0;
}
