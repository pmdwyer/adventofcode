#include "day11.h"

#include <iterator>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_set>

#include "func.h"
#include "str.h"
#include "file.h"

void aoc::day11()
{
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d11-1.txt"));
//  expand_rows(lines);
//  lines = transpose(lines);
//  expand_rows(lines);
//  lines = transpose(lines);

  std::unordered_set<int> rows, cols;
  for (int i = 0; i < lines.size(); i++) {
    if (lines[i].find('#') == std::string::npos) {
      rows.insert(i);
    }
  }
  lines = transpose(lines);
  for (int i = 0; i < lines.size(); i++) {
    if (lines[i].find('#') == std::string::npos) {
      cols.insert(i);
    }
  }
  lines = transpose(lines);
  std::cout << std::endl;

  auto galaxies = find_galaxies(lines);
  unsigned long long sum = 0;
  for (int i = 0; i < galaxies.size(); i++) {
    for (int j = i + 1; j < galaxies.size(); j++) {
      unsigned long long dx = 0;
      auto start = std::min(galaxies[i].x, galaxies[j].x);
      auto end = std::max(galaxies[i].x, galaxies[j].x);
      for (int k = start + 1; k <= end; k++) {
        if (rows.contains(k)) {
          dx += 1000000UL;
        } else {
          dx += 1;
        }
      }
      unsigned long long dy = 0;
      start = std::min(galaxies[i].y, galaxies[j].y);
      end = std::max(galaxies[i].y, galaxies[j].y);
      for (int k = start + 1; k <= end; k++) {
        if (cols.contains(k)) {
          dy += 1000000UL;
        } else {
          dy += 1;
        }
      }
      sum += dx + dy;
    }
  }
  std::cout << sum << std::endl;
}

void aoc::expand_rows(std::vector<std::string>& vs)
{
  for (int i = 0; i < vs.size(); i++) {
    if (std::all_of(begin(vs[i]), end(vs[i]), [](char c) { return c == '.'; })) {
      std::string copy = vs[i];
      vs.insert(vs.begin() + i, 1, copy);
      i++;
    }
  }
}

std::vector<aoc::point> aoc::find_galaxies(const std::vector<std::string>& vs)
{
  std::vector<aoc::point> points;
  for (int i = 0; i < vs.size(); i++) {
    for (int j = 0; j < vs[i].size(); j++) {
      if (vs[i][j] == '#') {
        points.push_back({i, j});
      }
    }
  }
  return points;
}

std::vector<struct aoc::point> aoc::a_star(const std::vector<std::string>& map, const struct point& start, const struct point& finish) {
  std::unordered_map<struct point, int> dist;
  std::unordered_map<struct point, struct point> prev;
  std::unordered_set<struct point> queued;
  auto width = map.size();
  auto height = map[0].length();

  auto compare = [&](struct point& p1, struct point& p2) {
    auto h1 = (finish.x - p1.x) * (finish.x - p1.x) + (finish.y - p1.y) * (finish.y - p1.y);
    auto h2 = (finish.x - p2.x) * (finish.x - p2.x) + (finish.y - p2.y) * (finish.y - p2.y);
    auto d1 = (dist.contains(p1) ? dist[p1] : (width * height)) + h1;
    auto d2 = (dist.contains(p2) ? dist[p2] : (width * height)) + h2;
    return d1 < d2;
  };
  std::priority_queue<struct point, std::vector<struct point>, decltype(compare)> q(compare);
  q.push(start);
  dist[start] = 0;
  prev[start] = { -1, -1 };
  queued.insert(start);

  while (!q.empty()) {
    auto curr = q.top();
    q.pop();
    for (const auto& n : get_neighbors(curr, (int) width, (int) height)) {
      if (!queued.contains(n) || (dist.contains(n) && dist[n] > (dist[curr] + 1))) {
        queued.insert(n);
        q.push(n);
        dist[n] = dist[curr] + 1;
        prev[n] = curr;
      }
    }
  }
  std::vector<struct point> path;
  struct point n = finish;
  while (n != start) {
    path.push_back(n);
    n = prev[n];
  }
  path.push_back(start);
  std::reverse(begin(path), end(path));
  return path;
}

std::vector<struct aoc::point> aoc::get_neighbors(const struct point &point, int maxx, int maxy)
{
  std::vector<struct point> neighbors;
  if (point.x - 1 >= 0) {
    neighbors.push_back({point.x - 1, point.y});
  }
  if (point.y - 1 >= 0) {
    neighbors.push_back({point.x, point.y - 1});
  }
  if (point.x + 1 < maxx) {
    neighbors.push_back({point.x + 1, point.y});
  }
  if (point.y + 1 < maxy) {
    neighbors.push_back({point.x, point.y + 1});
  }
  return neighbors;
}