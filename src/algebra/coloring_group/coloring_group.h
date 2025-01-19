/// coloring_group.h

/// a coloring group is a direct product: vertex_symmetry_group X color_symmetry_group
/// vertex_symmetry_group: a subgroup of S(vertex_size)
/// color_symmetry_group: S(color_size)
/// right(left) association when acting on colorings, which are equivalent

#pragma once

#include "direct_product.h"
#include "permutation.h"

namespace PlanarGraphColoring {

class ColoringGroup : public DirectProduct<Permutation, Permutation> {
public:
  inline ColoringGroup() = delete;
  inline ColoringGroup(const size_t vertex_order, const size_t color_order) : DirectProduct<Permutation, Permutation>(vertex_order, color_order) {}
  inline virtual void show() const override {
    TEST_INFO
    DirectProduct<Permutation, Permutation>::show();
  }/// show
};/// class ColoringGroup

}/// namespace PlanarGraphColoring
