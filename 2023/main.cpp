#include <chrono>
#include <iostream>

#include "day5.h"


int main() {
  const auto start = std::chrono::high_resolution_clock::now();
  aoc::day5();
  const auto end = std::chrono::high_resolution_clock::now();
  auto dt = end - start;
  std::cout << "time taken: " << dt << std::endl;
  return 0;
}
