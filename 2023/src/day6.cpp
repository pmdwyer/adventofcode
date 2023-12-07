#include "day6.h"

#include <string>
#include <iostream>

#include "func.h"
#include "file.h"
#include "str.h"

void aoc::day6() {
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d6-1.txt"));
  auto times = aoc::get_nums(lines[0]);
  auto distances = aoc::get_nums(lines[1]);
  std::cout << count_ways<int>(times, distances) << std::endl;

  auto temp = aoc::filter<std::string, std::string>([](const std::string& s) { return !s.empty(); }, aoc::split(" ", aoc::trim(aoc::split(":", lines[0])[1])));
  auto temp2 = aoc::filter<std::string, std::string>([](const std::string& s) { return !s.empty(); }, aoc::split(" ", aoc::trim(aoc::split(":", lines[1])[1])));
  auto times2 = std::stoll(aoc::fold<std::string>("", temp));
  auto distances2 = std::stoll(aoc::fold<std::string>("", temp2));
  std::cout << count_ways<long long>({ times2 }, { distances2 }) << std::endl;
}