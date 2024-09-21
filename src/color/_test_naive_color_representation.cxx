/// _test_naive_color_representation.cxx

#include "naive_color_representation.h"
#include "../basic/notation.h"
#include <vector>
#include <iostream>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  NaiveColorRepresentation ncr;
  std::vector<int> data = {
    1, 0, 1, 2, 1, 3
  };
  for (size_t i = 0; i < data.size(); ++i) {
    ncr.set(i, data[i]);
  }
  ncr.show();
  bool res = true;
  for (size_t i = 0; i < data.size(); ++i) {
    if (ncr.get(i) != data[i]) {
      std::cout << "get(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      std::cout << "get(" << i << ") passed!\n";
    }
  }/// for
  if (ncr.getVector() != data) {
    std::cout << "getVector failed!\n";
    res = false;
  } else {
    std::cout << "getVector passed!\n";
  }
  if (res) {
    PGC__SHOW_ENDL(PGC__TEST_PASS_INFO(0))
  } else {
    PGC__SHOW_ENDL(PGC__TEST_FAIL_INFO(0))
  }
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

int main(int argc, char* argv[]) {
  test_0();
  return 0;
}
