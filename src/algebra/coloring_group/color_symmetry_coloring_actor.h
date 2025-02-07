/// color_symmetry_coloring_actor.h

#pragma once

#include "../permutation.h"
#include "../../color/coloring_result.h"
#include "../../basic/notation.h"

namespace PlanarGraphColoring {

class ColorSymmetryColoringActor {
SINGLETON_ASSERTION(ColorSymmetryColoringActor)
public:
  inline void run(const Coloring& coloring, const Permutation& color_permutation, Coloring* transformed_coloring) {
    transformed_coloring->resize(coloring.size());
    for (size_t i = 0; i < coloring.size(); ++i) {
      const size_t color = color_permutation.getConst(coloring.getConst(i).getIndex());
      transformed_coloring->get(i) = std::move(Color(color));
    }
  }/// run
};/// class ColorSymmetryColoringActor

}/// namespace PlanarGraphColoring
