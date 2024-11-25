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

PGC__MAIN_START
  test_0();
PGC__MAIN_END
