//
// Created by pdwyer on 12/1/2022.
//

#ifndef ADVENTOFCODE_ADVENT_H
#define ADVENTOFCODE_ADVENT_H

#include <algorithm>
#include <functional>
#include <string>
#include <tuple>
#include <vector>

#include "utils.h"

namespace aoc {
  int calc_basic_round(int you, int them);
  int calc_alt_round(int you, int them);
  int calc_rps_score(const std::vector<std::tuple<int, int>>& rps, const std::function<int(int, int)>& calc);
  std::vector<std::tuple<int, int>> get_rps_rounds(const std::vector<std::string>& lines);
  std::vector<int> get_elf_calories(const std::vector<std::string>& calories);
  std::tuple<int, int> get_max_elf_calories(const std::vector<std::string>& calories);

  enum RPS {
    Rock = 1,
    Paper = 2,
    Scissors = 3
  };

  enum Strat {
    Lose = 1,
    Draw = 2,
    Win = 3
  };
}

#endif //ADVENTOFCODE_ADVENT_H
