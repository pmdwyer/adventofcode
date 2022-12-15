#include "knots.h"

std::vector<aoc::move> aoc::make_moves(const std::vector<std::string>& lines) {
  std::vector<move> moves;
  for (const auto& line : lines) {
    moves.emplace_back(line[0], std::stoi(split(line)[1]));
  }
  return moves;
}

int aoc::count_unique_moves(const std::vector<move>& moves, int num_knots) {
  std::unordered_set<point> visited;
  std::vector<point> knots{(size_t) num_knots, {0, 0}};
  for (const auto& move : moves) {
    for (int d = 0; d < move.amount; d++) {
      switch (move.dir) {
        case 'U':
          knots[0].y++;
          break;
        case 'D':
          knots[0].y--;
          break;
        case 'L':
          knots[0].x--;
          break;
        case 'R':
          knots[0].x++;
          break;
      }
      for (int i = 1; i < knots.size(); i++) {
        int dx = knots[i - 1].x - knots[i].x;
        int dy = knots[i - 1].y - knots[i].y;
        if (abs(dx) > 1 || abs(dy) > 1) {
          knots[i].x += dx > 0 ? 1 : dx < 0 ? -1 : 0;
          knots[i].y += dy > 0 ? 1 : dy < 0 ? -1 : 0;
        }
      }
      visited.insert(knots[knots.size() - 1]);
    }
  }
  return (int) visited.size();
}