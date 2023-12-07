#include "day7.h"

#include <string>
#include <iostream>

#include "func.h"
#include "str.h"
#include "file.h"

void aoc::day7()
{
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d7-1.txt"));
  std::vector<struct camel_hand> hands;
  for (const auto& line : lines) {
    auto words = aoc::split(" ", line);
    auto hand = aoc::trim(words[0]);
    auto bid = std::stoi(aoc::trim(words[1]));
    hands.push_back({ rank_hand(hand), hand, bid });
  }
  std::sort(begin(hands), end(hands), hand_comp);
  auto winnings = 0;
  for (int i = 0; i < hands.size(); i++) {
    winnings += ((i + 1) * hands[i].bid);
  }
  std::cout << winnings << std::endl;
}

bool aoc::hand_comp(const struct camel_hand& h1, const struct camel_hand& h2)
{
  if (h1.type == h2.type) {
    int i = 0;
    while (i < h1.cards.length() && h1.cards[i] == h2.cards[i]) {
      i++;
    }
    return card_value(h1.cards[i]) < card_value(h2.cards[i]);
  }
  return h1.type < h2.type;
}

aoc::CamelHandType aoc::elevate(const int counts[6], int jokers)
{
  auto type = CamelHandType::HighCard;
  if (counts[5] > 0) {
    type = CamelHandType::Five;
  } else if (counts[4] > 0) {
    type = CamelHandType::Four;
  } else if (counts[3] == 1 && counts[2] == 1) {
    type = CamelHandType::Full;
  } else if (counts[3] > 0) {
    type = CamelHandType::Three;
  } else if (counts[2] == 2) {
    type = CamelHandType::TwoPair;
  } else if (counts[2] == 1) {
    type = CamelHandType::Pair;
  }
  switch (jokers) {
    case 1:
      if (type == CamelHandType::HighCard) {
        type = CamelHandType::Pair;
      } else if (type == CamelHandType::Pair) {
        type = CamelHandType::Three;
      } else if (type == CamelHandType::TwoPair) {
        type = CamelHandType::Full;
      } else if (type == CamelHandType::Three) {
        type = CamelHandType::Four;
      } else if (type == CamelHandType::Four) {
        type = CamelHandType::Five;
      }
      break;
    case 2:
      if (type == CamelHandType::Pair) {
        type = CamelHandType::Three;
      } else if (type == CamelHandType::TwoPair) {
        type = CamelHandType::Four;
      } else if (type == CamelHandType::Full) {
        type = CamelHandType::Five;
      }
      break;
    case 3:
      if (type == CamelHandType::Three) {
        type = CamelHandType::Four;
      } else if (type == CamelHandType::Full) {
        type = CamelHandType::Five;
      }
      break;
    case 4:
      type = CamelHandType::Five;
      break;
    default:
      break;
  }
  return type;
}

aoc::CamelHandType aoc::rank_hand(const std::string& cards)
{
  int values[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  for (const auto& c : cards) {
    values[card_value(c)]++;
  }
  int counts[6] = {0,0,0,0,0,0};
  for (int value : values) {
    counts[value]++;
  }
  return elevate(counts, values[0]);
}

int aoc::card_value(const char c)
{
  switch (c) {
    case 'J':
      return 0;
    case '2':
      return 1;
    case '3':
      return 2;
    case '4':
      return 3;
    case '5':
      return 4;
    case '6':
      return 5;
    case '7':
      return 6;
    case '8':
      return 7;
    case '9':
      return 8;
    case 'T':
      return 9;
    case 'Q':
      return 10;
    case 'K':
      return 11;
    case 'A':
      return 12;
    default:
      return -1;
  }
  return -1;
}