#ifndef ADVENTOFCODE_DAY8_H
#define ADVENTOFCODE_DAY8_H

#include <string>
#include <vector>
#include <unordered_map>

namespace aoc
{
  void day8();

  template <class T>
  int get_index(std::vector<T>& indexes, const T& node);

  void follow_path(const std::vector<int> &insts,
                   int start, int finish,
                   std::unordered_map<int, std::array<int, 2>>& nodes);

  void follow_simul_paths(const std::vector<int> &insts,
                          const std::vector<int> &starts,
                          const std::vector<int> &finishes,
                          std::unordered_map<int, std::array<int, 2>> &map);
}

#endif //ADVENTOFCODE_DAY8_H
