/// _test_naive_color_representation.cxx

#include "naive_color_representation.h"
#include "../basic/notation.h"
#include <vector>
#include <iostream>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  NaiveColorRepresentation ncr;
  std::vector<size_t> data = {
    1, 0, 1, 2, 1, 3
  };
  for (size_t i = 0; i < data.size(); ++i) {
    ncr.set(i, data[i]);
  }
  ncr.show();
  bool res = true;
  for (size_t i = 0; i < data.size(); ++i) {
    if (ncr.get(i) != data[i]) {
      DEBUG << "get(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      DEBUG << "get(" << i << ") passed!\n";
    }
  }/// for
  if (ncr.getVector() != data) {
    DEBUG << "getVector failed!\n";
    res = false;
  } else {
    DEBUG << "getVector passed!\n";
  }
  if (res) {
    PGC__SHOW_ENDL(PGC__TEST_PASS_INFO(0))
  } else {
    PGC__SHOW_ENDL(PGC__TEST_FAIL_INFO(0))
  }
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
