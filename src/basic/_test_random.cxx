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

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  const size_t n = 8;
  const size_t k = 4;
  const VI choice(randomChoose(n, k));
  DEBUG_2VAR(n, k)
  INFO_VEC(choice)
  bool res = (choice.size() == k);
  for (size_t i = 0; i < choice.size(); ++i) {
    if (choice[i] >= n) {
      res = false;
      break;
    }/// if
    for (size_t j = i + 1; j < choice.size(); ++j) {
      if (choice[i] == choice[j]) {
        res = false;
        break;
      }/// if
    }/// for j
  }/// for i
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

PGC__MAIN_START
  test_0();
  test_1();
PGC__MAIN_END
