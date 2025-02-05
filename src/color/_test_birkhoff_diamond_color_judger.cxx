/// _test_birkhoff_diamond_color_judger.cxx

#include "birkhoff_diamond_color_judger.h"
#include "naive_color_representation.h"
#include "color_transformer.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondColorJudger bdcj;
  const std::vector<size_t> l0 = {0, 1, 2, 3, 0, 1};
  const std::vector<size_t> r0 = {3, 2, 1, 0, 1, 0};
  const NaiveColorRepresentation lhs0(l0);
  const NaiveColorRepresentation rhs0(r0);
  bool res = (true == bdcj.isIsomorphismByVertexSymmetry(lhs0, rhs0));
  const std::vector<size_t> l1 = {0, 1, 2, 3, 0, 1};
  const std::vector<size_t> r1 = {3, 2, 1, 0, 0, 1};
  const NaiveColorRepresentation lhs1(l1);
  const NaiveColorRepresentation rhs1(r1);
  res = res && (false == bdcj.isIsomorphismByVertexSymmetry(lhs1, rhs1));
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  BirkhoffDiamondColorJudger bdcj;
  const std::vector<size_t> l0 = {0, 1, 2, 3, 0, 1};
  const std::vector<size_t> r0 = {3, 2, 0, 1, 3, 2};
  const NaiveColorRepresentation lhs0(l0);
  const NaiveColorRepresentation rhs0(r0);
  bool res = (true == bdcj.isIsomorphismByColorSymmetry(lhs0, rhs0));
  const std::vector<size_t> l1 = {0, 1, 2, 3, 0, 1};
  const std::vector<size_t> r1 = {3, 2, 1, 0, 0, 1};
  const NaiveColorRepresentation lhs1(l1);
  const NaiveColorRepresentation rhs1(r1);
  res = res && (false == bdcj.isIsomorphismByColorSymmetry(lhs1, rhs1));
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  BirkhoffDiamondColorJudger judger;
  const NaiveColorRepresentation lhs({0, 1, 0, 1, 0, 3});
  const NaiveColorRepresentation rhs({0, 1, 0, 1, 0, 2});
  DEBUG_OBJ(lhs)
  DEBUG_OBJ(rhs)
  VI mapper;
  bool res = judger.isIsomorphismByColorSymmetry(lhs, rhs, &mapper);
  INFO_VAR(res)
  INFO_VEC(mapper)
  res = res && (mapper == VI({0, 1, 3, 2}));
TEST_END(2)
/// test_2

/// test_3
TEST_START(3)
  BirkhoffDiamondColorJudger judger;
  const NaiveColorRepresentation lhs({0, 1, 0, 2, 3, 1});
  const NaiveColorRepresentation rhs({0, 3, 0, 1, 2, 3});
  DEBUG_OBJ(lhs)
  DEBUG_OBJ(rhs)
  VI mapper;
  bool res = judger.isIsomorphismByColorSymmetry(lhs, rhs, &mapper);
  INFO_VAR(res)
  INFO_VEC(mapper)
  res = res && (mapper == VI({0, 3, 1, 2}));
  VI imapper;
  ColorTransformer transformer;
  transformer.inverseColorSymmetry(mapper, &imapper);
  INFO_VEC(imapper)
  res = res && (imapper == VI({0, 2, 3, 1}));
TEST_END(3)
/// test_3

PGC__MAIN_START
  test_0();
  test_1();
  TEST(2)
  TEST(3)
PGC__MAIN_END
