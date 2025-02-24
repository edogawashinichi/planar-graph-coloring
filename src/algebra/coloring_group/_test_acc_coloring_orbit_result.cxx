/// _test_acc_coloring_orbit_result.cxx

#include "acc_coloring_orbit_result.h"
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
  Colorer::getInstance().run(diamond, &ring_colorings);
  const size_t EXP_RING_COLORINGS_SIZE = 732;
  res = res && (ring_colorings.size() == EXP_RING_COLORINGS_SIZE);
  ColoringOrbitResult orbits;
  ColoringActor<BirkhoffDiamondVertexSymmetryGroup>::getInstance().run(ring_colorings, G, &orbits);
  const size_t EXP_ORBITS_SIZE = 15;
  res = res && (orbits.size() == EXP_ORBITS_SIZE);
  ColoringOrbitResult reduced_orbits;
  orbits.removeDuplicate(&reduced_orbits);
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
  res = res && (orbits.getOriginalSizeVector() == original_orbits_size_vec);
  res = res && (orbits.getReducedSizeVector() == reduced_orbits_size_vec);
  const size_t number = sum<size_t>(reduced_orbits_size_vec);
  res = res && (number == EXP_RING_COLORINGS_SIZE);
  /* condition: G, ring_colorings, orbits, reduced_orbits */
  AccColoringOrbitResult acc(reduced_orbits);
  for (size_t index = 0; index < ring_colorings.size(); ++index) {
    const ColoringInfo& info = acc.getConst(index);
    if (123 == index) {
      INFO_OBJ(info)
    }/// if
  }/// for
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
