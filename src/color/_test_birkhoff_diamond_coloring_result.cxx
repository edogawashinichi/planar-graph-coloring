/// _test_birkhoff_diamond_coloring_result.cxx

#include "birkhoff_diamond_coloring_result.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondColoringResult result;
  INFO_OBJ(*result.getBoundaryColorings())
  INFO_OBJ(*result.getInteriorColorings())
  bool res = true;
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  BirkhoffDiamondColoringResult result;
  auto boundary_colorings = result.getBoundaryColorings();
  auto interior_colorings = result.getInteriorColorings();
  const VVI boundary_data = {
    {0, 1, 0, 1, 0, 1},
    {0, 1, 2, 3, 0, 1}
  };
  const VVI interior_data = {
    {9, 9, 9, 9},
    {3, 0, 1, 2}
  };
  boundary_colorings->set(boundary_data);
  interior_colorings->set(interior_data);
  INFO_OBJ(*boundary_colorings)
  INFO_OBJ(*interior_colorings)
  bool res = true;
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  BirkhoffDiamondColoringResult result;
  auto boundary_colorings = result.getBoundaryColorings();
  auto interior_colorings = result.getInteriorColorings();
  const VVI boundary_data = {
    {0, 1, 0, 1, 0, 1},
    {0, 1, 2, 3, 0, 1}
  };
  const VVI interior_data = {
    {9, 9, 9, 9},
    {3, 0, 1, 2}
  };
  boundary_colorings->set(boundary_data);
  interior_colorings->set(interior_data);
  INFO_OBJ(result)
  bool res = true;
TEST_END(2)
/// test_2

PGC__MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
PGC__MAIN_END
