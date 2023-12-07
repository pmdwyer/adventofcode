#ifndef ADVENTOFCODE_DAY5_H
#define ADVENTOFCODE_DAY5_H

#include <vector>
#include <iostream>

#include "range_map.h"
#include "unordered_range_map.h"

namespace aoc
{
  template <class T>
  T traverse2(const std::vector<T> &seeds, aoc::unordered_range_map<T> *pMap)
  {
    auto min_loc = std::numeric_limits<T>::max();
    for (int i = 0; i < seeds.size(); i += 2) {
      std::cout << i << std::endl;
      for (auto seed = seeds[i]; seed <= seeds[i] + seeds[i + 1]; seed++) {
        auto temp = std::make_tuple(seeds[i], seeds[i] + seeds[i + 1]);
        std::vector<std::tuple<T, T>> rs = pMap[0][temp];
        std::vector<std::tuple<T, T>> nrs;
        for (int i = 1; i < 7; i++) {
          for (const auto &r: rs) {
            auto t = pMap[i][r];
            nrs.insert(nrs.end(), t.begin(), t.end());
          }
          rs = nrs;
          nrs.clear();
        }
        for (const auto& r : rs) {
          min_loc = std::min(std::get<0>(r), min_loc);
          min_loc = std::min(std::get<1>(r), min_loc);
        }
      }
    }
    return min_loc;
  }

  template <class T>
  T traverse(const std::vector<T> &seeds, aoc::unordered_range_map<T> *pMap)
  {
    auto min_loc = std::numeric_limits<T>::max();
    for (const auto& seed : seeds) {
      auto loc = pMap[0][seed];
      for (int i = 1; i < 7; i++) {
        loc = pMap[i][loc];
      }
      min_loc = (min_loc < loc ? min_loc : loc);
    }
    return min_loc;
  }

  void day5();
}

#endif //ADVENTOFCODE_DAY5_H
