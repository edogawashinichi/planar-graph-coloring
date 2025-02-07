/// coloring_actor.h

/// intruduce Burnside Lemma

#pragma once

#include "coloring_group.h"
#include "vertex_symmetry_coloring_actor.h"
#include "color_symmetry_coloring_actor.h"
#include "../../color/ring_coloring_result.h"

namespace PlanarGraphColoring {

template<typename VertexSymmetryGroup>
class ColoringActor {
SINGLETON_ASSERTION(ColoringActor)
public:
  inline void run(const RingColoring& coloring, const RingColoringResult& table, const ColoringGroup<VertexSymmetryGroup>& group, VI* orbit) {
    DEBUG_START(ColoringActor::run VI)
    DEBUG_OBJ(coloring)
    ColoringResult boundary_colorings;
    this->run(coloring.constBoundaryColoring(), group, &boundary_colorings);
    table.findBoundaryColoring(boundary_colorings, orbit);
    DEBUG_VEC(*orbit)
    DEBUG_END(ColoringActor::run VI)
  }/// run
  inline void run(const Coloring& coloring, const ColoringGroup<VertexSymmetryGroup>& group, ColoringResult* orbit) {
    DEBUG_START(ColoringActor::run ColoringResult)
    DEBUG_OBJ(coloring)
    for (size_t i = 0; i < group.size(); ++i) {
      VERBOSE_VAR(i)
      Coloring transformed_coloring(coloring);
      this->run(coloring, group, i, &transformed_coloring);
      VERBOSE_OBJ(transformed_coloring)
      orbit->append(transformed_coloring);
    }
    DEBUG_END(ColoringActor::run ColoringResult)
  }/// run
  inline void run(const RingColoringResult& table, const ColoringGroup<VertexSymmetryGroup>& group, VVI* orbits) {
    DEBUG_START(ColoringActor::run VVI)
    VI visited(table.size(), 0);
    for (size_t i = 0; i < table.size(); ++i) {
      INFO_VAR(i)
      INFO_OBJ(table.getConst(i))
      if (1 == visited[i]) continue;
      visited[i] = 1;
      VI orbit;
      this->run(table.getConst(i), table, group, &orbit);
      for (size_t index : orbit) {
        visited[index] = 1;
      }
      INFO_VEC(orbit)
      orbits->emplace_back(orbit);
    }
    DEBUG_END(ColoringActor::run VVI)
  }/// run
protected:
  inline void run(const Coloring& coloring, const ColoringGroup<VertexSymmetryGroup>& group, const size_t index, Coloring* transformed_coloring) {
    DEBUG_START(ColoringActor::run index)
    const II& pair = group.transformIndex(index);
    const Permutation& vertex_permutation = group.constVertexPermutation(pair.first);
    const Permutation& color_permutation = group.constColorPermutation(pair.second);
    VERBOSE_OBJ(vertex_permutation)
    VERBOSE_OBJ(color_permutation)
    Coloring inter_coloring(coloring);
    VertexSymmetryColoringActor::getInstance().run(coloring, vertex_permutation, &inter_coloring);
    VERBOSE_OBJ(inter_coloring)
    ColorSymmetryColoringActor::getInstance().run(inter_coloring, color_permutation, transformed_coloring);
    DEBUG_OBJ(*transformed_coloring)
    DEBUG_END(ColoringActor::run index)
  }/// run
};/// class ColoringActor

}/// namespace PlanarGraphColoring
