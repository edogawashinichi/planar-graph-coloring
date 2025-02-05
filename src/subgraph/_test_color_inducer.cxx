/// _test_color_inducer.cxx

#include "color_inducer.h"
#include "../color/naive_color_representation.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamond diamond;
  DEBUG_OBJ(diamond)
  const std::vector<size_t> coloring_data = {0, 1, 2, 3, 2,0, 1, 0, 1, 2};
  NaiveColorRepresentation coloring(coloring_data);
  DEBUG_OBJ(coloring)
  const std::vector<size_t> colors = {0, 1};
  DEBUG << "induce colors:\n";
  PGC__DEBUG_VEC(std::cout, colors)
  ColorInducer inducer;
  Graph result;
  inducer.run(diamond, coloring, colors, &result);
  INFO_OBJ(result)
  bool res = true;
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  BirkhoffDiamond diamond;
  DEBUG_OBJ(diamond)
  const std::vector<size_t> coloring_data = {0, 1, 2, 3, 2, 0, 1, 0, 1, 2};
  NaiveColorRepresentation coloring(coloring_data);
  DEBUG_OBJ(coloring)
  const II vertices = {1, 4};
  const II colors = {1, 2};
  DEBUG << "inducing vertices:\n";
  DEBUG_2VAR(vertices.first, vertices.second)
  DEBUG << "inducing colors:\n";
  DEBUG_PAIR(colors)
  ColorInducer inducer;
  KempeChain result;
  inducer.run(diamond, coloring, vertices, colors, &result);
  INFO_OBJ(result)
  const VVI exp = {
    {1, 2},
    {4}
  };
  bool res = (result.getConst() == exp);
TEST_END(1)
/// test_1

PGC__MAIN_START
  test_0();
  test_1();
PGC__MAIN_END
