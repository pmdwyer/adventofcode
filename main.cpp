#include <numeric>
#include <iostream>

#include "utils.h"
#include "boulders.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc18-1.txt");
  auto cubes = aoc::make_cubes(lines);
  auto map = aoc::gen_cube_map(cubes);
  std::cout << std::endl << aoc::calc_total_surface_area(map) << std::endl;
  std::cout << std::endl << aoc::calc_actual_surface_area(map) << std::endl;
  return 0;
}
