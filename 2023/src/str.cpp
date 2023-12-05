#include "str.h"

std::vector<std::string> aoc::split(const std::string& token, const std::string& str) {
  std::vector<std::string> words;
  size_t from = 0, to;
  while ((to = str.find(token, from)) != std::string::npos) {
    words.push_back(str.substr(from, (to - from)));
    from = to + token.length();
  }
  words.push_back(str.substr(from));
  return words;
}

std::string aoc::trim(const std::string& str) {
  std::string res(str);
  res.erase(res.begin(), std::find_if(res.begin(), res.end(), [](unsigned char c) { return !std::isspace(c); }));
  res.erase(std::find_if(res.rbegin(), res.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), res.end());
  return res;
}