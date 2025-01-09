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
  N5.show();
  bool res = true;
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
