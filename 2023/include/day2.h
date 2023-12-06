#ifndef ADVENTOFCODE_DAY2_H
#define ADVENTOFCODE_DAY2_H

namespace aoc
{
  static constexpr int AMOUNTS[3] = {
      12, 13, 14
  };

  struct game {
    int id;
    int r;
    int g;
    int b;
  };

  void day2();
}

#endif //ADVENTOFCODE_DAY2_H
