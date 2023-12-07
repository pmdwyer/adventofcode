#ifndef AOC23_UNORDERED_RANGE_MAP_H
#define AOC23_UNORDERED_RANGE_MAP_H

#include <tuple>
#include <vector>

namespace aoc {
  template<class T>
  class unordered_range_map {
  public:
    unordered_range_map() = default;
    ~unordered_range_map() = default;

    T operator[](T n) const;
    std::vector<std::tuple<T, T>> operator[](const std::tuple<T, T> &range) const;

    void insert(T source, T dest, T range);

  private:
    struct range {
      T src_start;
      T src_end;
      T dest_start;
      T dest_end;
    };

    std::vector<struct range> _ranges;
  };

  template<class T>
  T unordered_range_map<T>::operator[](T n) const {
    for (const auto &r: _ranges) {
      if (n >= r.src_start && n <= r.src_end) {
        return r.dest_start + (n - r.src_start);
      }
    }
    return n;
  }

  template<class T>
  std::vector<std::tuple<T, T>> unordered_range_map<T>::operator[](const std::tuple<T, T> &range) const {
    std::vector<std::tuple<T, T>> dests;
    auto start = std::get<0>(range);
    auto end = std::get<1>(range);

    bool done = false, any_matched = true;
    while (!done && any_matched) {
      any_matched = false;
      for (const auto& r : _ranges) {
        if (start >= r.src_start && start <= r.src_end && end >= r.src_start && end <= r.src_end) {
          // entire search range is contained
          dests.push_back({r.dest_start + (start - r.src_start), r.dest_start + (end - r.src_start)});
          done = true;
          any_matched = true;
          break;
        } else if (start >= r.src_start && start <= r.src_end && end >= r.src_end) {
          // end of search range is out of range, move start and add the existing range
          dests.push_back({r.dest_start + (start - r.src_start), r.dest_end});
          start = r.src_end + 1;
          any_matched = true;
          break;
        } else if (r.src_start > start && r.src_start <= end && end <= r.src_end) {
          // start of search range is out of range, move end and add the existing range
          dests.push_back({r.dest_start, r.dest_start + (end - r.src_start)});
          end = r.src_start - 1;
          any_matched = true;
          break;
        }
      }
    }
    if (!any_matched) {
      dests.push_back({start, end});
    }

    return dests;
  }

  template<class T>
  void unordered_range_map<T>::insert(T source, T dest, T range) {
    _ranges.push_back({source, source + range, dest, dest + range});
  }
}

#endif //AOC23_UNORDERED_RANGE_MAP_H
