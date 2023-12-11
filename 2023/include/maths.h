#ifndef ADVENTOFCODE_MATH_H
#define ADVENTOFCODE_MATH_H

#include <vector>

namespace aoc
{
  struct point {
    int x, y;

    point& operator=(const point& rhs) = default;
    bool operator==(const struct point& rhs) const { return x == rhs.x && y == rhs.y; }
  };

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

namespace std
{
  template <>
  struct hash<struct aoc::point> {
    size_t operator()(const struct aoc::point& p) const {
      size_t h1 = std::hash<int>{}(p.x);
      size_t h2 = std::hash<int>{}(p.y);
      return h1 ^ (h2 << 1);
    }
  };
}

#endif //ADVENTOFCODE_MATH_H
