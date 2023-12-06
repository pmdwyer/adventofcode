#ifndef ADVENTOFCODE_DAY5_H
#define ADVENTOFCODE_DAY5_H

#include <vector>

#include "range_map.h"

namespace aoc
{
  long traverse2(const std::vector<long> &seeds, aoc::range_map<long> *pMap);
  long traverse(const std::vector<long> &seeds, aoc::range_map<long> *pMap);
  void day5();
}

#endif //ADVENTOFCODE_DAY5_H
