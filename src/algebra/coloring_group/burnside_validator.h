/// burnside_validator.h

/// to validate Burnside Lemma on coloring groups

#pragma once

#include "coloring_group.h"
#include "vertex_symmetry_coloring_actor.h"
#include "color_symmetry_coloring_actor.h"
#include "../../topology/ring.h"
#include "../../color/ring_coloring_result.h"
#include "../../basic/notation.h"

namespace PlanarGraphColoring {

template<typename VertexSymmetryGroup>
class BurnsideValidator {
SINGLETON_ASSERTION(BurnsideValidator)
public:
  inline size_t run(const ColoringGroup<VertexSymmetryGroup>& coloring_group, const RingColoringResult& colorings) {
    DEBUG_START(BurnsideValidator::run)
    size_t res = 0;
    for (size_t group_index = 0; group_index < coloring_group.size(); ++group_index) {
      VI fixed_colorings;
      const size_t cnt = this->invariant(coloring_group, group_index, colorings, &fixed_colorings);
      DEBUG_VEC_HINT(fixed_colorings)
      res += cnt;
      DEBUG_2VAR(group_index, res)
    }/// for
    res /= coloring_group.size();
    INFO_VAR(res)
    DEBUG_END(BurnsideValidator::run)
    return res;
  }/// run
  inline size_t invariant(const ColoringGroup<VertexSymmetryGroup>& coloring_group, const size_t index, const RingColoringResult& colorings, VI* fixed_colorings) {
    DEBUG_START(BurnsideValidator::invariant)
    size_t res = 0;
    fixed_colorings->clear();
    const II& pair = coloring_group.transformIndex(index);
    const Permutation& vertex_permutation = coloring_group.constVertexPermutation(pair.first);
    const Permutation& color_permutation = coloring_group.constColorPermutation(pair.second);
    for (size_t colorings_index = 0; colorings_index < colorings.size(); ++colorings_index) {
      const RingColoring& coloring = colorings.getConst(colorings_index);
      Coloring intermediate_coloring;
      VertexSymmetryColoringActor::getInstance().run(coloring.constBoundaryColoring(), vertex_permutation, &intermediate_coloring);
      Coloring transformed_coloring;
      ColorSymmetryColoringActor::getInstance().run(intermediate_coloring, color_permutation, &transformed_coloring);
      if (coloring.constBoundaryColoring() == transformed_coloring) {
        ++res;
        fixed_colorings->emplace_back(colorings_index);
      }/// if
      DEBUG_2VAR(colorings_index, res)
    }/// for
    DEBUG_END(BurnsideValidator::invariant)
    return res;
  }/// invariant
};/// class BurnsideValidator

}/// namespace PlanarGraphColoring
