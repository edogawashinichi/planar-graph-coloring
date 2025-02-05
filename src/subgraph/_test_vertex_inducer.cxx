/// _test_vertex_inducer.cxx

#include "vertex_inducer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamond diamond;
  DEBUG_OBJ(diamond)
  const std::vector<size_t> vertices = {0, 1, 2, 3, 4, 5};
  DEBUG << "induce vertices:\n";
  //if (PGC__DEBUG_MODE) PGC__SHOW_VEC(vertices) /* WARNING: macro combination expanding */
  PGC__DEBUG_VEC(std::cout, vertices)
  VertexInducer inducer;
  Graph result;
  inducer.run(diamond, vertices, &result);
  INFO_OBJ(result)
  bool res = true;
TEST_END(0)
/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
