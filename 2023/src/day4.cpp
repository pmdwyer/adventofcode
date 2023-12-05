#include "day4.h"

#include <iostream>
#include <string>

#include "func.h"
#include "str.h"
#include "file.h"
#include "math.h"

std::vector<std::vector<std::vector<int>>> aoc::parse_input() {
  int i = 0;
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d4-1.txt"));
  std::vector<std::vector<std::vector<int>>> cards(lines.size(), std::vector<std::vector<int>>(2));
  for (const auto& line : lines) {
    auto card_nums = aoc::split(":", line);
    auto num_lines = aoc::split("|", card_nums[1]);
    auto winning_nums = aoc::split(" ", aoc::trim(num_lines[0]));
    auto your_nums = aoc::split(" ", aoc::trim(num_lines[1]));
    for (const auto& num : winning_nums) {
      if (num.length() == 0) {
        continue;
      }
      cards[i][0].push_back(std::stoi(aoc::trim(num)));
    }
    sort(cards[i][0].begin(), cards[i][0].end());
    for (const auto& num : your_nums) {
      if (num.length() == 0) {
        continue;
      }
      cards[i][1].push_back(std::stoi(aoc::trim(num)));
    }
    sort(cards[i][1].begin(), cards[i][1].end());
    i++;
  }
  return cards;
}

int aoc::count_matches(const std::vector<std::vector<int>>& card) {
  int i = 0, j = 0, matches = 0;
  while (i < card[0].size() && j < card[1].size()) {
    if (card[0][i] == card[1][j]) {
      matches++;
      i++;
      j++;
    } else if (card[0][i] < card[1][j]) {
      i++;
    } else {
      j++;
    }
  }
  return matches;
}

void aoc::part1(const std::vector<std::vector<std::vector<int>>>& input) {
  auto points = 0;
  for (const auto& card : input) {
    auto num_matches = count_matches(card);
    if (num_matches > 0) {
      points += aoc::power(2, num_matches - 1);
    }
  }
  std::cout << points << std::endl;
}

void aoc::part2(const std::vector<std::vector<std::vector<int>>>& input) {
  std::vector<int> counts(input.size(), 1);
  int cards = 0;
  for (int i = 0; i < input.size(); i++) {
    auto matches = count_matches(input[i]);
    for (int j = 1; j <= matches && i + j < input.size(); j++) {
      counts[i + j] += counts[i];
    }
    cards += counts[i];
  }
  std::cout << cards << std::endl;
}