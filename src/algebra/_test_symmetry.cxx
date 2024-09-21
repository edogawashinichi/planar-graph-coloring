/// _test_symmetry.cxx

#include "symmetry.h"
#include "../basic/notation.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  const std::vector<std::vector<int>> mappers = {
    {0, 1, 2, 3}, /// identity
    {3, 0, 1, 2}, /// rotate 90 degrees counterclockwise (or 270 degrees clockwise)
    {2, 3, 0, 1}, /// rotate 180 degrees
    {1, 2, 3, 0}, /// rotate 270 degrees counterclockwise (or 90 degrees clockwise)
    {2, 1, 0, 3}, /// flip around y-axis
    {0, 3, 2, 1}, /// flip around x-axis
    {1, 0, 3, 2}, /// flip around y=x
    {3, 2, 1, 0} /// flip around y=-x
  };
  VertexSymmetry vs(mappers);
  vs.show();
  bool res = true;
  for (size_t i = 0; i < vs.size(); ++i) {
    std::vector<int> mapper = vs.get(i);
    if (mapper != mappers[i]) {
      std::cout << "get(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      std::cout << "get(" << i << ") passed!\n";
    }
  }/// for
  if (res) {
    PGC__SHOW_ENDL(PGC__TEST_PASS_INFO(0))
  } else {
    PGC__SHOW_ENDL(PGC__TEST_FAIL_INFO(0))
  }
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  const std::vector<std::vector<int>> mappers = {
    {0, 1, 2, 3}, /// identity
    {3, 0, 1, 2}, /// rotate 90 degrees counterclockwise (or 270 degrees clockwise)
    {2, 3, 0, 1}, /// rotate 180 degrees
    {1, 2, 3, 0}, /// rotate 270 degrees counterclockwise (or 90 degrees clockwise)
    {2, 1, 0, 3}, /// flip about y-axis
    {0, 3, 2, 1}, /// flip about x-axis
    {1, 0, 3, 2}, /// flip about y=x
    {3, 2, 1, 0} /// flip about y=-x
  };
  VertexSymmetry vs;
  vs.set(mappers);
  vs.show();
  bool res = true;
  for (size_t i = 0; i < vs.size(); ++i) {
    std::vector<int> mapper = vs.get(i);
    if (mapper != mappers[i]) {
      std::cout << "get(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      std::cout << "get(" << i << ") passed!\n";
    }
  }/// for
  if (res) {
    PGC__SHOW_ENDL(PGC__TEST_PASS_INFO(1))
  } else {
    PGC__SHOW_ENDL(PGC__TEST_FAIL_INFO(1))
  }
    PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

int main(int argc, char* argv[]) {
  test_0();
  test_1();
  return 0;
}
