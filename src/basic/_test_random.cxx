/// _test_random.cxx

#include "random.h"
#include "notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  float p = 0.001;
  INFO_VAR(p)
  bool res = (bet(p) == false);
  INFO_VAR(res)
  p = 0.999;
  INFO_VAR(p)
  res = res && (bet(p) == true);
  INFO_VAR(res)
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
