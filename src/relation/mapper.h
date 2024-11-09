/// mapper.h

#pragma once

#include <unordered_map>

namespace PlanarGraphColoring {

struct pair_hash {
public:
  static constexpr size_t HASH_MAX_N = 10000;
  std::size_t operator() (const std::pair<size_t, size_t>& p) const {
    return p.first * HASH_MAX_N + p.second;
  }
};/// struct pair_hash

class Mapper {
public:
  void insert(const size_t i, const size_t j, const size_t k);
  void insert(const size_t i, const std::pair<size_t, size_t>& p);
  void show(const size_t n) const;
  inline size_t size() const {
    return plane2line_.size();
  }
protected:
  std::unordered_map<std::pair<size_t, size_t>, size_t, pair_hash> plane2line_;
  std::unordered_map<size_t, std::pair<size_t, size_t>> line2plane_;
};/// class Mapper

}/// namespace PlanarGraphColoring 
