/// hash.h

#pragma once

#include "global.h"
#include <utility>

namespace PlanarGraphColoring {

struct pair_hash {
  size_t maxN() const {
    return UNDEF_VERTEX;
  }
  size_t operator() (const std::pair<size_t, size_t>& p) const {
    return p.first * maxN() + p.second;
  }
};/// struct pair_hash 

}/// namespace PlanarGraphColoring
