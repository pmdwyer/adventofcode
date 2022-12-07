//
// Created by pdwyer on 12/7/2022.
//

#ifndef ADVENTOFCODE_FS_H
#define ADVENTOFCODE_FS_H

#include <algorithm>
#include <memory>
#include <numeric>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

namespace aoc {
  class file {
  public:
    file(std::string n, int sz) : name{std::move(n)}, size{sz} {};
    std::string name;
    int size;
  };

  class dir {
  public:
    explicit dir(std::string n) : _subdirs{}, _files{}, _name{std::move(n)} {};
    void create_subdir(const std::string& name);
    void create_file(const std::string& name, int size);
    int calculate_size();

  private:
    std::string _name;
    std::vector<std::shared_ptr<dir>> _subdirs;
    std::vector<std::shared_ptr<file>> _files;
  };
}


#endif //ADVENTOFCODE_FS_H
