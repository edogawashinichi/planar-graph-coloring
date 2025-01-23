/// _test_symmetry_group.cxx

#include "symmetry_group.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  SymmetryGroup S4(4);
  INFO_OBJ(S4)
  bool res = (S4.size() == fact(4));
  const VI permutation = {0, 1, 3, 2};
  const int index = S4.index(permutation);
  INFO_VAR(index)
  res = res && (index == 1);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  SymmetryGroup S7(7);
  DEBUG_OBJ(S7)
  bool res = (S7.size() == fact(7));
TEST_END(1)
/// test_1

PGC__MAIN_START
  TEST(0)
  TEST(1)
PGC__MAIN_END
