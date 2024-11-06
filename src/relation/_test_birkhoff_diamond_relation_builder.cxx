/// _test_birkhoff_diamond_relation_builder.cxx

#include "birkhoff_diamond_relation_builder.h"
#include "../basic/notation.h"
#include "../topology/birkhoff_diamond.h"
#include "../color/birkhoff_diamond_colorer.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamondRelationBuilder bdrb;
  BirkhoffDiamond bd;
  ColorResult cr;
  BirkhoffDiamondColorer bdc;
  bdc.run(bd, &cr);
  RelationManager rm;
  bdrb.run(bd, cr, &rm);
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
