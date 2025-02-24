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
    /// TODO: simple/elegant approach to fetch vertex_permutation/color_permutation
    DEBUG_START(ColoringGroup::inverse)
    const II& pair = this->transformIndex(index);
    const Permutation& vertex_permutation = this->constVertexPermutation(pair.first);
    const Permutation& color_permutation = this->constColorPermutation(pair.second);
    const Permutation& vid = g_->unit();
    const Permutation& cid = h_->unit();
    DEBUG_OBJ(vertex_permutation)
    DEBUG_OBJ(color_permutation)
    DEBUG_OBJ(vid)
    DEBUG_OBJ(cid)
    size_t i = 0;
    for (; i < this->size(); ++i) {
      DEBUG_VAR(i)
      const II& i_pair = this->transformIndex(i);/// WARNING: index-->i
      const Permutation& i_vp = this->constVertexPermutation(i_pair.first);
      DEBUG_OBJ(i_vp)
      const Permutation v_prod(i_vp * vertex_permutation);
      DEBUG_OBJ(v_prod)
      if (v_prod != vid) continue;
      const Permutation& i_cp = this->constColorPermutation(i_pair.second);
      DEBUG_OBJ(i_cp)
      const Permutation c_prod(i_cp * color_permutation);
      DEBUG_OBJ(c_prod)
      if (c_prod == cid) break;
    }
    DEBUG_END(ColoringGroup::inverse)
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
  inline virtual void show(std::ostream& cout, const size_t index) const {
    TEST_INFO
    /* assuming: index valid */
    const II& pair = this->transformIndex(index);
    const Permutation& vertex_permutation = this->constVertexPermutation(pair.first);
    const Permutation& color_permutation = this->constColorPermutation(pair.second);
    cout << "vertex_permutation:  ";
    vertex_permutation.show(cout);
    cout << "color_permutation:  ";
    color_permutation.show(cout);
  }/// show
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    cout << "vertex symmetry group:\n";
    g_->show(cout);
    cout << "color symmetry group:\n";
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
