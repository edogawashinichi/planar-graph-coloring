/// _test_integer_group.cxx

#include "integer_group.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const size_t N = 6;
  IntegerGroup<N> G;
  INFO_OBJ(G)
  bool res = (G.size() == N);
  const auto& orbit1 = G.orbit(1);
  INFO_VAR(orbit1.size())
  res = res && (orbit1.size() == N);
  const auto& orbit2 = G.orbit(2);
  INFO_VAR(orbit2.size())
  res = res && (orbit2.size() == N / 2);
  const auto& orbit0 = G.orbit(0);
  INFO_VAR(orbit0.size())
  res = res && (orbit0.size() == 1);
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
