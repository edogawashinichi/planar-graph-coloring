/// _test_math.cxx

#include "math.h"
#include "notation.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const std::vector<int> X = {2, 5, 7};
  const std::vector<int> f = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
  std::vector<int> Y(X.size(), 0);
  map<int>(X, f, &Y);
  const std::vector<int> Z = {4, 25, 49};
  bool res = (Y == Z);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  const std::vector<int> A = {1, 3, 5, 7, 8};
  const std::vector<int> B = {2, 3, 8};
  std::vector<int> C;
  diff<int>(A, B, &C);
  const std::vector<int> D = {1, 5, 7};
  bool res = (C == D);
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  bool res = (id<int>(5) == std::vector({0, 1, 2, 3, 4}));
TEST_END(2)
/// test_2

/// test_3
TEST_START(3)
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
TEST_END(3)
/// test_3

/// test_4
TEST_START(4)
  VVI data = {
    {1, 2,},
    {4, 5, 6},
    {},
    {8, 9, 0}
  };
  cycle_sort(data, 10);
  INFO << "after ascend cycle sort:\n";
  INFO_VVI_WITH_INDEX(data)
  const VVI exp_ascend = {
    {},
    {8, 9, 0},
       {1, 2},
    {4, 5, 6},
  };
  bool res = (exp_ascend == data);
  cycle_sort(data, 10, false);
  INFO << "after descend cycle sort:\n";
  INFO_VVI_WITH_INDEX(data)
  const VVI exp_descend = {
    {6, 5, 4},
    {2, 1},
    {0, 9, 8},
    {}
  };
  res = res && (exp_descend == data);
TEST_END(4)
/// test_4

/// test_5
TEST_START(5)
  bool res = (cap<size_t>({}, {}) == false);
  res = res && (cap<size_t>({}, {0, 1, 2}) == false);
  res = res && (cap<size_t>({1, 2, 3}, {4, 5, 5, 3}) == true);
TEST_END(5)
/// test_5

/// test_6
TEST_START(6)
  bool res = (combination(1, 1) == 1);
  res = res && (combination(2, 0) == 1);
  res = res && (combination(3, 2) == 3);
  res = res && (combination(4, 2) == 6);
  res = res && (combination(5, 5) == 1);
  res = res && (combination(6, 3) == 20);
TEST_END(6)
/// test_6

PGC__MAIN_START
  test_0();
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  TEST(6)
PGC__MAIN_END
