/// permutation.h

#pragma once

#include "../basic/structure/dimension_one_vector.h"
#include <ostream>

namespace PlanarGraphColoring {

class Permutation : public DimensionOneVector<size_t> {
public:
  DERIVE_CLASS_5_FUNCTIONS(Permutation, DimensionOneVector<size_t>)
  Permutation(const VI& a);
  void show(std::ostream& cout) const;
  bool id() const;
  size_t order() const;
  VVI getCycles() const;
  /* left assosiation: i-->lhs-->rhs-->j */
  friend Permutation operator*(const Permutation& lhs, const Permutation& rhs);
  friend bool operator==(const Permutation& lhs, const Permutation& rhs);
  friend bool operator!=(const Permutation& lhs, const Permutation& rhs);
  friend std::ostream& operator<<(std::ostream& cout, const Permutation& obj);
};/// class Permutation

}/// namespace PlanarGraphColoring
