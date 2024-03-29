#ifndef ADVENTOFCODE_ADVENT_H
#define ADVENTOFCODE_ADVENT_H

#include <algorithm>
#include <array>
#include <functional>
#include <ranges>
#include <set>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "utils.h"
#include "fs.h"

namespace aoc {
  std::shared_ptr<aoc::dir> create_dir_tree(const std::vector<std::string>& lines);
  int find_large_soh(const std::string& data);
  int find_small_soh(const std::string& data);
  std::vector<std::string> make_crates(const std::vector<std::string>& lines);
  std::vector<std::tuple<int, int, int>> make_instructions(const std::vector<std::string>& lines);
  void do_instructions(std::vector<std::string>& crates, const std::vector<std::tuple<int, int, int>>& insts);
  int calc_overlapping_ranges(const std::vector<std::vector<int>>& ranges);
  std::vector<std::vector<int>> create_ranges(const std::vector<std::vector<std::string>>& ranges);
  std::vector<char> get_badges(const std::vector<std::string>& rucksacks);
  std::vector<int> get_priorites(const std::vector<char>& cs);
  std::vector<char> get_common_items(const std::vector<std::string>& rucksacks);
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
