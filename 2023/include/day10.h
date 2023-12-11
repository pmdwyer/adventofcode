#ifndef AOC23_DAY10_H
#define AOC23_DAY10_H

#include <vector>
#include <string>
#include <unordered_set>

namespace aoc
{
  enum class PipeType {
    Unknown,
    Vert,
    Hori,
    L,
    J,
    Seven,
    F,
    Empty
  };

  struct pipe {
    pipe() = default;

    bool operator==(const struct pipe& rhs) const {
      return (x == rhs.x && y == rhs.y);
    }

    PipeType type;
    int x;
    int  y;
  };

  void day10();
  std::unordered_set<struct pipe> count_pipes(const std::vector<std::string>& map, struct pipe& node);
  struct pipe make_pipe(const std::vector<std::string>& map, int x, int y);
  bool in_bounds(const std::vector<std::string>& map, int x, int y);
  bool is_open_right(const std::vector<std::string>& map, int x, int y);
  bool is_open_left(const std::vector<std::string>& map, int x, int y);
  bool is_open_top(const std::vector<std::string>& map, int x, int y);
  bool is_open_bottom(const std::vector<std::string>& map, int x, int y);
  PipeType find_s_type(const std::vector<std::string> &lines, int x, int y);
  char get_char(PipeType type);
}

namespace std
{
  template <>
  struct hash<aoc::pipe> {
    size_t operator () (const aoc::pipe &p) const {
      std::size_t h1 = std::hash<int>{}(p.x);
      std::size_t h2 = std::hash<int>{}(p.y);
      return h1 ^ (h2 << 1);
    }
  };
}

#endif //AOC23_DAY10_H
