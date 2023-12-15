#include "day14.h"

#include <iostream>

#include "func.h"
#include "str.h"
#include "file.h"

void aoc::day14()
{
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d14-1.txt"));
  lines = transpose(lines);
  auto total_load = 0;
  for (const auto& line : lines) {
    total_load += calc_load(line);
  }
  std::cout << total_load << std::endl;
}

int aoc::calc_load(const std::string& s)
{
  int load = 0;
  int start = 0;
  while (start < s.length()) {
    while (start < s.length() && s[start] == '#') {
      start++;
    }
    auto end = start + 1;
    while (end < s.length() && s[end] != '#') {
      end++;
    }
    auto rocks = 0;
    for (int i = start; i < end && i < s.length(); i++) {
      if (s[i] == 'O') {
        rocks++;
      }
    }
    for (int i = start; i < start + rocks; i++) {
      load += ((int) s.length() - i);
    }
    start = end + 1;
  }
  return load;
}