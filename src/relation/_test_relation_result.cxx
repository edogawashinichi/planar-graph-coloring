/// _test_relation_result.cxx

#include "relation_result.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  const std::vector<size_t> mapper = {1, 2, 0};
  Relation r(0, 1, 0, mapper);
  r.show();
  RelationResult rr;
  const size_t n = 10;
  for (size_t i = 0; i < n; ++i) {
    rr.append(r);
  }
  rr.show(5);
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
