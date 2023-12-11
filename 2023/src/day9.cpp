#include "day9.h"

#include <string>
#include <vector>
#include <iostream>

#include "func.h"
#include "str.h"
#include "file.h"

void aoc::day9()
{
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d9-1.txt"));
  std::vector<std::vector<long long>> nums;
  for (const auto& line : lines) {
    auto n = aoc::map<std::string, long long>(
        [](const std::string& s) {
          return std::stoll(s);
        },
        aoc::filter<std::string, std::string>(
            [](const std::string& s) {
              return !s.empty();
            },
            aoc::map<std::string, std::string>(
                aoc::trim,
                aoc::split(" ", line))));
    nums.push_back(n);
  }
  long long next = 0, prev = 0;
  for (const auto& n : nums) {
    auto curr = next_value<long long>(n);
    std::cout << std::get<0>(curr) << ", " << std::get<1>(curr) << std::endl;
    next += std::get<0>(curr);
    prev += std::get<1>(curr);
  }
  std::cout << next << ", " << prev << std::endl;
}
