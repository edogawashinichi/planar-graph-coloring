/// _test_coloring_result.cxx

#include "coloring_result.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  Coloring coloring;
  INFO_(coloring)
  bool res = true;
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  const VI data = {0, 1, 2, 3, 0, 9, 2, 1, 3, 0};
  Coloring coloring(data);
  INFO_(coloring)
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
  ColoringResult colorings(data);
  INFO_(colorings)
  bool res = true;
TEST_END(2)
/// test_2
  
/// test_3
TEST_START(3)
  const size_t START = 1;
  const size_t END = 9;
  const VI data = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3};
  Coloring coloring(data);
  Coloring slice(coloring.getCopy(START, END));
  INFO_(slice)
  bool res = (END - START == slice.size());
TEST_END(3)
/// test_3

PGC__MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
  TEST(3)
PGC__MAIN_END
