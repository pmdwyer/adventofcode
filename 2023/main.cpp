#include <iostream>

#include "file.h"
#include "func.h"

static constexpr const char* NUMBER_WORDS[9] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int convert(const std::string& s) {
  int first = -1, last = -1;
  for (size_t i = 0, j = s.length() - 1; i < s.length() && j >= 0 && (first < 0 || last < 0); i++, j--) {
    if (first < 0 && isdigit(s[i])) {
      first = 10 * (s[i] - '0');
    }
    if (last < 0 && isdigit(s[j])) {
      last = s[j] - '0';
    }
  }
  return first + last;
}

int convert2(const std::string& s) {
  int findex = -1, lindex = -1;
  int first = -1, last = -1;
  for (size_t i = 0, j = s.length() - 1; i < s.length() && j >= 0 && (findex < 0 || lindex < 0); i++, j--) {
    if (findex < 0 && isdigit(s[i])) {
      findex = (int) i;
      first = 10 * (s[i] - '0');
    }
    if (lindex < 0 && isdigit(s[j])) {
      lindex = (int) j;
      last = s[j] - '0';
    }
  }
  int min_idx = s.length(), max_idx = 0;
  int min_num = 0, max_num = 0;
  for (int i = 0; i < 9; i++) {
    auto fidx = s.find(NUMBER_WORDS[i]);
    if (fidx != std::string::npos && fidx < min_idx) {
      min_idx = (int) fidx;
      min_num = 10 * (i + 1);
    }
    auto lidx = s.rfind(NUMBER_WORDS[i]);
    if (lidx != std::string::npos && lidx > max_idx) {
      max_idx = (int) lidx;
      max_num = i + 1;
    }
  }
  if (min_idx < findex) {
    first = min_num;
  }
  if (max_idx > lindex) {
    last = max_num;
  }
  return first + last;
}

int main()
{
  auto lines = aoc::get_lines("../../2023/input/d1-1.txt");
  auto nums = aoc::map<std::string, int>(lines, convert2);
  for (const auto& num : nums) {
    std::cout << num << std::endl;
  }
  std::cout << aoc::sum(nums) << std::endl;
  return 0;
}
