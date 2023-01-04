#include <iostream>

#include "utils.h"
#include "hill.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc12-1.txt");
  auto start_end = aoc::get_start_and_end(lines);
  auto map = aoc::make_map(lines);
  auto path = aoc::pathfind(start_end, map);
  for (const auto& p : path) {
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
  }
  std::cout << path.size() << std::endl;
  return 0;
}
