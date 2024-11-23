/// mapper.h

#pragma once

#include "../basic/hash.h"
#include <unordered_map>

namespace PlanarGraphColoring {

class Mapper {
public:
  void insert(const size_t i, const size_t j, const size_t k);
  void insert(const size_t i, const std::pair<size_t, size_t>& p);
  void show(const size_t n) const;
  inline size_t size() const {
    return plane2line_.size();
  }
  size_t get(const size_t i, const size_t j) const;
protected:
  std::unordered_map<std::pair<size_t, size_t>, size_t, pair_hash> plane2line_;
  std::unordered_map<size_t, std::pair<size_t, size_t>> line2plane_;
};/// class Mapper

}/// namespace PlanarGraphColoring 
