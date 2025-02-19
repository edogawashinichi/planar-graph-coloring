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

/// test_1
TEST_START(1)
  BirkhoffDiamondColoringGroup G;
  INFO_OBJ(G)
  bool res = (G.size() == 4 * fact(COLORS.size()));
  BirkhoffDiamond diamond;
  RingColoringResult ring_colorings;
  Colorer colorer;
  colorer.run(diamond, &ring_colorings);
  res = res && (ring_colorings.size() == 732);
  ColoringOrbitResult orbits;
  const size_t orbits_init_length = orbits.size();
  ColoringActor<BirkhoffDiamondVertexSymmetryGroup>::getInstance().run(ring_colorings, G, &orbits);
  const size_t orbits_res_length = orbits.size();
  INFO_2VAR(orbits_init_length, orbits_res_length)
  res = res && (orbits.size() == 15);
  VERBOSE_OBJ(orbits)
TEST_END(1)
/// test_1

PGC__MAIN_START
  //TEST(0)
  TEST(1)
PGC__MAIN_END
