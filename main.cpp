#include <numeric>
#include <iostream>

#include "utils.h"
#include "advent.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc7-1.txt");
  auto root_fs = aoc::create_dir_tree(lines);
  std::cout << root_fs->calculate_size() << std::endl;
  return 0;
}
