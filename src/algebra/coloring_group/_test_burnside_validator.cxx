/// _test_burnside_validator.cxx

#include "burnside_validator.h"
#include "birkhoff_diamond_coloring_group.h"
#include "birkhoff_diamond_vertex_symmetry_group.h"
#include "../../topology/birkhoff_diamond.h"
#include "../../color/colorer.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondColoringGroup G;
  INFO_OBJ(G)
  bool res = (G.size() == 4 * fact(COLORS.size()));
  BirkhoffDiamond diamond;
  RingColoringResult ring_colorings;
  Colorer::getInstance().run(diamond, &ring_colorings);
  res = res && (ring_colorings.size() == 732);
  const size_t cnt = BurnsideValidator<BirkhoffDiamondVertexSymmetryGroup>::getInstance().run(G, ring_colorings);
  INFO_VAR(cnt)
  res = res && (cnt == 15);
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
