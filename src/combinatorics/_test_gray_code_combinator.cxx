/// _test_gray_code_combinator.cxx

#include "gray_code_combinator.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  GrayCodeCombinator combinator;
  Combinator* ptr = &combinator;
  const VVI& output = ptr->run(4, 2);
  INFO_VVI_WITH_INDEX(output)
  bool res = (static_cast<LL>(output.size()) == combination(4, 2));
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  GrayCodeCombinator combinator;
  Combinator* ptr = &combinator;
  const VVI& output = ptr->run(14, 9);
  INFO_VVI_WITH_INDEX(output)
  bool res = (static_cast<LL>(output.size()) == combination(14, 9));
TEST_END(1)
/// test_1

PGC__MAIN_START
  TEST(0)
  TEST(1)
PGC__MAIN_END
