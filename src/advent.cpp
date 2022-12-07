#include "advent.h"

std::shared_ptr<aoc::dir> aoc::create_dir_tree(const std::vector<std::string>& lines) {
  std::shared_ptr<dir> root = nullptr, curr = nullptr;
  for (const auto& line : lines) {
    std::stringstream ss(line);
    if (ss.peek() == '$') {
      char carat;
      std::string cmd, dirname;
      ss >> carat >> cmd;
      if (cmd == "cd") {
        ss >> dirname;
        if (root == nullptr) {
          root = std::make_unique<dir>(dirname);
          curr = root;
        }
        if (!curr->get_dir(dirname)) {

        }
      }
    } else if (std::isdigit(ss.peek())) {
      int sz;
      std::string fname;
      ss >> sz >> fname;
      curr->create_file(fname, sz);
    } else if (ss.peek() == 'd') {
      std::string cmd, dirname;
      ss >> cmd >> dirname;
      curr->create_subdir(dirname);
    }
  }
  return root;
}

int aoc::find_large_soh(const std::string& data) {
  int soh = -1;
  std::array<int, 26> hist{};
  for (int i = 0; i < 14; i++) {
    hist[data[i] - 'a']++;
  }
  for (int i = 14; i < data.length(); i++) {
    if (std::ranges::all_of(begin(hist), end(hist), [](int i){ return i <= 1; })) {
      soh = i;
      break;
    }
    hist[data[i - 14] - 'a']--;
    hist[data[i] - 'a']++;
  }
  return soh;
}

int aoc::find_small_soh(const std::string& data) {
  int soh = -1;
  for (int i = 0; i < data.length() - 4; i++) {
    if (data[i] != data[i+1] &&
        data[i] != data[i+2] &&
        data[i] != data[i+3] &&
        data[i+1] != data[i+2] &&
        data[i+1] != data[i+3] &&
        data[i+2] != data[i+3]) {
      soh = i + 4;
      break;
    }
  }
  return soh;
}

std::vector<std::string> aoc::make_crates(const std::vector<std::string>& lines) {
  std::vector<std::string> crates(9, "");
  int index_line = 0;
  for ( ; index_line < lines.size(); index_line++) {
    if (lines[index_line].empty()) {
      break;
    }
  }
  index_line--;
  for (int i = 0; i < index_line; i++) {
    for (int j = 0; j * 4 < lines[i].size(); j++) {
      auto c = lines[i][j * 4 + 1];
      if (!std::isspace(c)) {
        crates[j] += c;
      }
    }
  }
  for (auto& crate : crates) {
    std::reverse(crate.begin(), crate.end());
  }
  return crates;
}

std::vector<std::tuple<int, int, int>> aoc::make_instructions(const std::vector<std::string> &lines) {
  std::vector<std::tuple<int, int, int>> inst;
  int i = 0;
  for ( ; i < lines.size(); i++) {
    if (lines[i].empty()) {
      break;
    }
  }
  for (i++; i < lines.size(); i++) {
    auto words = split(lines[i]);
    inst.emplace_back(std::stoi(words[1]), std::stoi(words[3]) - 1, std::stoi(words[5]) - 1);
  }
  return inst;
}

void aoc::do_instructions(std::vector<std::string>& crates, const std::vector<std::tuple<int, int, int>>& insts) {
  for (const auto& inst : insts) {
    auto amount = std::get<0>(inst);
    auto from = std::get<1>(inst);
    auto to = std::get<2>(inst);
    auto crates_to_move = crates[from].substr(crates[from].length() - amount, amount);
    crates[from].erase(crates[from].length() - amount);
//    std::reverse(crates_to_move.begin(), crates_to_move.end());
    crates[to] += crates_to_move;
  }
}

int aoc::calc_overlapping_ranges(const std::vector<std::vector<int>>& ranges) {
  int overlapping = 0;
  for (const auto& range : ranges) {
    if ((range[0] >= range[2] && range[0] <= range[3]) ||
        (range[2] >= range[0] && range[2] <= range[1])) {
      overlapping++;
    }
  }
  return overlapping;
}

std::vector<std::vector<int>> aoc::create_ranges(const std::vector<std::vector<std::string>>& ranges) {
  std::vector<std::vector<int>> results;
  for (const auto& r : ranges) {
    std::vector<int> current_ranges;
    auto first = split_on(r[0], '-');
    auto second = split_on(r[1], '-');
    current_ranges.push_back(std::stoi(first[0]));
    current_ranges.push_back(std::stoi(first[1]));
    current_ranges.push_back(std::stoi(second[0]));
    current_ranges.push_back(std::stoi(second[1]));
    results.push_back(current_ranges);
  }
  return results;
}

std::vector<char> aoc::get_badges(const std::vector<std::string>& rucksacks) {
  std::vector<char> badges;
  for (int group = 0; group < rucksacks.size() / 3; group++) {
    int i = group * 3;
    std::vector<char> first_two;
    std::set<char> first_items(rucksacks[i].begin(), rucksacks[i].end());
    std::set<char> second_items(rucksacks[i + 1].begin(), rucksacks[i + 1].end());
    std::set<char> third_items(rucksacks[i + 2].begin(), rucksacks[i + 2].end());

    std::set_intersection(first_items.begin(), first_items.end(),
                          second_items.begin(), second_items.end(),
                          std::back_inserter(first_two));

    std::set_intersection(first_two.begin(), first_two.end(),
                          third_items.begin(), third_items.end(),
                          std::back_inserter(badges));
  }
  return badges;
}

std::vector<int> aoc::get_priorites(const std::vector<char>& cs) {
  std::vector<int> ords;
  std::transform(cs.begin(), cs.end(), std::back_inserter(ords), [](char c) {
    return isupper(c) ? (c - '@' + 26) : (c - '`');
  });
  return ords;
}

std::vector<char> aoc::get_common_items(const std::vector<std::string>& rucksacks) {
  std::vector<char> common;
  for (const auto& rucksack : rucksacks) {
    auto first_comp = rucksack.substr(0, rucksack.length() / 2);
    auto second_comp = rucksack.substr(rucksack.length() / 2, rucksack.length() / 2);
    std::set<char> first_items(first_comp.begin(), first_comp.end());
    std::set<char> second_items(second_comp.begin(), second_comp.end());
    std::set_intersection(first_items.begin(), first_items.end(),
                          second_items.begin(), second_items.end(),
                          std::back_inserter(common));
  }
  return common;
}

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