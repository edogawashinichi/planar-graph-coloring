/// _test_symmetry_group.cxx

#include "symmetry_group.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  SymmetryGroup<4> S4;
  INFO_OBJ(S4)
  bool res = (S4.size() == fact(4));
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
