//
// Created by pdwyer on 12/7/2022.
//

#include "fs.h"

void aoc::dir::create_subdir(const std::string& name) {
  _subdirs.push_back(std::make_unique<dir>(name));
}

void aoc::dir::create_file(const std::string& name, int size) {
  _files.push_back(std::make_unique<file>(name, size));
}

int aoc::dir::calculate_size() {
  int size = 0;
  for (const auto& d : _subdirs) {
    size += d->calculate_size();
  }
  for (const auto& f : _files) {
    size+= f->size;
  }
  return size;
}