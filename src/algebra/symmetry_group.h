/// symmetry_group.h

#pragma once

#include "group.h"
#include "permutation.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

template <size_t N>
class SymmetryGroup : public Group {
public:
  inline SymmetryGroup() {
    const size_t n = fact(N);
    elements_.resize(n);
    for (const size_t i = 0; i < n; ++i) {
      elements_[i] = std::move(Permutation(i));
    }
  }
protected:
  std::vector<Permutation> elements_;
};/// class SymmetryGroup

}/// namespace PlanarGraphColoring
