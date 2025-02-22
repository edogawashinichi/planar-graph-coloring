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
  const size_t EXP_RING_COLORINGS_SIZE = 732;
  res = res && (ring_colorings.size() == EXP_RING_COLORINGS_SIZE);
  ColoringOrbitResult orbits;
  ColoringActor<BirkhoffDiamondVertexSymmetryGroup>::getInstance().run(ring_colorings, G, &orbits);
  INFO_VAR(orbits.size())
  const size_t EXP_ORBITS_SIZE = 15;
  res = res && (orbits.size() == EXP_ORBITS_SIZE);
  INFO_OBJ(orbits)
  ColoringOrbitResult reduced_orbits;
  orbits.removeDuplicate(&reduced_orbits);
  INFO_OBJ(reduced_orbits)
  const VI original_orbits_size_vec(EXP_ORBITS_SIZE, 96);
  const VI reduced_orbits_size_vec = {
    12, /* 0 */
    96, /* 1 */
    48, /* 2 */
    48, /* 3 */
    48, /* 4 */
    48, /* 5 */
    96, /* 6 */
    96, /* 7 */
    48, /* 8 */
    24, /* 9 */
    48, /* 10 */
    24, /* 11 */
    48, /* 12 */
    24, /* 13 */
    24, /* 14 */
  };
  //DEBUG_VEC(orbits.getOriginalSizeVector())
  //DEBUG_VEC(orbits.getReducedSizeVector())
  res = res && (orbits.getOriginalSizeVector() == original_orbits_size_vec);
  res = res && (orbits.getReducedSizeVector() == reduced_orbits_size_vec);
  const size_t number = sum<size_t>(reduced_orbits_size_vec);
  //DEBUG_VAR(number)
  res = res && (number == EXP_RING_COLORINGS_SIZE);
TEST_END(1)
/// test_1

PGC__MAIN_START
  //TEST(0)
  TEST(1)
PGC__MAIN_END
