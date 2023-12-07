#ifndef ADVENTOFCODE_DAY7_H
#define ADVENTOFCODE_DAY7_H

#include <string>

namespace aoc
{
  enum class CamelHandType {
    HighCard,
    Pair,
    TwoPair,
    Three,
    Full,
    Four,
    Five
  };

  struct camel_hand {
    CamelHandType type;
    std::string cards;
    int bid;
  };

  bool hand_comp(const struct camel_hand& h1, const struct camel_hand& h2);
  CamelHandType elevate(const int counts[6], int jokers);
  CamelHandType rank_hand(const std::string& cards);
  int card_value(char c);
  void day7();
}

#endif //ADVENTOFCODE_DAY7_H
