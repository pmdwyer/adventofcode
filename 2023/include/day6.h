#ifndef AOC23_DAY6_H
#define AOC23_DAY6_H

#include <vector>

namespace aoc
{
  template <class T>
  int count_ways(const std::vector<T> &times, const std::vector<T> &distances)
  {
    int count = 1;
    for (int i = 0; i < times.size(); i++) {
      auto time = times[i];
      auto distance = distances[i];
      int j = 1;
      while (j * (time - j) <= distance) {
        j++;
      }
      auto ways = time - j - j + 1;
      count *= ways;
    }
    return count;
  }

  void day6();
}

#endif //AOC23_DAY6_H
