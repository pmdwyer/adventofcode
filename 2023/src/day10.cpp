#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include "day10.h"

#include "func.h"
#include "str.h"
#include "file.h"

void aoc::day10()
{
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d10-1.txt"));
  struct pipe start{};
  auto found_start = false;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].length(); j++) {
      if (lines[i][j] == 'S') {
        start.x = j;
        start.y = i;
        start.type = find_s_type(lines, start.x, start.y);
        found_start = true;
        break;
      }
    }
    if (found_start) {
      break;
    }
  }
  lines[start.y][start.x] = get_char(start.type);
  auto pipes = count_pipes(lines, start);
  std::cout << pipes.size() / 2 << std::endl;
  std::vector<std::string> map(lines.size(), std::string(lines[0].length(), '.'));

  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      auto tile = make_pipe(lines, j, i);
      if (pipes.contains(tile)) {
        map[tile.y][tile.x] = lines[tile.y][tile.x];
      }
    }
  }

  auto contained = 0;
  for (int i = 0; i < map.size(); i++) {
    auto crossing = 0;
    for (int j = 0; j < map[i].size(); j++) {
      if (map[i][j] != '.') {
        auto k = j + 1;
        while (is_open_right(map, j, i) && is_open_left(map, k, i)) {
          k++;
        }
        k--;
        if ((map[i][j] == 'F' && map[i][k] != '7') || (map[i][j] == 'L' && map[i][k] != 'J') || map[i][j] == '|') {
          crossing++;
        }
        j = k;
      } else if (crossing & 1) {
        map[i][j] = 'I';
        contained++;
      } else {
        map[i][j] = 'O';
      }
    }
  }
  std::cout << contained << std::endl;

  for (const auto& m : map) {
    std::cout << m << std::endl;
  }
  std::cout << std::endl;
}

char aoc::get_char(PipeType type) {
  switch (type) {
    case PipeType::Vert:
      return '|';
    case PipeType::Hori:
      return '-';
    case PipeType::L:
      return 'L';
    case PipeType::J:
      return 'J';
    case PipeType::Seven:
      return '7';
    case PipeType::F:
      return 'F';
    case PipeType::Unknown:
    case PipeType::Empty:
      return '.';
  }
  return '.';
}

aoc::PipeType aoc::find_s_type(const std::vector<std::string> &lines, int x, int y) {
  auto type = PipeType::Unknown;
  if (is_open_right(lines, x - 1, y) && is_open_left(lines, x + 1, y)) {
    type = PipeType::Hori;
  } else if (is_open_right(lines, x - 1, y) && is_open_bottom(lines, x, y - 1)) {
    type = PipeType::J;
  } else if (is_open_right(lines, x - 1, y) && is_open_top(lines, x, y + 1)) {
    type = PipeType::Seven;
  } else if (is_open_bottom(lines, x, y - 1) && is_open_left(lines, x + 1, y)) {
    type = PipeType::L;
  } else if (is_open_bottom(lines, x, y - 1) && is_open_top(lines, x, y + 1)) {
    type = PipeType::Vert;
  } else {
    type = PipeType::F;
  }
  return type;
}

std::unordered_set<struct aoc::pipe> aoc::count_pipes(const std::vector<std::string>& map, struct pipe& node)
{
  int count = 0;
  std::queue<struct pipe> q;
  std::unordered_set<struct pipe> seen;
  q.push(node);
  while (!q.empty()) {
    const auto n = q.front();
    q.pop();
    if (seen.contains(n) || n.type == PipeType::Unknown || n.type == PipeType::Empty) {
      continue;
    }
    seen.insert(n);
    count++;
    struct pipe next{}, prev{};
    switch (n.type) {
      case PipeType::Vert:
        next = make_pipe(map, n.x, n.y - 1);
        prev = make_pipe(map, n.x, n.y + 1);
        break;
      case PipeType::Hori:
        next = make_pipe(map, n.x - 1, n.y);
        prev = make_pipe(map, n.x + 1, n.y);
        break;
      case PipeType::L:
        next = make_pipe(map, n.x + 1, n.y);
        prev = make_pipe(map, n.x, n.y - 1);
        break;
      case PipeType::J:
        next = make_pipe(map, n.x - 1, n.y);
        prev = make_pipe(map, n.x, n.y - 1);
        break;
      case PipeType::Seven:
        next = make_pipe(map, n.x - 1, n.y);
        prev = make_pipe(map, n.x, n.y + 1);
        break;
      case PipeType::F:
        next = make_pipe(map, n.x + 1, n.y);
        prev = make_pipe(map, n.x, n.y + 1);
        break;
      case PipeType::Empty:
      case PipeType::Unknown:
      default:
        break;
    }
    if (!seen.contains(next) && next.type != PipeType::Unknown && next.type != PipeType::Empty) {
      q.push(next);
    }
    if (!seen.contains(prev) && prev.type != PipeType::Unknown && prev.type != PipeType::Empty) {
      q.push(prev);
    }
  }
  return seen;
}

struct aoc::pipe aoc::make_pipe(const std::vector<std::string>& map, int x, int y)
{
  struct pipe pipe{};
  pipe.x = x;
  pipe.y = y;
  pipe.type = pipe.type = PipeType::Unknown;
  if (!in_bounds(map, x, y)) {
    return pipe;
  }
  switch (map[y][x]) {
    case '|':
      pipe.type = PipeType::Vert;
      break;
    case '-':
      pipe.type = PipeType::Hori;
      break;
    case 'L':
      pipe.type = PipeType::L;
      break;
    case 'J':
      pipe.type = PipeType::J;
      break;
    case '7':
      pipe.type = PipeType::Seven;
      break;
    case 'F':
      pipe.type = PipeType::F;
      break;
    case '.':
      pipe.type = PipeType::Empty;
      break;
    case 'S':
      pipe.type = find_s_type(map, x, y);
    default:
      break;
  }
  return pipe;
}

bool aoc::in_bounds(const std::vector<std::string>& map, int x, int y)
{
  if (x < 0 || y < 0) {
    return false;
  }
  if (y >= map.size() || x >= map[y].size()) {
    return false;
  }
  return true;
}

bool aoc::is_open_right(const std::vector<std::string>& map, int x, int y)
{
  if (!in_bounds(map, x, y)) {
    return false;
  }
  switch (map[y][x]) {
    case '-':
    case 'L':
    case 'F':
      return true;
    default:
      return false;
  }
}

bool aoc::is_open_left(const std::vector<std::string>& map, int x, int y)
{
  if (!in_bounds(map, x, y)) {
    return false;
  }
  switch (map[y][x]) {
    case '-':
    case 'J':
    case '7':
      return true;
    default:
      return false;
  }
}

bool aoc::is_open_top(const std::vector<std::string>& map, int x, int y)
{
  if (!in_bounds(map, x, y)) {
    return false;
  }
  switch (map[y][x]) {
    case '|':
    case 'L':
    case 'J':
      return true;
    default:
      return false;
  }
}

bool aoc::is_open_bottom(const std::vector<std::string>& map, int x, int y)
{
  if (!in_bounds(map, x, y)) {
    return false;
  }
  switch (map[y][x]) {
    case '|':
    case '7':
    case 'F':
      return true;
    default:
      return false;
  }
}
