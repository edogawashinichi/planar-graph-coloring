/// hash.h

#pragma once

#include "global.h"
#include <utility>
#include <vector>

namespace PlanarGraphColoring {

struct pair_hash {
  size_t N() const {
    /// WARNING: transform global non-constant-expression to constant-expression
    return UNDEF_VERTEX;
  }
  size_t operator() (const std::pair<size_t, size_t>& p) const {
    return p.first * this->N() + p.second;
  }
};/// struct pair_hash 

struct vector_hash {
  size_t N() const {
    return COLORS.size();
  }
  size_t operator() (const std::vector<size_t>& v) const {
    size_t res = 0;
    for (const auto a : v) {
      res = res * this->N() + a;
    }
    return res;
  }
};/// struct vector_hash

}/// namespace PlanarGraphColoring
