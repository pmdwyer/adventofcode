#ifndef ADVENTOFCODE_FS_H
#define ADVENTOFCODE_FS_H

#include <algorithm>
#include <functional>
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

  class dir : public std::enable_shared_from_this<dir> {
  public:
    explicit dir(std::string n) : _subdirs{}, _files{}, _name{std::move(n)}, _parent{nullptr} {};
    dir(std::string n, std::shared_ptr<dir> parent)
      : _subdirs{}, _files{}, _name{std::move(n)}, _parent{std::move(parent)}
    {};

    void create_subdir(const std::string& name);
    void create_file(const std::string& name, int size);

    std::shared_ptr<dir> get_parent() { return _parent; };
    std::shared_ptr<dir> get_subdir(const std::string& name);

    void get_size_when(const std::function<bool(int)>& pred, int* val);
    int get_size() const { return _size; };
    int get_smallest_dir(int space_needed);

  private:
    int _size = 0;
    std::string _name;
    std::shared_ptr<dir> _parent;
    std::vector<std::shared_ptr<dir>> _subdirs;
    std::vector<std::shared_ptr<file>> _files;

    void add_file_size(int size);
  };
}


#endif //ADVENTOFCODE_FS_H
