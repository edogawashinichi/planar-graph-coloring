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

PGC__MAIN_START
  TEST(0)
  TEST(1)
PGC__MAIN_END
