/// birkhoff_diamond_coloring_group.h

#pragma once

#include "coloring_group.h"
#include "../basic/global.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondColoringGroup : public ColoringGroup {
public:
  inline BirkhoffDiamondColoringGroup() : ColoringGroup(BIRKHOFF_DIAMOND_BOUNDARY_SIZE, COLORS) {}
};/// class BirkhoffDiamondColoringGroup

}/// namespace PlanarGraphColoring
