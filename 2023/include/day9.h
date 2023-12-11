#ifndef AOC23_DAY9_H
#define AOC23_DAY9_H

#include <vector>
#include <algorithm>
#include <tuple>

namespace aoc
{
  void day9();

  template <typename T>
  std::tuple<T, T> next_value(const std::vector<T> &vs)
  {
    std::vector<std::vector<T>> levels;
    levels.push_back(vs);
    std::vector<T> curr{vs}, next;
    while (!std::all_of(begin(curr), end(curr), [](T i) { return i == 0; })) {
      for (int i = 0; i < curr.size() - 1; i++) {
        next.push_back(curr[i + 1] - curr[i]);
      }
      levels.push_back(next);
      curr = next;
      next.clear();
    }
    T v = 0, p = 0;
    for (const auto& level : levels) {
      v += level[level.size() - 1];
      p = level[0] - p;
    }
    return std::make_tuple<>(v, p);
  }
}

#endif //AOC23_DAY9_H
