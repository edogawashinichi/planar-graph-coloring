/// coloring_actor.h

/// introduce Burnside Lemma

#pragma once

#include "coloring_group.h"
#include "coloring_orbit_result.h"
#include "vertex_symmetry_coloring_actor.h"
#include "color_symmetry_coloring_actor.h"
#include "../../color/ring_coloring_result.h"

namespace PlanarGraphColoring {

template<typename VertexSymmetryGroup>
class ColoringActor {
SINGLETON_ASSERTION(ColoringActor)
public:
  inline void run(const RingColoringResult& table, const ColoringGroup<VertexSymmetryGroup>& group, ColoringOrbitResult* orbits) {
    DEBUG_START(ColoringActor::run ColoringOrbitResult)
    ///orbits->resize(table.size()); /// WARNING
    VI visited(table.size(), 0);
    AccColoringResult acc(table.copyBoundaryColoringResult());
    for (size_t i = 0; i < table.size(); ++i) {
      const auto& ring_coloring = table.getConst(i);
      INFO_VAR(i)
      INFO_OBJ(ring_coloring)
      if (1 == visited[i]) {
        INFO << "visited\n";
        continue;
      }
      INFO << "unvisited\n";
      SI orbit;
      this->run(i, table, acc, group, &orbit, orbits);
      INFO_VAR(orbit.size())
      INFO_VAR(orbits->size())
      for (const size_t index : orbit) {
        visited[index] = 1;
      }/// for orbit
    }/// for table.size
    DEBUG_END(ColoringActor::run ColoringOrbitResult)
  }/// run
  inline void run(const RingColoringResult& table, const ColoringGroup<VertexSymmetryGroup>& group, VSI* orbits) {
    DEBUG_START(ColoringActor::run VSI)
    VI visited(table.size(), 0);
    for (size_t i = 0; i < table.size(); ++i) {
      INFO_VAR(i)
      INFO_OBJ(table.getConst(i))
      if (1 == visited[i]) continue;
      visited[i] = 1;
      SI orbit;
      this->run(table.getConst(i), table, group, &orbit);
      for (size_t index : orbit) {
        visited[index] = 1;
      }
      INFO_SET(orbit)
      orbits->emplace_back(orbit);
    }
    DEBUG_END(ColoringActor::run VSI)
  }/// run
protected:
  inline void run(const size_t table_index, const RingColoringResult& table, const AccColoringResult& acc, const ColoringGroup<VertexSymmetryGroup>& group, SI* orbit, ColoringOrbitResult* orbits) {
    DEBUG_START(ColoringActor::run SI ColoringOrbitResult)
    const Coloring& boundary_coloring = table.getConst(table_index).constBoundaryColoring();
    DEBUG_VAR(table_index)
    DEBUG_OBJ(boundary_coloring)
    orbit->clear();
    for (size_t i = 0; i < group.size(); ++i) {
      VERBOSE_2VAR(i, table_index)
      const II& pair = group.transformIndex(i);
      const Permutation& vertex_permutation = group.constVertexPermutation(pair.first);
      const Permutation& color_permutation = group.constColorPermutation(pair.second);
      VERBOSE_OBJ(vertex_permutation)
      VERBOSE_OBJ(color_permutation)
      Coloring inter_coloring;
      VertexSymmetryColoringActor::getInstance().run(boundary_coloring, vertex_permutation, &inter_coloring);
      Coloring transformed_coloring;
      ColorSymmetryColoringActor::getInstance().run(inter_coloring, color_permutation, &transformed_coloring);
      const size_t index = static_cast<size_t>(acc.find(transformed_coloring));
      VERBOSE_OBJ(inter_coloring)
      VERBOSE_OBJ(transformed_coloring)
      VERBOSE_VAR(index)
      /*if (orbit->count(index)) continue;
      VERBOSE << "uncount!\n";*/
      orbit->insert(index);
      const size_t j = group.inverse(i);
      this->append({index, table_index, i, j}, orbits);
      VERBOSE_4VAR(index, table_index, i, j)
    }/// for group.size
    DEBUG_END(ColoringActor::run SI ColoringOrbitResult)
  }/// run
  inline void append(const VI& quadruple, ColoringOrbitResult* orbits) {
    /* assuming: quadruple size == 4 */
    if (quadruple[2] == 0) {
      orbits->append(ColoringInfo(quadruple));
      INFO << "append:  ";
    } else {
      orbits->extend(ColoringInfo(quadruple));
      INFO << "extend:  ";
    }
    INFO_VAR(orbits->size())
  }/// append
  inline void run(const RingColoring& coloring, const RingColoringResult& table, const ColoringGroup<VertexSymmetryGroup>& group, SI* orbit) {
    DEBUG_START(ColoringActor::run SI)
    DEBUG_OBJ(coloring)
    ColoringResult boundary_colorings;
    this->run(coloring.constBoundaryColoring(), group, &boundary_colorings);
    table.findBoundaryColoring(boundary_colorings, orbit);
    DEBUG_SET(*orbit)
    DEBUG_END(ColoringActor::run SI)
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
