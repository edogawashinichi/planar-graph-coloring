/// test_neighborhood.cxx

#include "neighborhood.h"
#include "../basic/notation.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  Neighborhood<5> N5;
  INFO_OBJ(N5)
  const VII& edges = N5.getEdges();
  bool res = (edges.size() == 10);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  Neighborhood<6> N6;
  INFO_OBJ(N6)
  const VII& edges = N6.getEdges();
  bool res = (edges.size() == 12);
TEST_END(1)
/// test_1

PGC__MAIN_START
  TEST(0)
  TEST(1)
PGC__MAIN_END
