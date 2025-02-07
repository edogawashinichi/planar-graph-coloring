/// vertex_symmetry_coloring_actor.h

#pragma once

#include "../permutation.h"
#include "../../color/coloring_result.h"
#include "../../basic/notation.h"

namespace PlanarGraphColoring {

class VertexSymmetryColoringActor {
SINGLETON_ASSERTION(VertexSymmetryColoringActor)
public:
  inline void run(const Coloring& coloring, const Permutation& vertex_permutation, Coloring* transformed_coloring) {
    transformed_coloring->resize(coloring.size());
    for (size_t i = 0; i < coloring.size(); ++i) {
      transformed_coloring->get(vertex_permutation.getConst(i)) = coloring.getConst(i);
    }
  }/// run
};/// class VertexSymmetryColoringActor

}/// namespace PlanarGraphColoring
