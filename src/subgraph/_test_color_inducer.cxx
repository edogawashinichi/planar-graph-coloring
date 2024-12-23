/// _test_color_inducer.cxx

#include "color_inducer.h"
#include "../color/naive_color_representation.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamond diamond;
  DEBUG << "birkhoff diamond:\n";
  if (PGC__DEBUG_MODE) diamond.show();
  const std::vector<size_t> coloring_data = {0, 1, 2, 3, 2,0, 1, 0, 1, 2};
  NaiveColorRepresentation coloring(coloring_data);
  DEBUG << "coloring:\n";
  if (PGC__DEBUG_MODE) coloring.show();
  const std::vector<size_t> colors = {0, 1};
  DEBUG << "induce colors:\n";
  PGC__DEBUG_VEC(colors)
  ColorInducer inducer;
  Graph result;
  inducer.run(diamond, coloring, colors, &result);
  INFO << "RESULT: \n";
  result.show();
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  BirkhoffDiamond diamond;
  DEBUG << "birkhoff diamond:\n";
  DEBUG_OBJ(diamond)
  const std::vector<size_t> coloring_data = {0, 1, 2, 3, 2, 0, 1, 0, 1, 2};
  NaiveColorRepresentation coloring(coloring_data);
  DEBUG << "coloring:\n";
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
  INFO << "RESULT: \n";
  INFO_OBJ(result)
  const VVI exp = {
    {1, 2},
    {4}
  };
  bool res = (result.getConst() == exp);
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

PGC__MAIN_START
  test_0();
  test_1();
PGC__MAIN_END
