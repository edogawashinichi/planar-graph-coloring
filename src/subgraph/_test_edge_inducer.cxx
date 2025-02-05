/// _test_edge_inducer.cxx

#include "edge_inducer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamond diamond;
  DEBUG_OBJ(diamond)
  const VII edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}};
  DEBUG << "induce edges:\n";
  PGC__DEBUG_VII(std::cout, edges)
  EdgeInducer inducer;
  Graph result;
  inducer.run(diamond, edges, &result);
  INFO_OBJ(result)
  bool res = true;
TEST_END(0)
/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
