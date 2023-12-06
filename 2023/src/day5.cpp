#include "day5.h"

#include "func.h"
#include "str.h"
#include "file.h"

#include <climits>
#include <iostream>

long aoc::traverse2(const std::vector<long> &seeds, aoc::range_map<long> *pMap)
{
  auto min_loc = LONG_MAX;
  for (int i = 0; i < seeds.size(); i += 2) {
    std::cout << i << std::endl;
    for (long seed = seeds[i]; seed <= seeds[i] + seeds[i + 1]; seed++) {
      auto loc = pMap[0][seed];
      for (int j = 1; j < 7; j++) {
        loc = pMap[j][loc];
      }
      min_loc = (min_loc < loc ? min_loc : loc);
    }
  }
  return min_loc;
}

long aoc::traverse(const std::vector<long> &seeds, aoc::range_map<long> *pMap)
{
  auto min_loc = LONG_MAX;
  for (const auto& seed : seeds) {
    auto loc = pMap[0][seed];
    for (int i = 1; i < 7; i++) {
      loc = pMap[i][loc];
    }
    min_loc = (min_loc < loc ? min_loc : loc);
  }
  return min_loc;
}

void aoc::day5() {
  auto* maps = new aoc::range_map<long>[7];
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d5-1.txt"));
  auto seeds = aoc::map<std::string, long>(
      [](const std::string& s) {
        return std::stol(s);
      },
      aoc::filter<std::string, std::string>(
          [](const std::string& s) {
            return s.length() > 0;
          },
          aoc::map<std::string, std::string>(
              aoc::trim,
              aoc::split(" ", aoc::split(":", lines[0])[1]))));

  int i = 3;
  for (int map_num = 0; map_num < 7; map_num++) {
    while(i < lines.size() && lines[i].length() > 0) {
      auto nums = aoc::map<std::string, std::string>(aoc::trim, aoc::split(" ", lines[i]));
      auto dest = std::stol(nums[0]);
      auto source = std::stol(nums[1]);
      auto range = std::stol(nums[2]);
      maps[map_num].insert(source, dest, range);
      i++;
    }
    i += 2;
  }
  auto min_loc = traverse(seeds, maps);
  std::cout << min_loc << std::endl;
  min_loc = traverse2(seeds, maps);
  std::cout << min_loc << std::endl;
  delete [] maps;
}