/// _test_birkhoff_diamond_relation_builder.cxx

#include "birkhoff_diamond_relation_builder.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamondRelationBuilder builder;
  RelationManager manager;
  builder.run(&manager);
  bool res = (manager.getColorResult()->size() == 732);
  res = res && (manager.getRelationResult()->size() == 18180);
  res = res && (manager.getMapper()->size() == 18180);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  BirkhoffDiamondRelationBuilder builder;
  ColorResult color_result;
  builder.run(&color_result);
  color_result.show(20);
  bool res = (color_result.size() == 732);
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

void test_2() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
  BirkhoffDiamondRelationBuilder builder;
  ColorResult color_result;
  builder.run(&color_result);
  color_result.show(20);
  RelationResult relation_result;
  Mapper mapper;
  builder.run(color_result, &relation_result, &mapper);
  relation_result.show(20);
  mapper.show(20);
  bool res = (color_result.size() == 732);
  res = res && (relation_result.size() == 18180);
  res = res && (mapper.size() == 18180);
  PGC__TEST_RESULT_INFO(res, 2)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
}/// test_2

PGC__MAIN_START
  test_0();
  //test_1();
  //test_2();
PGC__MAIN_END
