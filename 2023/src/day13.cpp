#include "day13.h"

#include <string>
#include <iostream>

#include "func.h"
#include "str.h"
#include "file.h"

void aoc::day13()
{
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d13-1.txt"));
  mirror_math(lines);
  mirror_math2(lines);
}

void aoc::mirror_math2(const std::vector<std::string> &lines)
{
  std::vector<std::string> input;
  auto start = 0, sum = 0;
  while (start < lines.size()) {
    auto end = start + 1;
    while (!lines[end].empty() && end < lines.size()) {
      end++;
    }
    input.insert(input.begin(), lines.begin() + start, lines.begin() + end);

    std::unordered_map<int, std::vector<int>> total_mismatches;
    for (int i = 1; i < input[0].length(); i++) {
      auto curr_mismatches = 0;
      for (const auto& line : input) {
        curr_mismatches += count_mismatches(line, i - 1, i);
      }
      total_mismatches[curr_mismatches].push_back(i);
    }
    if (total_mismatches.contains(1)) {
      sum += total_mismatches[1][0];
    }
    total_mismatches.clear();
    input = transpose(input);
    for (int i = 1; i < input[0].length(); i++) {
      auto curr_mismatches = 0;
      for (const auto& line : input) {
        curr_mismatches += count_mismatches(line, i - 1, i);
      }
      total_mismatches[curr_mismatches].push_back(i);
    }
    if (total_mismatches.contains(1)) {
      sum += (total_mismatches[1][0] * 100);
    }
    input.clear();
    start = end + 1;
  }
  std::cout << sum << std::endl;
}

int aoc::count_mismatches(const std::string& line, int start, int mid)
{
  int count = 0;
  while (start >= 0 && mid < line.length()) {
    if (line[start] != line[mid]) {
      count++;
    }
    start--;
    mid++;
  }
  return count;
}

void aoc::mirror_math(const std::vector<std::string> &lines)
{
  int start = 0, sum = 0;
  std::vector<std::string> input;
  while (start < lines.size()) {
    auto end = start + 1;
    while (!lines[end].empty() && end < lines.size()) {
      end++;
    }
    input.insert(input.begin(), lines.begin() + start, lines.begin() + end);
    auto indexes = find_indexes(input[0]);
    for (const auto& index : indexes) {
      if (std::all_of(input.begin(), input.end(), [=](const std::string& s) { return is_palindrome(s, index - 1, index); })) {
        sum += index;
      }
    }
    input = transpose(input);
    indexes = find_indexes(input[0]);
    for (const auto& index : indexes) {
      if (std::all_of(input.begin(), input.end(), [=](const std::string& s) { return is_palindrome(s, index - 1, index); })) {
        sum += index * 100;
      }
    }
    input.clear();
    start = end + 1;
  }
  std::cout << sum << std::endl;
}

std::vector<int> aoc::find_indexes(const std::string& line)
{
  std::vector<int> indexes;
  for (int i = 1; i < line.length(); i++) {
    if (is_palindrome(line, i - 1, i)) {
      indexes.push_back(i);
    }
  }
  return indexes;
}

bool aoc::is_palindrome(const std::string &line, int start, int mid)
{
  while (start >= 0 && mid < line.length()) {
    if (line[start] != line[mid]) {
      return false;
    }
    start--;
    mid++;
  }
  return true;
}
