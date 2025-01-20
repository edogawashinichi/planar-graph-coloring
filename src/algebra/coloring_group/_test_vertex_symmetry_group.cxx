/// _test_vertex_symmetry_group.cxx

#include "birkhoff_diamond_vertex_symmetry_group.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondVertexSymmetryGroup G;
  INFO_OBJ(G)
  bool res = (G.size() == 4);
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
