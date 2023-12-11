#ifndef AOC23_DAY11_H
#define AOC23_DAY11_H

#include <vector>
#include <algorithm>
#include <string>

#include "maths.h"

namespace aoc
{
  void day11();
  void expand_rows(std::vector<std::string>& vs);
  std::vector<std::string> transpose(const std::vector<std::string>& vs);
  std::vector<struct point> find_galaxies(const std::vector<std::string>& vs);
  std::vector<struct point> a_star(const std::vector<std::string>& map, const struct point& start, const struct point& finish);
  std::vector<struct point> get_neighbors(const struct point &point, int maxx, int maxy);
}

#endif //AOC23_DAY11_H
