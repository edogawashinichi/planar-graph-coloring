/// _test_birkhoff_diamond_kempe_chain_interchanger.cxx

#include "../../relation/birkhoff_diamond_relation_builder.h"
#include "birkhoff_diamond_kempe_chain_interchanger.h"
#include "../naive_color_representation.h"
#include "../../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamondRelationBuilder builder;
  RelationManager manager;
  builder.run(&manager);
  BirkhoffDiamond diamond;
  NaiveColorRepresentation coloring({0, 1, 2, 1, 0, 2, 9, 9, 9, 9});
  DEBUG_OBJ(coloring)
  const II kempe_vertices = {1, 5};
  /// TODO: all vertex pair
  /// TODO: for each classification all members have the same validity
  ColorResult result_if;
  ColorResult result_else;
  BirkhoffDiamondKempeChainInterchanger interchanger;
  interchanger.run(diamond, coloring, kempe_vertices, *(manager.getColorResult()), &result_if, &result_else);
  INFO << "RESULT_IF:\n";
  INFO_OBJ(result_if)
  INFO << "RESULT_ELSE:\n";
  INFO_OBJ(result_else)
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
