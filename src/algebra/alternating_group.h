/// alternating_group.h

/// an alternating group is a group of even permutations

#pragma once

#include "symmetry_group.h"
#include "permutator/johnson_trotter_permutator.h"

namespace PlanarGraphColoring {

class AlternatingGroup : public SymmetryGroup {
public:
  inline AlternatingGroup() = default;
  inline AlternatingGroup(const size_t N) {
    const size_t n = fact(N) / 2;
    /*
    Proposition: the number of all even permutations is equal to the number of all odd permutations of order N.
    Proof: denote them by n(e) and n(o) respectively.
    construct an injection from even permutations to odd permutations (i0, i1, i2, ..., iN)-->(i1, i0, i2, ..., iN), thus n(e)<=n(o).
    the reverse injection indicates n(o)<=n(e).
    */
    Group<Permutation>::elements().resize(n);
    JohnsonTrotterPermutator jt;
    VVI res = jt.runEven(N);
    dict_sort(res);
    for (size_t i = 0; i < n; ++i) {
      Group<Permutation>::element(i) = std::move(Permutation(res[i]));
    }/// for
  }/// constructor
};/// class AlternatingGroup

}/// namespace PlanarGraphColoring
