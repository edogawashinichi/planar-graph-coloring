/// birkhoff_diamond_vertex_symmetry_group.h

/// birkhoff_diamond_vertex_symmetry_group is a subgroup of S(6)
/// generators: (1 5)(2 4), (0 3)(1 4)(2 5)

#pragma once

#include "../symmetry_group.h"
#include "../../basic/global.h"
#include "../symmetry_group_generator.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondVertexSymmetryGroup: public SymmetryGroup {
public:
  inline BirkhoffDiamondVertexSymmetryGroup() : SymmetryGroup() {
    SymmetryGroupGenerator generator;
    /// TODO: optimize by static RingSixSymmetryGroup
    SymmetryGroup S(BIRKHOFF_DIAMOND_BOUNDARY_SIZE);
    const VVI& vvi_generators = {
      {0, 5, 4, 3, 2, 1},
      {3, 4, 5, 0, 1, 2}
    };
    const VI& vi_generators = S.getIndex(vvi_generators);
    generator.run(S, vi_generators, this);
  }/// constructor default
  
};/// class BirkhoffDiamondVertexSymmetryGroup

}/// namespace PlanarGraphColoring
