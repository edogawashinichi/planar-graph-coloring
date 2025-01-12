/// _test_permutation.cxx

#include "permutation.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const VI aa = {0, 1, 2, 3};
  const VI bb = {0, 2, 1, 3};
  const VI cc = {0, 2, 3, 1};
  Permutation a(aa);
  Permutation b(bb);
  Permutation c(cc);
  INFO_OBJ(a)
  INFO_OBJ(b)
  INFO_OBJ(c)
  const Permutation& b_dot_c = b * c;
  const Permutation& c_dot_b = c * b;
  INFO_OBJ(b_dot_c)
  INFO_OBJ(c_dot_b)
  bool res = (a.id() && !b.id() && !c.id());
  res = res && (b_dot_c != c_dot_b);
  const size_t a_order = a.order();
  const size_t b_order = b.order();
  const size_t c_order = c.order();
  INFO_3VAR(a_order, b_order, c_order)
  res = res && (a_order == 1) && (b_order == 2) && (c_order == 3);
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
