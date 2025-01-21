/// _test_coloring_group.cxx

#include "birkhoff_diamond_coloring_group.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondColoringGroup G;
  INFO_OBJ(G)
  bool res = (G.size() == 4 * fact(COLORS));
  for (size_t i = 0; i < G.size(); ++i) {
    const II& pair = G.get(i);
    auto vertex_permutation = G.constVertexPermutation(pair.first);
    auto color_permutation = G.constColorPermutation(pair.second);
    if (78 == i) {
      INFO_VAR(i)
      INFO_PAIR(pair)
      INFO_OBJ(vertex_permutation)
      INFO_OBJ(color_permutation)
    }/// if
  }/// for
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
