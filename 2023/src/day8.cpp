#include "day8.h"

#include <string>
#include <unordered_map>
#include <iostream>

#include "func.h"
#include "str.h"
#include "file.h"
#include "maths.h"

void aoc::day8()
{
  auto lines = aoc::map<std::string, std::string>(aoc::trim, aoc::get_lines("../../2023/input/d8-1.txt"));
  std::vector<int> insts(lines[0].length());
  for (int i = 0; i < lines[0].length(); i++) {
    insts[i] = (lines[0][i] == 'L' ? 0 : 1);
  }

  std::vector<std::string> indexes;

  int start, finish;
  std::vector<int> starts, finishes;
  std::unordered_map<int, std::array<int, 2>> nodes;
  for (int i = 2; i < lines.size(); i++) {
    auto t = aoc::split("=", lines[i]);
    auto node = aoc::trim(t[0]);
    auto node_index = aoc::get_index(indexes, node);

    auto t2 = aoc::map<std::string, std::string>(aoc::trim, aoc::split(",", t[1]));
    auto left = aoc::remove(t2[0], "(");
    int l_index = aoc::get_index(indexes, left);

    auto right = aoc::remove(t2[1], ")");
    auto r_index = aoc::get_index(indexes, right);

    nodes[node_index] = { l_index, r_index };

    if (node == "AAA") {
      start = (int) node_index;
    } else if (node == "ZZZ") {
      finish = (int) node_index;
    }
    if (node.ends_with('A')) {
      starts.push_back(node_index);
    }
    if (node.ends_with('Z')) {
      finishes.push_back(node_index);
    }
  }

  follow_path(insts, start, finish, nodes);
  follow_simul_paths(insts, starts, finishes, nodes);
}

void aoc::follow_simul_paths(const std::vector<int> &insts,
                             const std::vector<int> &starts,
                             const std::vector<int> &finishes,
                             std::unordered_map<int, std::array<int, 2>> &nodes)
{
    std::vector<unsigned long long> counts;
    for (const auto& start : starts) {
      auto curr = start;
      auto count = 0;
      const auto sz = insts.size();

      auto f_index = std::find(finishes.begin(), finishes.end(), curr);
      while (f_index == finishes.end()) {
        auto i = count % sz;
        curr = nodes[curr][insts[i]];
        f_index = std::find(finishes.begin(), finishes.end(), curr);
        count++;
      }
      counts.push_back(count);
    }
    std::cout << aoc::lcm(counts) << std::endl;
}

void aoc::follow_path(const std::vector<int>& insts, int start, int finish,
                      std::unordered_map<int, std::array<int, 2>>& nodes)
{
  auto curr = start;
  auto count = 0;
  const auto sz = insts.size();
  while (curr != finish) {
    auto i = count % sz;
    curr = nodes[curr][insts[i]];
    count++;
  }
  std::cout << count << std::endl;
}

template <class T>
int aoc::get_index(std::vector<T>& indexes, const T& node)
{
  auto itr = std::find(indexes.begin(), indexes.end(), node);
  int index;
  if (itr == indexes.end()) {
    index = (int) indexes.size();
    indexes.push_back(node);
  } else {
    index = (int) std::distance(indexes.begin(), itr);
  }
  return index;
}
