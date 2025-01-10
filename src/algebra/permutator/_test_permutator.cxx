/// _test_permutator.cxx

#include "johnson_trotter.h"
#include "next_iter.h"
#include "../../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const size_t N = 4;
  JohnsonTrotter jt;
  Permutator* p = &jt;
  const VVI& vvi = p->run(N);
  INFO_VVI_WITH_INDEX(vvi)
  bool res = (vvi.size() == fact(N));
  res = res && distinct(vvi);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  const size_t N = 5;
  JohnsonTrotter jt;
  Permutator* p = &jt;
  const VVI& vvi = p->run(N);
  INFO_VVI_WITH_INDEX(vvi)
  bool res = (vvi.size() == fact(N));
  res = res && distinct(vvi);
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  const size_t N = 4;
  NextIter ni;
  Permutator* p = &ni;
  const VVI& vvi = p->run(N);
  INFO_VVI_WITH_INDEX(vvi)
  bool res = (vvi.size() == fact(N));
  res = res && distinct(vvi);
TEST_END(2)
/// test_2

/// test_3
TEST_START(3)
  const size_t N = 5;
  NextIter ni;
  Permutator* p = &ni;
  const VVI& vvi = p->run(N);
  INFO_VVI_WITH_INDEX(vvi)
  bool res = (vvi.size() == fact(N));
  res = res && distinct(vvi);
TEST_END(3)
/// test_3

/// test_4
TEST_START(4)
  const size_t N = 6;
  JohnsonTrotter jt;
  NextIter ni;
  Permutator* p = &jt;
  VVI res_jt = p->run(N);
  dict_sort(res_jt);
  p = &ni;
  VVI res_ni = p->run(N);
  bool res = (equal(res_jt, res_ni));
TEST_END(4)
/// test_4

PGC__MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
  TEST(3)
  TEST(4)
PGC__MAIN_END
