#include "maths.h"

int aoc::power(int num, int exp) {
  int x = 1;
  while (exp > 0) {
    x *= num;
    exp--;
  }
  return x;
}
