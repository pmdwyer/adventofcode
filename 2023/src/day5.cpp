#include "day5.h"

#include <iostream>

#include "func.h"
#include "str.h"
#include "file.h"
#include "unordered_range_map.h"

void aoc::day5() {
  aoc::unordered_range_map<unsigned long long> maps[7];
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d5-1.txt"));
  auto seeds = aoc::map<std::string, unsigned long long>(
      [](const std::string& s) {
        return std::stoll(s);
      },
      aoc::filter<std::string, std::string>(
          [](const std::string& s) {
            return !s.empty();
          },
          aoc::map<std::string, std::string>(
              aoc::trim,
              aoc::split(" ", aoc::split(":", lines[0])[1]))));

  int i = 3;
  for (int map_num = 0; map_num < 7; map_num++) {
    while(i < lines.size() && !lines[i].empty()) {
      auto nums = aoc::map<std::string, std::string>(aoc::trim, aoc::split(" ", lines[i]));
      auto dest = std::stoll(nums[0]);
      auto source = std::stoll(nums[1]);
      auto range = std::stoll(nums[2]);
      maps[map_num].insert(source, dest, range);
      i++;
    }
    i += 2;
  }
  auto min_loc = traverse<unsigned long long>(seeds, maps);
  std::cout << min_loc << std::endl;
  min_loc = traverse2<unsigned long long>(seeds, maps);
  std::cout << min_loc << std::endl;
}