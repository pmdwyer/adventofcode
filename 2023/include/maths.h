#ifndef ADVENTOFCODE_MATH_H
#define ADVENTOFCODE_MATH_H

#include <vector>

namespace aoc
{
  int power(int num, int exp);

  template <typename T>
  T gcd(T a, T b)
  {
    while (b > 0) {
      auto t = b;
      b = a % b;
      a = t;
    }
    return a;
  }

  template <typename T>
  T lcm(const std::vector<T>& xs)
  {
    auto d = gcd(xs[0], xs[1]);
    auto l = xs[0] * (xs[1] / d);
    for (int i = 2; i < xs.size(); i++) {
      d = gcd(l, xs[i]);
      l = l * (xs[i] / d);
    }
    return l;
  }
}

#endif //ADVENTOFCODE_MATH_H
