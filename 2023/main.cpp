#include <chrono>
#include <iostream>

#include "day8.h"

int main() {
  const auto start = std::chrono::high_resolution_clock::now();
  aoc::day8();
  const auto end = std::chrono::high_resolution_clock::now();
  auto dt = end - start;
  std::cout << "time taken: " << dt.count() << std::endl;
  return 0;
}
