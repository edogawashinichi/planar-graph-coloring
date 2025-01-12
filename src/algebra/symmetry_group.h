/// symmetry_group.h

/// symmetry group is a group whose elements are permutations

#pragma once

#include "group.h"
#include "permutation.h"
#include "permutator/next_iter.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

template <size_t N>
class SymmetryGroup : public Group<Permutation> {
public:
  inline SymmetryGroup() {
    const size_t n = fact(N);
    Group<Permutation>::elements().resize(n);
    NextIter ni;
    const VVI& res = ni.run(N);
    for (size_t i = 0; i < n; ++i) {
      Group<Permutation>::element(i) = std::move(Permutation(res[i]));
    }
  }/// constructor default
  inline virtual void show() const override {
    TEST_INFO
    for (size_t i = 0; i < Group<Permutation>::size(); ++i) {
      std::cout << i << "th ";
      INFO_OBJ(Group<Permutation>::constElement(i))
    }/// for
  }/// show
  inline virtual const Permutation& unit() const override {
    for (const auto& permutation : Group<Permutation>::constElements()) {
      if (permutation.id()) return permutation;
    }/// for
    return Group<Permutation>::constElement(0);
  }/// unit
  inline virtual const Permutation& inverse(const Permutation& e) const override {
    for (const auto& f : Group<Permutation>::constElements()) {
      if (this->multiply(f, e) == this->unit()) return f;
    }/// for
    return Group<Permutation>::constElement(0);
  }/// inverse
  inline virtual const Permutation& multiply(const Permutation& e, const Permutation& f) const override {
    const Permutation& g = e * f;
    for (const auto& permutation : Group<Permutation>::constElements()) {
      if (permutation == g) return permutation;
    }
    return Group<Permutation>::constElement(0);
  }/// multiply
};/// class SymmetryGroup

}/// namespace PlanarGraphColoring
