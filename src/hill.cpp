#include "hill.h"

std::vector<std::vector<int>> aoc::make_map(const std::vector<std::string>& lines) {
  std::vector<std::vector<int>> heightmap{lines.size(), std::vector<int>(lines[0].size(), 0)};
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (lines[i][j] == 'S') {
        heightmap[i][j] = 0;
      } else if (lines[i][j] == 'E') {
        heightmap[i][j] = 25;
      } else {
        heightmap[i][j] = lines[i][j] - 'a';
      }
    }
  }
  return heightmap;
}

std::tuple<std::vector<aoc::point>, aoc::point> aoc::get_start_and_end(const std::vector<std::string>& heightmap) {
  std::vector<point> starts;
  point finish;
  for (int i = 0; i < heightmap.size(); i++) {
    for (int j = 0; j < heightmap[i].size(); j++) {
      if (heightmap[i][j] == 'S' || heightmap[i][j] == 'a') {
        starts.emplace_back(j, i);
      } else if (heightmap[i][j] == 'E') {
        finish.x = j;
        finish.y = i;
      }
    }
  }
  return std::make_tuple(starts, finish);
}

std::vector<aoc::point> aoc::pathfind(const std::tuple<std::vector<point>, point>& start_end, const std::vector<std::vector<int>>& heightmap) {
  std::unordered_map<point, point> parent;
  std::unordered_map<point, int> distance;
  std::unordered_set<point> wavefront, visited;
  std::queue<point> q;

  auto finish = std::get<1>(start_end);
  distance[finish] = -1;

  auto starts = std::get<0>(start_end);
  for (const auto& start : starts) {
    distance[start] = 0;
    parent[start] = point{-1, -1};
    q.push(start);
    wavefront.insert(start);
  }

  while (!q.empty()) {
    auto current = q.front();
    for (auto p : get_neighbors(current, heightmap)) {
      if ((!visited.contains(p) && !wavefront.contains(p)) ||
          (distance[p] > distance[current] + 1)) {
        q.push(p);
        wavefront.insert(p);
        distance[p] = distance[current] + 1;
        parent[p] = current;
      }
    }
    wavefront.erase(current);
    visited.insert(current);
    q.pop();
  }

  std::vector<point> path;
  auto p = finish;
  while (p.x >= 0 && p.y >= 0) {
    path.push_back(p);
    p = parent[p];
  }
  return path;
}

std::vector<aoc::point> aoc::get_neighbors(const point &p, const std::vector<std::vector<int>>& heightmap) {
  std::vector<point> neighbors;
  if (p.x + 1 < heightmap[0].size()) {
    if (heightmap[p.y][p.x + 1] <= heightmap[p.y][p.x] + 1) {
      neighbors.emplace_back(p.x + 1, p.y);
    }
  }
  if (p.x - 1 >= 0) {
    if (heightmap[p.y][p.x - 1] <= heightmap[p.y][p.x] + 1) {
      neighbors.emplace_back(p.x - 1, p.y);
    }
  }
  if (p.y + 1 < heightmap.size()) {
    if (heightmap[p.y + 1][p.x] <= heightmap[p.y][p.x] + 1) {
      neighbors.emplace_back(p.x, p.y + 1);
    }
  }
  if (p.y - 1 >= 0) {
    if (heightmap[p.y - 1][p.x] <= heightmap[p.y][p.x] + 1) {
      neighbors.emplace_back(p.x, p.y - 1);
    }
  }
  return neighbors;
}