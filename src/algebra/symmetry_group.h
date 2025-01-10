/// symmetry_group.h

#pragma once

#include "group.h"
#include "permutation.h"
#include "permutator/next_iter.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

template <size_t N>
class SymmetryGroup : public Group {
public:
  inline SymmetryGroup() {
    const size_t n = fact(N);
    elements_.resize(n);
    NextIter ni;
    const VVI& res = ni.run(N);
    for (size_t i = 0; i < n; ++i) {
      elements_[i] = std::move(Permutation(res[i]));
    }
  }/// constructor default
  inline virtual void show() const override {
    TEST_INFO
    for (size_t i = 0; i < elements_.size(); ++i) {
      std::cout << i << "th ";
      INFO_OBJ(elements_[i])
    }/// for
  }/// show
protected:
  std::vector<Permutation> elements_;
};/// class SymmetryGroup

}/// namespace PlanarGraphColoring
