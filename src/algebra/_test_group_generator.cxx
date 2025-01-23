/// _test_group_generator.cxx

#include "symmetry_group_generator.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const size_t N = 4;
  SymmetryGroup S(N);
  INFO_OBJ(S)
  bool res = (S.size() == fact(N));
  const VVI generators = {
    {0, 1, 3, 2}
  };
  SymmetryGroupGenerator SGG;
  SymmetryGroup subgroup;
  SGG.run(S, generators, &subgroup);
  INFO_OBJ(subgroup)
  INFO_VVI_WITH_INDEX(generators)
  res = res && (subgroup.size() == 2);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  const size_t N = 4;
  SymmetryGroup S(N);
  INFO_OBJ(S)
  bool res = (S.size() == fact(N));
  const VVI generators = {
    {1, 2, 3, 0}
  };
  SymmetryGroupGenerator SGG;
  SymmetryGroup subgroup;
  SGG.run(S, generators, &subgroup);
  INFO_OBJ(subgroup)
  INFO_VVI_WITH_INDEX(generators)
  res = res && (subgroup.size() == 4);
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  const size_t N = 4;
  SymmetryGroup S(N);
  INFO_OBJ(S)
  bool res = (S.size() == fact(N));
  const VVI generators = {
    {0, 3, 1, 2}
  };
  SymmetryGroupGenerator SGG;
  SymmetryGroup subgroup;
  SGG.run(S, generators, &subgroup);
  INFO_OBJ(subgroup)
  INFO_VVI_WITH_INDEX(generators)
  res = res && (subgroup.size() == 3);
TEST_END(2)
/// test_2

/// test_3
TEST_START(3)
  const size_t N = 4;
  SymmetryGroup S(N);
  INFO_OBJ(S)
  bool res = (S.size() == fact(N));
  const VVI generators = {
    {0, 1, 2, 3}
  };
  SymmetryGroupGenerator SGG;
  SymmetryGroup subgroup;
  SGG.run(S, generators, &subgroup);
  INFO_OBJ(subgroup)
  INFO_VVI_WITH_INDEX(generators)
  res = res && (subgroup.size() == 1);
TEST_END(3)
/// test_3

PGC__MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
  TEST(3)
PGC__MAIN_END
