/// _test_permutator.cxx

#include "johnson_trotter_permutator.h"
#include "next_iter_permutator.h"
#include "../../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const size_t N = 4;
  JohnsonTrotterPermutator jt;
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
  JohnsonTrotterPermutator jt;
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
  NextIterPermutator ni;
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
  NextIterPermutator ni;
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
  JohnsonTrotterPermutator jt;
  NextIterPermutator ni;
  Permutator* p = &jt;
  VVI res_jt = p->run(N);
  dict_sort(res_jt);
  p = &ni;
  VVI res_ni = p->run(N);
  bool res = (equal(res_jt, res_ni));
TEST_END(4)
/// test_4

/// test_5
TEST_START(5)
  const size_t N = 3;
  JohnsonTrotterPermutator jt;
  VVI res_jt = jt.runEven(N);
  dict_sort(res_jt);
  INFO_VVI_WITH_INDEX(res_jt)
  const VVI exp = {
    {0, 1, 2},
    {1, 2, 0},
    {2, 0, 1}
  };
  bool res = (equal(exp, res_jt));
TEST_END(5)
/// test_5

PGC__MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
  TEST(3)
  TEST(4)
  TEST(5)
PGC__MAIN_END
