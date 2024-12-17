/// _test_color_triple.cxx

#include "color_triple.h"
#include "../naive_color_representation.h"
#include "../../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  const VI vec_1 = {0, 1, 0, 1, 0, 1};
  const VI vec_2 = {0, 1, 2, 3, 0, 1};
  const VI vec_3 = {1, 2, 3, 1, 2, 0};
  NaiveColorRepresentation first(vec_1);
  NaiveColorRepresentation second(vec_2);
  NaiveColorRepresentation third(vec_3);
  ColorTriple triple;
  DEBUG << "after triple\n";
  triple.set(first, second, third);
  DEBUG << "after set\n";
  triple.show();
  bool res = (triple.getFirstConst()->getVector() == vec_1);
  res = res && (triple.getSecondConst()->getVector() == vec_2);
  res = res && (triple.getThirdConst()->getVector() == vec_3);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
