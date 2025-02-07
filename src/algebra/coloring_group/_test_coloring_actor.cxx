/// _test_coloring_actor.cxx

#include "coloring_actor.h"
#include "birkhoff_diamond_coloring_group.h"
#include "../../color/colorer.h"
#include "../../topology/birkhoff_diamond.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondColoringGroup G;
  INFO_OBJ(G)
  bool res = (G.size() == 4 * fact(COLORS.size()));
  BirkhoffDiamond diamond;
  RingColoringResult ring_colorings;
  Colorer colorer;
  colorer.run(diamond, &ring_colorings);
  res = res && (ring_colorings.size() == 732);
  VSI orbits;
  ColoringActor<BirkhoffDiamondVertexSymmetryGroup>::getInstance().run(ring_colorings, G, &orbits);
  res = res && (orbits.size() == 15);
  for (size_t i = 0; i < orbits.size(); ++i) {
    INFO << i << "th size: " << orbits[i].size() << "\n";
    INFO_SET(orbits[i])
  }
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
