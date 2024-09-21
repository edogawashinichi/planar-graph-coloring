/// _test_color_result.cxx

#include "color_result.h"
#include "../basic/notation.h"
#include <vector>
#include <iostream>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  ColorResult cr;
  std::vector<int> data = {
    -1, 0, 1, 2, 1, 3
  };
  const size_t N = 800;
  for (size_t i = 0; i < N; ++i) {
    cr.append(data);
  }
  cr.show();
  bool res = true;
  for (size_t i = 0; i < N; ++i) {
    if (cr.getInfo(i) != data) {
      std::cout << "getInfo(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      std::cout << "getInfo(" << i << ") passed!\n";
    }
  }
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  ColorResult cr;
  std::vector<int> data = {
    1, 0, 1, 2, 1, -3
  };
  const size_t N = 800;
  for (size_t i = 0; i < N; ++i) {
    cr.append(data);
  }
  cr.show(20);
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

int main(int argc, char* argv[]) {
  test_0();
  test_1();
  return 0;
}
