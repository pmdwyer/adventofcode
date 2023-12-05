#include <iostream>
#include "day3.h"

bool aoc::symbol(const char& c) {
  return !std::isdigit(c) && c != '.';
}

bool aoc::is_part(const std::vector<std::string>& parts, int x, int start, int end)
{
  auto startx = std::max(x - 1, 0);
  auto endx = std::min(x + 2, (int) parts.size());
  auto starty = std::max(start - 1, 0);
  auto endy = std::min(end + 1, (int) parts[x].size());

  for (int i = startx; i < endx; i++) {
    for (int j = starty; j < endy; j++) {
      if (symbol(parts[i][j])) {
        std::cout << parts[i][j];
        return true;
      }
    }
  }
  return false;
}

int aoc::process(const std::vector<std::string>& parts, int i, int& j)
{
  int part_num = 0, col_start = j, col_end = j;

  while (std::isdigit(parts[i][col_end])) {
    col_end++;
  }
  auto part_num_str = parts[i].substr(col_start, col_end - col_start);
  std::cout << "(" << i << ", " << j << ")\t" << part_num_str << "\t";
  auto temp = std::stoi(part_num_str);
  if (is_part(parts, i, col_start, col_end)) {
    part_num = temp;
  }
  std::cout << std::endl;
  j = col_end - 1;
  return part_num;
}

void aoc::part1(const std::vector<std::string> &engine) {
  int part_sum = 0;
  for (int i = 0; i < engine.size(); i++) {
    for (int j = 0; j < engine[i].size(); j++) {
      if (std::isdigit(engine[i][j])) {
        part_sum += process(engine, i, j);
      }
    }
  }
  std::cout << part_sum << std::endl;
}

int aoc::expand(const std::vector<std::string> &engine, int i, int& j)
{
  int start = j, end = j;
  while (start >= 0 && std::isdigit(engine[i][start])) {
    start--;
  }
  start++;
  while (end < engine[i].size() && std::isdigit(engine[i][end])) {
    end++;
  }
  auto num_str = engine[i].substr(start, end - start);
  auto num = std::stoi(num_str);
  j = end - 1;
  return num;
}

int aoc::calc_ratio(const std::vector<std::string> &engine, int x, int y)
{
  int ratio = 0;
  auto startx = std::max(x - 1, 0);
  auto endx = std::min(x + 2, (int) engine.size());
  auto starty = std::max(y - 1, 0);
  auto endy = std::min(y + 2, (int) engine[x].size());

  int list[9];
  int numnums = 0;
  for (int i = startx; i < endx; i++) {
    for (int j = starty; j < endy; j++) {
      if (std::isdigit(engine[i][j])) {
        list[numnums++] = expand(engine, i, j);
      }
    }
  }

  if (numnums == 2) {
    ratio = list[0] * list[1];
  }
  return ratio;
}

void aoc::part2(const std::vector<std::string> &engine) {
  auto sum = 0;
  for (int i = 0; i < engine.size(); i++) {
    for (int j = 0; j < engine[i].size(); j++) {
      if (engine[i][j] == '*') {
        sum += calc_ratio(engine, i, j);
      }
    }
  }
  std::cout << sum << std::endl;
}
