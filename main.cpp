#include <numeric>
#include <iostream>

#include "utils.h"
#include "advent.h"

int main()
{
  auto lines = aoc::get_lines("../data/aoc7-1.txt");
  auto root_fs = aoc::create_dir_tree(lines);
  int total = 0;
  root_fs->get_size_when([](int sz){ return sz <= 100000; }, &total);
  std::cout << total << std::endl;

  int unused = 70000000 - root_fs->get_size();
  int needed = 30000000 - unused;
  auto minsz = root_fs->get_smallest_dir(needed);
  std::cout << minsz << std::endl;

  return 0;
}
