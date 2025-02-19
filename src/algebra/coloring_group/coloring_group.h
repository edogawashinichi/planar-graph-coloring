/// coloring_group.h

/// a coloring group is a direct product: vertex_symmetry_group X color_symmetry_group
/// vertex_symmetry_group: a subgroup of S(vertex_size)
/// color_symmetry_group: S(color_size)
/// right(left) association when acting on colorings, which are equivalent

#pragma once

#include "../direct_product.h"
#include "../permutation.h"
#include "../symmetry_group.h"

namespace PlanarGraphColoring {

template <typename VertexSymmetryGroup>
class ColoringGroup : public DirectProduct<Permutation, Permutation> {
public:
  inline ColoringGroup() = delete;
  inline ColoringGroup(const size_t color_order) : DirectProduct<Permutation, Permutation>() {
    g_ = std::make_unique<VertexSymmetryGroup>();/// g: vertex symmetry group
    h_ = std::make_unique<SymmetryGroup>(color_order);/// h: color symmetry group
    DimensionTwoVector<size_t>::set(g_->size(), h_->size());
  }/// constructor
  inline size_t inverse(const size_t index) const {
    const II& pair = this->transformIndex(index);
    const Permutation& vertex_permutation = this->constVertexPermutation(pair.first);
    const Permutation& color_permutation = this->constColorPermutation(pair.second);
    const Permutation& vid = g_->unit();
    const Permutation& cid = h_->unit();
    size_t i = 0;
    for (; i < this->size(); ++i) {
      const II& i_pair = this->transformIndex(index);
      const Permutation& i_vp = this->constVertexPermutation(i_pair.first);
      if (i_vp * vertex_permutation != vid) continue;
      const Permutation& i_cp = this->constColorPermutation(i_pair.second);
      if (i_cp * color_permutation == cid) break;
    }
    return i;
  }/// inverse
  inline virtual size_t size() const override {
    return DirectProduct<Permutation, Permutation>::size();
  }/// size
  inline size_t sizeVertexSymmetryGroup() const {
    return g_->size();
  }/// sizeVertexSymmetryGroup
  inline size_t sizeColorSymmetryGroup() const {
    return h_->size();
  }/// sizeColorSymmetryGroup
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    g_->show(cout);
    h_->show(cout);
    INFO_3VAR(this->size(), this->sizeVertexSymmetryGroup(), this->sizeColorSymmetryGroup())
  }/// show
  inline II transformIndex(const size_t index) const {
    /// assuming: index valid
    II res;
    DimensionTwoVector<size_t>::transformIndex(index, &(res.first), &(res.second));
    return res;
  }/// get
  inline const Permutation& constVertexPermutation(const size_t index) const {
    /// assuming: index valid
    return g_->constElement(index);
  }/// constVertexPermutation
  inline const Permutation& constColorPermutation(const size_t index) const {
    /// assuming: index valid
    return h_->constElement(index);
  }/// constColorPermutation
};/// class ColoringGroup

}/// namespace PlanarGraphColoring
