/// alternating_group.h

/// an alternating group is a group of even permutations

#pragma once

#include "symmetry_group.h"
#include "permutator/johnson_trotter.h"

namespace PlanarGraphColoring {

template<size_t N>
class AlternatingGroup : public SymmetryGroup<N> {
public:
  inline AlternatingGroup() {
    const size_t n = fact(N) / 2;
    /*
    Proposition: the number of all even permutations is equal to the number of all odd permutations of order N.
    Proof: denote them by n(e) and n(o) respectively.
    construct an injection from even permutations to odd permutations (i0, i1, i2, ..., iN)-->(i1, i0, i2, ..., iN), thus n(e)<=n(o).
    the reverse injection indicates n(o)<=n(e).
    */
    Group<Permutation>::elements().resize(n);
    JohnsonTrotter jt;
    VVI res = jt.runEven(N);
    for (size_t i = 0; i < n; ++i) {
      Group<Permutation>::element(i) = std::move(Permutation(res[i]));
    }/// for
  }/// constructor default
};/// class AlternatingGroup

}/// namespace PlanarGraphColoring
