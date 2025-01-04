/// _test_birkhoff_diamond_kempe_chain_interchanger.cxx

#include "../../relation/birkhoff_diamond_relation_builder.h"
#include "birkhoff_diamond_kempe_chain_interchanger.h"
#include "../naive_color_representation.h"
#include "../birkhoff_diamond_color_judger.h"
#include "../../basic/notation.h"

using namespace PlanarGraphColoring;

/// test_3()
TEST_START(3)
  BirkhoffDiamondRelationBuilder builder;
  RelationManager manager;
  builder.run(&manager);
  BirkhoffDiamond diamond;
  NaiveColorRepresentation coloring({0, 1, 2, 3, 1, 2, 9, 9, 9, 9});
  auto table_ptr = manager.getColorResult()->findConstPtr(coloring.getVector(), diamond.boundarySize());
  INFO_OBJ(*table_ptr)
  BirkhoffDiamondColorJudger judger;
  bool res = false;
  if (judger.isValid(*table_ptr)) {
    INFO << "valid coloring need not interchange\n";
    res = true;
  } else {
    /// WARNING: running one case will fail
    BirkhoffDiamondKempeChainInterchanger interchanger;
    KempeChainResult result;
    std::unordered_set<const ColorRepresentation*> valid_table;
    res = interchanger.run(diamond, coloring, *(manager.getColorResult()), &result, &valid_table);
    INFO << "invalid coloring need interchange\n";
    INFO_OBJ(result)
  }
  /// TODO: debug res=false
TEST_END(3)
/// test_3()

void test_2() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
  BirkhoffDiamondRelationBuilder builder;
  RelationManager manager;
  builder.run(&manager);
  BirkhoffDiamond diamond;
  NaiveColorRepresentation coloring({0, 1, 0, 1, 0, 1, 9, 9, 9, 9});
  auto table_ptr = manager.getColorResult()->findConstPtr(coloring.getVector(), diamond.boundarySize());
  INFO_OBJ(*table_ptr)
  BirkhoffDiamondColorJudger judger;
  bool res = false;
  if (judger.isValid(*table_ptr)) {
    INFO << "valid coloring need not interchange\n";
    res = true;
  } else {
    BirkhoffDiamondKempeChainInterchanger interchanger;
    KempeChainResult result;
    std::unordered_set<const ColorRepresentation*> valid_table;
    res = interchanger.run(diamond, coloring, *(manager.getColorResult()), &result, &valid_table);
    INFO << "invalid coloring need interchange\n";
  }
  PGC__TEST_RESULT_INFO(res, 2)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
}/// test_2

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  BirkhoffDiamondRelationBuilder builder;
  RelationManager manager;
  builder.run(&manager);
  BirkhoffDiamond diamond;
  NaiveColorRepresentation coloring({0, 1, 2, 1, 0, 2, 9, 9, 9, 9});
  auto table_ptr = manager.getColorResult()->findConstPtr(coloring.getVector(), diamond.boundarySize());
  INFO_OBJ(*table_ptr)
  BirkhoffDiamondColorJudger judger;
  bool res = false;
  if (judger.isValid(*table_ptr)) {
    INFO << "valid coloring need not interchange\n";
    res = true;
  } else {
    BirkhoffDiamondKempeChainInterchanger interchanger;
    KempeChainResult result;
    std::unordered_set<const ColorRepresentation*> valid_table;
    res = interchanger.run(diamond, coloring, *(manager.getColorResult()), &result, &valid_table);
    INFO << "invalid coloring need interchange\n";
  }
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamondRelationBuilder builder;
  RelationManager manager;
  builder.run(&manager);
  BirkhoffDiamond diamond;
  NaiveColorRepresentation coloring({0, 1, 2, 1, 0, 2, 9, 9, 9, 9});
  DEBUG_OBJ(coloring)
  const II kempe_vertices = {1, 5};
  BirkhoffDiamondKempeChainInterchanger interchanger;
  KempeChainResult result;
  std::unordered_set<const ColorRepresentation*> valid_table;
  interchanger.run(diamond, coloring, *(manager.getColorResult()), kempe_vertices, &result, &valid_table);
  INFO_OBJ(result)
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  //test_0();
  //test_1();
  //test_2();
  TEST(3)
PGC__MAIN_END
