#include "advent.h"

int aoc::calc_basic_round(int you, int them) {
  int score = you;
  if (you == them) {
    score += 3;
  }
  if ((you == RPS::Rock && them == RPS::Scissors) ||
      (you == RPS::Paper && them == RPS::Rock) ||
      (you == RPS::Scissors && them == RPS::Paper)) {
    score += 6;
  }
  return score;
}

int aoc::calc_alt_round(int you, int them) {
  int score = 0;
  if (you == Strat::Draw) {
    score += 3 + them;
  } else if (you == Strat::Win) {
    score += 6;
    if (them == RPS::Rock) {
      score += RPS::Paper;
    } else if (them == RPS::Paper) {
      score += RPS::Scissors;
    } else {
      score += RPS::Rock;
    }
  } else {
    if (them == RPS::Rock) {
      score += RPS::Scissors;
    } else if (them == RPS::Paper) {
      score += RPS::Rock;
    } else {
      score += RPS::Paper;
    }
  }
  return score;
}

int aoc::calc_rps_score(const std::vector<std::tuple<int, int>>& rps, const std::function<int(int, int)>& calc) {
  int score = 0;
  for (const auto& round : rps) {
    int them = get<0>(round);
    int you = get<1>(round);
    score += calc(you, them);
  }
  return score;
}

std::vector<std::tuple<int, int>> aoc::get_rps_rounds(const std::vector<std::string>& lines) {
  auto rps = split_lines(lines);
  std::vector<std::tuple<int, int>> rounds;
  for (const auto& round : rps) {
    rounds.emplace_back((round[0][0] - '@'), (round[1][0] - 'W'));
  }
  return rounds;
}

std::vector<int> aoc::get_elf_calories(const std::vector<std::string>& calories) {
  std::vector<int> elf_calories((int) calories.size(), 0);
  int elf = 0;
  for (const auto& calorie : calories) {
    if (calorie.empty()) {
      elf++;
    } else {
      elf_calories[elf] += std::stoi(calorie);
    }
  }
  return elf_calories;
}

std::tuple<int, int> aoc::get_max_elf_calories(const std::vector<std::string>& calories) {
  auto cs = get_elf_calories(calories);
  auto result = std::max_element(cs.begin(), cs.end());
  int max_elf = (int) std::distance(cs.begin(), result);
  int max_calories = *result;
  return std::make_tuple(max_elf, max_calories);
}