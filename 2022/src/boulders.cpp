#include "../include/boulders.h"

std::vector<aoc::cube> aoc::make_cubes(const std::vector<std::string> &lines)
{
  std::vector<cube> cubes;
  for (const auto& line : lines) {
    auto coords = split_on(line, ',');
    cubes.emplace_back(std::stoi(coords[0]) + 1, std::stoi(coords[1]) + 1, std::stoi(coords[2]) + 1);
  }
  return cubes;
}

int aoc::calc_total_surface_area(const cube_map &map)
{
  int surface_area = 0;
  for (int i = 1; i < 22; i++) {
    for (int j = 1; j < 22; j++) {
      for (int k = 1; k < 22; k++) {
        cube c{i, j, k};
        surface_area += exposed_sides(c, map);
      }
    }
  }
  return surface_area;
}

int aoc::neighbors(const aoc::cube &c, const aoc::cube_map &map)
{
  int num_neighbors = 0;
  if (map[c.x - 1][c.y][c.z]) {
    num_neighbors++;
  }
  if (map[c.x + 1][c.y][c.z]) {
    num_neighbors++;
  }
  if (map[c.x][c.y - 1][c.z]) {
    num_neighbors++;
  }
  if (map[c.x][c.y + 1][c.z]) {
    num_neighbors++;
  }
  if (map[c.x][c.y][c.z - 1]) {
    num_neighbors++;
  }
  if (map[c.x][c.y][c.z + 1]) {
    num_neighbors++;
  }
  return num_neighbors;
}

aoc::cube_map aoc::gen_cube_map(const std::vector<cube> &cubes)
{
  cube_map map{};
  for (const auto& cube : cubes) {
    map[cube.x][cube.y][cube.z] = true;
  }
  return map; 
}

int aoc::exposed_sides(cube c, const cube_map &map)
{
  if (!map[c.x][c.y][c.z]) {
    return 0;
  }
  return 6 - neighbors(c, map);
}

int aoc::calc_actual_surface_area(const aoc::cube_map &map)
{
  int surface_area = 0;
  cube curr{0, 0, 0};
  std::queue<cube> q;
  std::unordered_set<cube> visited;
  std::unordered_set<cube> wavefront;

  q.push(curr);
  wavefront.insert(curr);
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    wavefront.erase(curr);
    visited.insert(curr);
    for (const auto& n : gen_neighbors(curr)) {
      if (map[n.x][n.y][n.z]) {
        surface_area++;
      } else if (!visited.contains(n) && !wavefront.contains(n)) {
        q.push(n);
        wavefront.insert(n);
      }
    }
  }
  return surface_area;
}

std::vector<aoc::cube> aoc::gen_neighbors(const cube &c)
{
  std::vector<cube> neighbors;
  if (c.x - 1 >= 0) {
    neighbors.emplace_back(c.x - 1, c.y, c.z);
  }
  if (c.x + 1 < 22) {
    neighbors.emplace_back(c.x + 1, c.y, c.z);
  }
  if (c.y - 1 >= 0) {
    neighbors.emplace_back(c.x, c.y - 1, c.z);
  }
  if (c.y + 1 < 22) {
    neighbors.emplace_back(c.x, c.y + 1, c.z);
  }
  if (c.z - 1 >= 0) {
    neighbors.emplace_back(c.x, c.y, c.z - 1);
  }
  if (c.z + 1 < 22) {
    neighbors.emplace_back(c.x, c.y, c.z + 1);
  }
  return neighbors;
}
