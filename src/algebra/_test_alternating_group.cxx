/// _test_alternating_group.cxx

#include "alternating_group.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  AlternatingGroup<3> A3;
  INFO_OBJ(A3)
  bool res = (A3.size() == fact(3) / 2);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  AlternatingGroup<4> A4;
  INFO_OBJ(A4)
  bool res = (A4.size() == fact(4) / 2);
TEST_END(1)
/// test_1

PGC__MAIN_START
  TEST(0)
  TEST(1)
PGC__MAIN_END
