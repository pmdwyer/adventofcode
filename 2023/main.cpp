#include <chrono>
#include <string>
#include <iostream>

#include "func.h"
#include "str.h"
#include "file.h"
#include "day5.h"

template <class T>
int count_ways(const std::vector<T> &times, const std::vector<T> &distances)
{
  int count = 1;
  for (int i = 0; i < times.size(); i++) {
    auto time = times[i];
    auto distance = distances[i];
    int j = 1;
    while (j * (time - j) <= distance) {
      j++;
    }
    auto ways = time - j - j + 1;
    count *= ways;
  }
  return count;
}

void day6() {
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d6-1.txt"));
  auto times = aoc::get_nums(lines[0]);
  auto distances = aoc::get_nums(lines[1]);
  std::cout << count_ways<int>(times, distances) << std::endl;

  auto temp = aoc::filter<std::string, std::string>([](const std::string& s) { return s.length() > 0; }, aoc::split(" ", aoc::trim(aoc::split(":", lines[0])[1])));
  auto temp2 = aoc::filter<std::string, std::string>([](const std::string& s) { return s.length() > 0; }, aoc::split(" ", aoc::trim(aoc::split(":", lines[1])[1])));
  auto times2 = std::stol(aoc::fold<std::string>("", temp));
  auto distances2 = std::stol(aoc::fold<std::string>("", temp2));
  std::cout << count_ways<long>({ times2 }, { distances2 }) << std::endl;
}

int main() {
  const auto start = std::chrono::high_resolution_clock::now();
  aoc::day5();
  const auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> dt = end - start;
  std::cout << "time taken: " << dt.count() << std::endl;
  return 0;
}
