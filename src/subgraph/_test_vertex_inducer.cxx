/// _test_vertex_inducer.cxx

#include "vertex_inducer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamond diamond;
  DEBUG << "birkhoff diamond:\n";
  if (PGC__DEBUG_MODE) diamond.show();
  const std::vector<size_t> vertices = {0, 1, 2, 3, 4, 5};
  DEBUG << "induce vertices:\n";
  //if (PGC__DEBUG_MODE) PGC__SHOW_VEC(vertices) /* WARNING: macro combination expanding */
  PGC__DEBUG_VEC(vertices)
  VertexInducer inducer;
  Graph result;
  inducer.run(diamond, vertices, &result);
  INFO << "RESULT: \n";
  result.show();
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
