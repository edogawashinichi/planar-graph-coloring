/// _test_birkhoff_diamond_relation_builder.cxx

#include "birkhoff_diamond_relation_builder.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondRelationBuilder builder;
  RelationManager manager;
  builder.run(&manager);
  bool res = (manager.getColorResult()->size() == 732);
  res = res && (manager.getRelationResult()->size() == 18180);
  res = res && (manager.getMapper()->size() == 18180);
  res = res && (manager.getDigraphResult()->getVertexColor()->size() == 732);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  BirkhoffDiamondRelationBuilder builder;
  ColorResult color_result;
  builder.run(&color_result);
  color_result.show(std::cout, 20);
  bool res = (color_result.size() == 732);
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
  BirkhoffDiamondRelationBuilder builder;
  ColorResult color_result;
  builder.run(&color_result);
  color_result.show(std::cout, 20);
  RelationResult relation_result;
  Mapper mapper;
  DigraphResult digraph_result;
  builder.run(color_result, &relation_result, &mapper, &digraph_result);
  relation_result.show(std::cout, 20);
  mapper.show(std::cout, 20);
  digraph_result.show(std::cout);
  bool res = (color_result.size() == 732);
  res = res && (relation_result.size() == 18180);
  res = res && (mapper.size() == 18180);
  res = res && (digraph_result.getVertexColor()->size() == 732);
TEST_END(2)
/// test_2

PGC__MAIN_START
  test_0();
  test_1();
  test_2();
PGC__MAIN_END
