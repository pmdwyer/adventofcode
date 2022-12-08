#include "fs.h"

void aoc::dir::create_subdir(const std::string& name) {
  auto dir = std::ranges::find_if(_subdirs.begin(), _subdirs.end(), [&](const std::shared_ptr<aoc::dir>& d) { return d->_name == name; });
  if (dir == _subdirs.end()) {
    _subdirs.push_back(std::make_shared<aoc::dir>(name, shared_from_this()));
  }
}

void aoc::dir::create_file(const std::string& name, int size) {
  auto fi = std::ranges::find_if(_files.begin(), _files.end(), [&](const std::shared_ptr<aoc::file>& f) { return f->name == name; });
  if (fi == _files.end()) {
    _files.push_back(std::make_shared<file>(name, size));
    add_file_size(size);
  }
}

std::shared_ptr<aoc::dir> aoc::dir::get_subdir(const std::string& name) {
  auto dir = std::ranges::find_if(_subdirs.begin(), _subdirs.end(), [&](const std::shared_ptr<aoc::dir>& d) { return d->_name == name; });
  if (dir == _subdirs.end()) {
    return nullptr;
  }
  return *dir;
}

void aoc::dir::get_size_when(const std::function<bool(int)>& pred, int* val) {
  int size = get_size();
  std::ranges::for_each(_subdirs.begin(), _subdirs.end(), [&](const std::shared_ptr<dir>& subdir){ subdir->get_size_when(pred, val); });
  if (pred(size)) {
    *val += size;
  }
}

void aoc::dir::add_file_size(int size) {
  _size += size;
  if (_parent)
    _parent->add_file_size(size);
}

int aoc::dir::get_smallest_dir(int space_needed) {
  auto min_size = 70000000;
  for (const auto& subdir : _subdirs) {
    auto subdir_smallest = subdir->get_smallest_dir(space_needed);
    if (subdir_smallest >= space_needed) {
      min_size = std::min(min_size, subdir_smallest);
    }
  }
  if (get_size() > space_needed) {
    min_size = std::min(min_size, get_size());
  }
  return min_size;
}