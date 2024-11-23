/// hash.h

#pragma once

#include <utility>

namespace PlanarGraphColoring {

struct pair_hash {
  static constexpr size_t HASH_MAX_N = 10000;
  size_t operator() (const std::pair<size_t, size_t>& p) const {
    return p.first * HASH_MAX_N + p.second;
  }
};/// struct pair_hash 

}/// namespace PlanarGraphColoring
