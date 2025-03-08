/// _test_refactor_kempe_chain.cxx

#include "refactor_kempe_chain.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  KempeChainConnector connector;
  bool res = true;
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  bool res = true;
  const II vertices = {0, 1};
  const II colors = {1, 2};
  KempeChainConnector connector(vertices, colors);
  INFO_OBJ(connector)
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  bool res = true;
  KempeChainInfo default_info;
  INFO_OBJ(default_info)
  const II color_pair = {0, 2};
  const KempeChainConnector dual({1, 3}, {1, 3});
  const VI coloring_data = {0, 1, 2, 3, 4, 5};
  const Coloring interchange(coloring_data);
  KempeChainInfo info(color_pair, dual, interchange);
  INFO_OBJ(info)
TEST_END(2)
/// test_2

/// test_3
TEST_START(3)
  bool res = true;
  KempeChainInfoResult default_result;
  INFO_OBJ(default_result)
  const II vertex_pair = {0, 3};
  const II separating_color_pair = {0, 1};
  const II separating_dual_vertex_pair = {1, 4};
  const II separating_dual_color_pair = {2, 3};
  const KempeChainConnector separating_dual(separating_dual_vertex_pair, separating_dual_color_pair);
  const VI separating_interchange_data = {0, 3, 2, 1, 2};
  const Coloring separating_interchange(separating_interchange_data);
  KempeChainInfo separating(separating_color_pair, separating_dual, separating_interchange);
  const II separated_color_pair = {0, 1};
  const II separated_dual_vertex_pair = {1, 4};
  const II separated_dual_color_pair = {2, 3};
  const KempeChainConnector separated_dual(separated_dual_vertex_pair, separated_dual_color_pair);
  const VI separated_interchange_data = {1, 2, 3, 0, 3};
  const Coloring separated_interchange(separated_interchange_data);
  KempeChainInfo separated(separated_color_pair, separated_dual, separated_interchange);
  KempeChainInfoResult result(vertex_pair, separating, separated);
  INFO_OBJ(result)
TEST_END(3)
/// test_3

PGC__MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
  TEST(3)
PGC__MAIN_END
