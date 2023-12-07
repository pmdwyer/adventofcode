#ifndef AOC23_FUNC_H
#define AOC23_FUNC_H

#include <functional>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

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

  template<class T, class V>
  std::vector<V> filter(std::function<bool (const T& t)> f, const std::vector<T> &ts)
  {
    std::vector<V> vs;
    std::copy_if(begin(ts), end(ts), std::back_inserter(vs), f);
    return vs;
  }

  template <class T>
  T fold(T init, const std::vector<T>& ts) {
    for (const auto& t : ts) {
      init += t;
    }
    return init;
  }
}

#endif //AOC23_FUNC_H
