#include <numeric>
#include <iostream>

#include "utils.h"
#include "advent.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc3-1.txt");
  auto badges = aoc::get_badges(lines);
  auto priorities = aoc::get_priorites(badges);
  std::cout << std::accumulate(priorities.begin(), priorities.end(), 0) << std::endl;
  return 0;
}
