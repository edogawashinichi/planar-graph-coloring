/// symmetry_group.h

/// a symmetry group is a group whose elements are permutations

#pragma once

#include "group.h"
#include "permutation.h"

namespace PlanarGraphColoring {

class SymmetryGroup : public Group<Permutation> {
public:
  inline SymmetryGroup() = default;
  SymmetryGroup(const size_t N);
  size_t product(const VI& element_indices) const;
  virtual std::vector<Permutation> orbit(const Permutation& element) const override;
  virtual VI orbit(const size_t element_index) const override;
  size_t getIndex(const VI& element) const;
  VI getIndices(const VVI& elements) const;
  virtual void show() const override;
  virtual const Permutation& unit() const override;
  virtual const Permutation& inverse(const Permutation& e) const override;
  virtual const Permutation& multiply(const Permutation& e, const Permutation& f) const override;
};/// class SymmetryGroup

}/// namespace PlanarGraphColoring
