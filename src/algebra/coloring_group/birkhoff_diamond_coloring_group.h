/// birkhoff_diamond_coloring_group.h

#pragma once

#include "coloring_group.h"
#include "birkhoff_diamond_vertex_symmetry_group.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondColoringGroup : public ColoringGroup<BirkhoffDiamondVertexSymmetryGroup> {
public:
  inline BirkhoffDiamondColoringGroup() : ColoringGroup<BirkhoffDiamondVertexSymmetryGroup>(COLORS.size()) {}
};/// class BirkhoffDiamondColoringGroup

}/// namespace PlanarGraphColoring
