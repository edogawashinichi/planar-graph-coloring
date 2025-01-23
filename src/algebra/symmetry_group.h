/// symmetry_group.h

/// a symmetry group is a group whose elements are permutations

#pragma once

#include "group.h"
#include "permutation.h"
#include "../combinatorics/permutator/next_iter_permutator.h"

namespace PlanarGraphColoring {

class SymmetryGroup : public Group<Permutation> {
public:
  inline SymmetryGroup() : Group<Permutation>() {
  }/// constructor default
  inline SymmetryGroup(const size_t N) : Group<Permutation>() {
    const size_t n = fact(N);
    Group<Permutation>::elements().resize(n);
    NextIterPermutator ni;
    const VVI& res = ni.run(N);
    for (size_t i = 0; i < n; ++i) {
      Group<Permutation>::element(i) = std::move(Permutation(res[i]));
    }/// for
  }/// constructor
};/// class SymmetryGroup

}/// namespace PlanarGraphColoring
