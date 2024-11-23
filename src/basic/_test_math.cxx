/// _test_math.cxx

#include "math.h"
#include "notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  const std::vector<int> X = {2, 5, 7};
  const std::vector<int> f = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
  std::vector<int> Y(X.size(), 0);
  map<int>(X, f, &Y);
  const std::vector<int> Z = {4, 25, 49};
  bool res = (Y == Z);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  const std::vector<int> A = {1, 3, 5, 7, 8};
  const std::vector<int> B = {2, 3, 8};
  std::vector<int> C;
  diff<int>(A, B, &C);
  const std::vector<int> D = {1, 5, 7};
  bool res = (C == D);
  PGC__TEST_RESULT_INFO(res, 1) 
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

void test_2() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
  bool res = (id<int>(5) == std::vector({0, 1, 2, 3, 4}));
  PGC__TEST_RESULT_INFO(res, 2) 
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
}/// test_2

void test_3() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(3))
  std::vector<std::vector<size_t>> data = {
    {1, 2, 3},
    {1, 2, 3, 4},
    {1, 1},
    {1, 2, 3},
    {1, 3},
    {1, 2, 2}
  };
  dict_sort(data);
  const std::vector<std::vector<size_t>> exp_ascend = {
    {1, 1},
    {1, 2, 2},
    {1, 2, 3},
    {1, 2, 3},
    {1, 2, 3, 4},
    {1, 3}
  };
  bool res = (exp_ascend == data);
  const std::vector<std::vector<size_t>> exp_descend = {
    {1, 3},
    {1, 2, 3, 4},
    {1, 2, 3},
    {1, 2, 3},
    {1, 2, 2},
    {1, 1}
  };
  dict_sort(data, false);
  res = res && (exp_descend == data);
  PGC__TEST_RESULT_INFO(res, 3)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(3))
}/// test_3

PGC__MAIN_START
  test_0();
  test_1();
  test_2();
  test_3();
PGC__MAIN_END
