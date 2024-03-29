#include "str.h"
#include "func.h"

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

std::vector<int> aoc::get_nums(const std::string &line) {
  return aoc::map<std::string, int>(
      [](const std::string& s) {
        return std::stoi(s);
      },
      aoc::filter<std::string, std::string>(
          [](const std::string& s) {
            return s.length() > 0;
          },
          aoc::map<std::string, std::string>(
              aoc::trim,
              aoc::split(" ", aoc::split(":", line)[1]))));
}

std::string aoc::remove(const std::string &s, const std::string &cs)
{
  auto res(s);
  res.erase(std::remove_if(res.begin(), res.end(), [&](char c) { return cs.find_first_of(c) != std::string::npos; }), res.end());
  return res;
}

std::vector<std::string> aoc::transpose(const std::vector<std::string>& vs)
{
  std::vector<std::string> ts;
  for (int i = 0; i < vs[0].length(); i++) {
    std::string temp;
    for (int j = 0; j < vs.size(); j++) {
      temp += vs[j][i];
    }
    ts.push_back(temp);
  }
  return ts;
}
