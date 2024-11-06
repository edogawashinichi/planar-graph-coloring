/// _test_symmetry.cxx

#include "symmetry.h"
#include "../basic/notation.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  const std::vector<std::vector<size_t>> mappers = {
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
    std::vector<size_t> mapper = vs.get(i);
    if (mapper != mappers[i]) {
      DEBUG << "get(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      DEBUG << "get(" << i << ") passed!\n";
    }
  }/// for
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  const std::vector<std::vector<size_t>> mappers = {
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
    std::vector<size_t> mapper = vs.get(i);
    if (mapper != mappers[i]) {
      DEBUG << "get(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      DEBUG << "get(" << i << ") passed!\n";
    }
  }/// for
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

void test_2() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
  const std::vector<size_t> input = {2, 3, 4, 1, 0};
  const std::vector<size_t> exp   = {4, 3, 0, 1, 2};
  Transformation t(input);
  std::vector<size_t> output = t.inverse();
  bool res = (output == exp);
  if (PGC__DEBUG_MODE) {
    PGC__SHOW_ENDL("input:")
    PGC__SHOW_VEC_WITH_INDEX(input)
    PGC__SHOW_ENDL("output:")
    PGC__SHOW_VEC_WITH_INDEX(output)
    PGC__SHOW_ENDL("exp:")
    PGC__SHOW_VEC_WITH_INDEX(exp)
  }
  PGC__TEST_RESULT_INFO(res, 2)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
}/// test_2

PGC__MAIN_START
  test_0();
  test_1();
  test_2();
PGC__MAIN_END
