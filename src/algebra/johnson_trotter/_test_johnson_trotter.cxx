/// _test_johnson_trotter.cxx

#include "johnson_trotter.h"
#include "../../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const size_t N = 4;
  JohnsonTrotter jt;
  const VVI& vvi = jt.run(N);
  INFO_VVI_WITH_INDEX(vvi)
  bool res = (vvi.size() == fact(N));
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
