#include "../include/grid.h"

#include <iostream>

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
  std::vector<std::vector<bool>> visible(height, std::vector<bool>(width, false));
  for (int i = 0; i < height; i++) {
    visible[i][0] = true;
    visible[i][width - 1] = true;
  }
  for (int j = 0; j < width; j++) {
    visible[0][j] = true;
    visible[height - 1][j] = true;
  }
  for (int i = 1; i < height - 1; i++) {
    int current_max = _matrix[i][0];
    for (int j = 1; j < width; j++) {
      if (_matrix[i][j] > current_max) {
        current_max = _matrix[i][j];
        visible[i][j] = true;
      }
    }
    current_max = _matrix[i][width - 1];
    for (int j = width - 2; j >= 0; j--) {
      if (_matrix[i][j] > current_max) {
        current_max = _matrix[i][j];
        visible[i][j] = true;
      }
    }
  }
  for (int j = 1; j < width - 1; j++) {
    int current_max = _matrix[0][j];
    for (int i = 1; i < height; i++) {
      if (_matrix[i][j] > current_max) {
        current_max = _matrix[i][j];
        visible[i][j] = true;
      }
    }
    current_max = _matrix[height - 1][j];
    for (int i = height - 2; i >= 0; i--) {
      if (_matrix[i][j] > current_max) {
        current_max = _matrix[i][j];
        visible[i][j] = true;
      }
    }
  }
  int trees = 0;
  for (int i = 0; i < height; i++) {
    trees += std::count_if(visible[i].begin(), visible[i].end(), [](bool b) { return b; });
  }
  return trees;
}

int aoc::grid::calc_scenic_score() {
  int height = (int) _matrix.size();
  int width = (int) _matrix[0].size();
  std::vector<std::vector<int>> scores(height, std::vector<int>(width, 0));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int k = j - 1;
      while (k >= 0 && _matrix[i][k] < _matrix[i][j]) {
        k--;
      }
      scores[i][j] = k < 0 ? j : j - k;
      k = j + 1;
      while (k < width && _matrix[i][k] < _matrix[i][j]) {
        k++;
      }
      scores[i][j] *= k >= width ? k - j - 1 : k - j;
    }
  }
  for (int j = 0; j < width; j++) {
    for (int i = 0; i < height; i++) {
      int k = i - 1;
      while (k >= 0 && _matrix[k][j] < _matrix[i][j]) {
        k--;
      }
      scores[i][j] *= k < 0 ? i : i - k;
      k = i + 1;
      while (k < height && _matrix[k][j] < _matrix[i][j]) {
        k++;
      }
      scores[i][j] *= k >= height ? k - i - 1 : k - i;
    }
  }
  int score = -1;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << scores[i][j] << ' ';
      score = std::max(score, scores[i][j]);
    }
    std::cout << std::endl;
  }
  return score;
}