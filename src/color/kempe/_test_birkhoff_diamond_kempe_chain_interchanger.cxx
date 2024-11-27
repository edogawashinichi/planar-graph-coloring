/// _test_birkhoff_diamond_kempe_chain_interchanger.cxx

#include "birkhoff_diamond_kempe_chain_interchanger.h"
#include "../naive_color_representation.h"
#include "../../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamond diamond;
  NaiveColorRepresentation coloring({0, 1, 2, 1, 0, 2, 9, 9, 9, 9});
  if (PGC__DEBUG_MODE) coloring.show();
  const II kempe_vertices = {1, 5};
  const II separated_vertices = {0, 2};
  DEBUG_2VAR(kempe_vertices.first, kempe_vertices.second)
  DEBUG_2VAR(separated_vertices.first, separated_vertices.second)
  ColorResult result;
  BirkhoffDiamondKempeChainInterchanger interchanger;
  interchanger.run(diamond, coloring, kempe_vertices, separated_vertices, &result);
  INFO << "RESULT:\n";
  result.show();
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
