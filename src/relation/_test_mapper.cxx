/// _test_mapper.cxx

#include "mapper.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  Mapper m;
  const std::vector<std::vector<size_t>> vv = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 2, 0},
    {2, 1, 2},
    {3, 2, 1},
    {4, 2, 0},
    {5, 1, 2},
    {6, 2, 1},
    {7, 2, 0}
  };
  for (const auto& v : vv) {
    m.insert(v[0], v[1], v[2]);
  }
  m.show(5);
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
