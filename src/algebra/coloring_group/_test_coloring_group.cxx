/// _test_coloring_group.cxx

#include "birkhoff_diamond_coloring_group.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondColoringGroup G;
  INFO_OBJ(G)
  bool res = (G.size() == 4 * fact(COLORS));
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
