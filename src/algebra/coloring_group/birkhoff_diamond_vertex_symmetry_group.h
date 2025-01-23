/// birkhoff_diamond_vertex_symmetry_group.h

/// birkhoff_diamond_vertex_symmetry_group is a subgroup of S(6)
/// generators: (1 5)(2 4), (0 3)(1 4)(2 5)
/// rest elements: (), (0 3)(1 2)(4 5)
/// abelian, dimension: 2, size: 4
/// a = (1 5)(2 4) ........ vertical flip
/// b = (0 3)(1 4)(2 5) ... 180 degrees rotation
/// c = (0 3)(1 2)(4 5) ... horizontal flip
/// e = () ................ unit permutation
/// a * b = b * a = c
/// b * c = c * b = a
/// c * a = a * c = b
/// a * a = b * b = c * c = e

#pragma once

#include "../symmetry_group.h"
#include "../../basic/global.h"
#include "../symmetry_group_generator.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondVertexSymmetryGroup: public SymmetryGroup {
public:
  inline BirkhoffDiamondVertexSymmetryGroup() : SymmetryGroup() {
    SymmetryGroupGenerator generator;
    SymmetryGroup S(BIRKHOFF_DIAMOND_BOUNDARY_SIZE);
    const VVI& generators = {
      {0, 5, 4, 3, 2, 1}, /* (1 5)(2 4) */
      {3, 4, 5, 0, 1, 2}  /* (0 3)(1 4)(2 5) */
    };
    generator.run(S, generators, this);
  }/// constructor default
};/// class BirkhoffDiamondVertexSymmetryGroup

}/// namespace PlanarGraphColoring
