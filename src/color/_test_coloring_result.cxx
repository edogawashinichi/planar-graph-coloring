/// _test_coloring.cxx

#include "coloring_result.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  Coloring<BIRKHOFF_DIAMOND_SIZE> coloring;
  INFO_OBJ(coloring)
  bool res = true;
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  Coloring<BIRKHOFF_DIAMOND_SIZE> coloring({0, 1, 2, 3, 0, 9, 2, 1, 3, 0});
  INFO_OBJ(coloring)
  bool res = true;
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  const VVI data = {
    {0, 1, 2, 3, 4, 5},
    {0, 1, 0, 1, 0, 1},
    {9, 3, 2, 9, 3, 2}
  };
  ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE> colorings(data);
  INFO_OBJ(colorings)
  bool res = true;
TEST_END(2)
/// test_2

PGC__MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
PGC__MAIN_END
