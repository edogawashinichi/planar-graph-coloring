/// _test_ring_coloring_result.cxx

#include "ring_coloring_result.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  RingColoring coloring;
  INFO_(coloring)
  bool res = true;
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  const VI boundary_data = {0, 1, 2, 3, 0, 9};
  const VI interior_data = {0, 9, 7, 1};
  RingColoring coloring(boundary_data, interior_data);
  INFO_(coloring)
  bool res = (coloring.size() == boundary_data.size() + interior_data.size());
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  const VVI boundary = {
    {0, 1, 2, 3, 4, 5},
    {0, 1, 0, 1, 0, 1},
    {9, 3, 2, 9, 3, 2}
  };
  const VVI interior = {
    {9, 9, 9, 9},
    {9, 1, 9, 1},
    {0, 9, 9, 0}
  };
  RingColoringResult colorings(boundary, interior);
  INFO_(colorings)
  bool res = (colorings.size() == boundary.size());
TEST_END(2)
/// test_2
  
PGC__MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
PGC__MAIN_END
