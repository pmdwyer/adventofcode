#include "grid.h"

aoc::grid::grid(const std::vector<std::string>& text)
  : _matrix{}
{
  _matrix.resize(text.size());
  for (int i = 0; i < text.size(); i++) {
    _matrix[i].resize(text[i].length());
    for (int j = 0; j < text[i].length(); j++) {
      _matrix[i][j] = text[i][j] - '0';
    }
  }
}

int aoc::grid::calc_visible_trees() {
  int height = (int) _matrix.size();
  int width = (int) _matrix[0].size();
  std::vector<bool> visible(width * height, false);
  for (int i = 0; i < height; i++) {
    visible[height * i + 0] = true;
    visible[height * i + width - 1] = true;
    // left
    for (int j = 1; j < width; j++) {
      if (_matrix[i][j] > _matrix[i][j - 1]) {
        visible[height * i + j] = true;
      } else {
        break;
      }
    }
    // right
    for (int j = width - 2; j >= 0; j--) {
      if (_matrix[i][j] > _matrix[i][j + 1]) {
        visible[height * i + j] = true;
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < width; i++) {
    visible[0          + width * i] = true;
    visible[height - 1 + width * i] = true;
    // top
    for (int j = 1; j < height - 1; j++) {
      if (_matrix[j][i] > _matrix[j - 1][i]) {
        visible[height * j + i] = true;
      } else {
        break;
      }
    }
    // bottom
    for (int j = height - 2; j >= 0; j--) {
      if (_matrix[j][i] > _matrix[j + 1][i]) {
        visible[height * j + i] = true;
      } else {
        break;
      }
    }
  }
  auto trees = std::count_if(visible.begin(), visible.end(), [](bool v) { return v; });
  return (int) trees;
}