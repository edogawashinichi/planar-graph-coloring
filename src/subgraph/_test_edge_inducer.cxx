/// _test_edge_inducer.cxx

#include "edge_inducer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamond diamond;
  DEBUG << "birkhoff diamond:\n";
  if (PGC__DEBUG_MODE) diamond.show();
  const VII edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}};
  DEBUG << "induce edges:\n";
  PGC__DEBUG_VII(edges)
  EdgeInducer inducer;
  Graph result;
  inducer.run(diamond, edges, &result);
  INFO << "RESULT: \n";
  result.show();
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
