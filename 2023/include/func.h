#ifndef AOC23_FUNC_H
#define AOC23_FUNC_H

#include <functional>
#include <numeric>
#include <vector>

namespace aoc
{
  template<class T, class V>
  std::vector<V> map(std::function<V(const T &t)> f, const std::vector<T> &ts)
  {
    std::vector<V> vs(ts.size());
    std::transform(begin(ts), end(ts), begin(vs), f);
    return vs;
  }

  template<class T>
  int sum(const std::vector<T> &ts)
  {
    return std::accumulate(begin(ts), end(ts), 0);
  }
}

#endif //AOC23_FUNC_H
